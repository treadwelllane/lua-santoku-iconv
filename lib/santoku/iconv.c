// TODO: Allow incremental conversion and preservation of a iconv file
// descriptor

#include "lua.h"
#include "lauxlib.h"

#include "errno.h"
#include "string.h"
#include "stdlib.h"
#include "iconv.h"

#define debug(...) fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");

// TODO: Duplicated across santoku-python, santoku-web, iconv, should be split
// into separate library
static void tk_lua_callmod (lua_State *L, int nargs, int nret, const char *smod, const char *sfn)
{
  lua_getglobal(L, "require"); // arg req
  lua_pushstring(L, smod); // arg req smod
  lua_call(L, 1, 1); // arg mod
  lua_pushstring(L, sfn); // args mod sfn
  lua_gettable(L, -2); // args mod fn
  lua_remove(L, -2); // args fn
  lua_insert(L, - nargs - 1); // fn args
  lua_call(L, nargs, nret); // results
}

int tk_iconv (lua_State *L)
{
  int n = lua_gettop(L);

  if (n < 3 || n > 4) {

    luaL_error(L, "iconv: expected 3 or 4 string arguments");
    return 0;

  } else if (n == 4) {

    luaL_checkstring(L, -4);
    luaL_checkstring(L, -3);
    luaL_checkstring(L, -2);
    luaL_checkstring(L, -1);

    lua_pushstring(L, "//"); // str from to flag slash
    lua_insert(L, -2); // str from to slash flag
    lua_concat(L, 3); // str from to

  } else if (n == 3) {

    luaL_checkstring(L, -3);
    luaL_checkstring(L, -2);
    luaL_checkstring(L, -1); // str from to

  }

  size_t inlen;
  const char *innext = lua_tolstring(L, -3, &inlen);
  size_t inleft = inlen;

  lua_pushvalue(L, -2); // str from to from
  tk_lua_callmod(L, 1, 1, "string", "upper"); // str from to from

  lua_pushvalue(L, -2); // str from to from to
  tk_lua_callmod(L, 1, 1, "string", "upper"); // str from to from to

  lua_remove(L, -3);
  lua_remove(L, -3); // str from to

  const char *from = lua_tostring(L, -2);
  const char *to = lua_tostring(L, -1);

  char *outstart = NULL;
  char *outnext = NULL;
  size_t outsize = inlen;
  size_t outleft = outsize;

  iconv_t ic = iconv_open(to, from);

  if (ic == ((iconv_t) -1))
    goto err;

  outstart = malloc(outsize);
  outnext = outstart;

  if (outstart == NULL)
    goto err_mem;

  while (1)
  {
    int rc = iconv(ic, (char ** restrict) &innext, &inleft, &outnext, &outleft);

    if (rc >= 0)
    {
      lua_pushboolean(L, 1);
      lua_pushlstring(L, outstart, outsize - outleft);
      free(outstart);

      rc = iconv_close(ic);

      if (rc == -1)
        goto err;

      return 2;
    }

    if (rc == -1 && errno != E2BIG)
      goto err;

    if (rc == -1) {
      size_t len = outsize - outleft;
      outsize = outsize * 1.5;
      char *outstart0 = realloc(outstart, outsize);
      if (outstart0 == NULL)
        goto err_mem;
      outleft = outsize - len;
      outstart = outstart0;
      outnext = outstart + len;
    }
  }

err_mem:
  free(outstart);
  lua_pushboolean(L, 0);
  lua_pushstring(L, "malloc failed");
  return 2;

err:
  free(outstart);
  int cd = errno;
  const char *err = strerror(cd);
  lua_pushboolean(L, 0);
  lua_pushstring(L, err);
  lua_pushinteger(L, cd);
  return 3;
}

int luaopen_santoku_iconv (lua_State *L)
{
  lua_pushcfunction(L, tk_iconv);
  return 1;
}
