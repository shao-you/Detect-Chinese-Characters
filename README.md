# 🔍 Detect Chinese, Fullwidth, and Bopomofo Characters in C++

This program demonstrates how to detect whether a given multibyte `char*` string (e.g., ANSI or UTF-8 encoded) contains **Chinese characters**, **fullwidth symbols**, or **Bopomofo (注音)** using Windows API.

---

## 📌 Overview

The core logic includes two main functions:

- `IsChineseOrFullwidth(wchar_t ch)` – checks if a single wide character falls into specific Unicode ranges
- `DetectChineseChar(const char* input)` – converts a multibyte string to UTF-16 and scans for characters matching the above condition

---

## 🔧 Unicode Ranges Checked

The following Unicode ranges are used to determine whether a character is related to Chinese, fullwidth forms, or Bopomofo:

| Unicode Range      | Description                        |
|--------------------|------------------------------------|
| `0x4E00 ~ 0x9FFF`  | CJK Unified Ideographs (Chinese)   |
| `0x3000 ~ 0x303F`  | CJK Symbols and Punctuation        |
| `0xFF00 ~ 0xFFEF`  | Fullwidth ASCII, Symbols           |
| `0x3100 ~ 0x312F`  | Bopomofo (注音符號)                 |

