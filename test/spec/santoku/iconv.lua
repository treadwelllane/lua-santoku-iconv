local assert = require("luassert")
local test = require("santoku.test")
local iconv = require("santoku.iconv")

os.setlocale("en_US.UTF-8", "all")

test("iconv", function ()

  test("basic", function ()
    assert.same(
      { true, "aaaaaeeeeeiiiiiooooouuuuuuuuuAAAAAEEEEEIIIIIOOOOOUUUUUUUUU" },
      { iconv("aāáǎàeēéěèiīíǐìoōóǒòuūúǔùǖǘǚǜAĀÁǍÀEĒÉĚÈIĪÍǏÌOŌÓǑÒUŪÚǓÙǕǗǙǛ", "utf-8", "ascii", "translit") })
  end)

  test("ligatures 1", function ()
    assert.same(
      { true, "Hzae" },
      { iconv("㎐æ", "utf-8", "ascii", "translit") })
  end)

  test("ligatures 2", function ()
    assert.same(
      { true, "VIIIVIIIVIIIVIIIVIIIVIIIVIIIVIIIVIIIVIII" },
      { iconv("ⅧⅧⅧⅧⅧⅧⅧⅧⅧⅧ", "utf-8", "ascii", "translit") })
  end)

  test("failing case", function ()
    assert.same(
        { true, "a young woman's journey in which a ghostwriter investigates an arsonist while avoiding marriage" }, -- luacheck: ignore
        { iconv("a young woman's journey in which a ghostwriter investigates an arsonist while avoiding marriage", "utf-8", "ascii", "translit") }) -- luacheck: ignore
  end)

end)
