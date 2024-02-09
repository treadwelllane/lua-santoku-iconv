local test = require("santoku.test")
local iconv = require("santoku.iconv")

local tbl = require("santoku.table")
local teq = tbl.equals

local err = require("santoku.error")
local assert = err.assert

os.setlocale("en_US.UTF-8", "all")

test("basic", function ()
  assert(teq(
    { "aaaaaeeeeeiiiiiooooouuuuuuuuuAAAAAEEEEEIIIIIOOOOOUUUUUUUUU" },
    { iconv("aāáǎàeēéěèiīíǐìoōóǒòuūúǔùǖǘǚǜAĀÁǍÀEĒÉĚÈIĪÍǏÌOŌÓǑÒUŪÚǓÙǕǗǙǛ", "utf-8", "ascii", "translit") }))
end)

test("ligatures 1", function ()
  assert(teq(
    { "Hzae" },
    { iconv("㎐æ", "utf-8", "ascii", "translit") }))
end)

test("ligatures 2", function ()
  assert(teq(
    { "VIIIVIIIVIIIVIIIVIIIVIIIVIIIVIIIVIIIVIII" },
    { iconv("ⅧⅧⅧⅧⅧⅧⅧⅧⅧⅧ", "utf-8", "ascii", "translit") }))
end)

test("failing case", function ()
  assert(teq(
    { "a young woman's journey in which a ghostwriter investigates an arsonist while avoiding marriage" }, -- luacheck: ignore
    { iconv("a young woman's journey in which a ghostwriter investigates an arsonist while avoiding marriage", "utf-8", "ascii", "translit") })) -- luacheck: ignore
end)
