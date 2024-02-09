local env = {

  name = "santoku-iconv",
  version = "0.0.7-1",
  variable_prefix = "TK_ICONV",
  license = "MIT",
  public = true,

  dependencies = {
    "lua >= 5.1",
  },

  test = {
    dependencies = {
      "santoku >= 0.0.191-1",
      "luacov >= 0.15.0-1",
    }
  },

}

env.homepage = "https://github.com/treadwelllane/lua-" .. env.name
env.tarball = env.name .. "-" .. env.version .. ".tar.gz"
env.download = env.homepage .. "/releases/download/" .. env.version .. "/" .. env.tarball

return {
  type = "lib",
  env = env,
}

