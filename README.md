# Santoku Iconv

Character encoding conversion for Lua using the POSIX iconv library. Part of the Santoku utility library ecosystem.

## Module Reference

### `santoku.iconv`

| Function | Arguments | Returns | Description |
|----------|-----------|---------|-------------|
| `iconv` | `input, from_enc, to_enc, [flags]` | `string` | Converts text between character encodings |

**Parameters:**
- `input` (string): Text to convert
- `from_enc` (string): Source encoding (case-insensitive)
- `to_enc` (string): Target encoding (case-insensitive)
- `flags` (string, optional): Conversion flags ("translit" or "ignore")

**Returns:**
- Converted string in target encoding

**Errors:**
- Raises structured error on invalid encoding or conversion failure

## Common Encodings

| Encoding | Common Aliases | Description |
|----------|---------------|-------------|
| UTF-8 | `utf-8`, `UTF-8`, `utf8` | Unicode (8-bit) |
| ASCII | `ascii`, `ASCII`, `us-ascii` | 7-bit ASCII |
| Latin-1 | `iso-8859-1`, `latin1`, `ISO-8859-1` | Western European |
| Windows-1252 | `cp1252`, `windows-1252` | Windows Western |
| UTF-16 | `utf-16`, `UTF-16` | Unicode (16-bit) |
| UTF-32 | `utf-32`, `UTF-32` | Unicode (32-bit) |
| GBK | `gbk`, `GBK`, `CP936` | Simplified Chinese |
| Shift-JIS | `shift_jis`, `SJIS`, `CP932` | Japanese |
| EUC-KR | `euc-kr`, `EUCKR`, `CP949` | Korean |

The exact list of supported encodings depends on your system's iconv implementation. Check with `iconv -l` command.

## Conversion Flags

| Flag | Syntax | Description |
|------|--------|-------------|
| `translit` | `"translit"` | Transliterates unconvertible characters to similar ASCII |
| `ignore` | `"ignore"` | Skips unconvertible characters (not yet implemented) |
| (none) | `nil` or omitted | Strict conversion, errors on unconvertible characters |

## License

MIT License

Copyright 2025 Matthew Brooks

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
