#include <windows.h>
#include <iostream>

bool IsChineseOrFullwidth(wchar_t ch)
{
    return (ch >= 0x4E00 && ch <= 0x9FFF) ||   // CJK Unified Ideographs
           (ch >= 0x3000 && ch <= 0x303F) ||   // CJK Symbols and Punctuation
           (ch >= 0xFF00 && ch <= 0xFFEF) ||   // Fullwidth Forms
           (ch >= 0x3100 && ch <= 0x312F);     // Bopomofo
}

void DetectChineseChar(const char* input)
{
    // Convert multibyte string (ANSI or UTF-8) to UTF-16 wide string
    int requiredSize = MultiByteToWideChar(CP_ACP, 0, input, -1, NULL, 0);
    if (requiredSize == 0)
    {
        std::cerr << "Failed to convert input string." << std::endl;
        return;
    }

    // Allocate buffer for wide string
    wchar_t* utf16Str = new wchar_t[requiredSize];
    if (!utf16Str)
    {
        std::cerr << "Memory allocation failed." << std::endl;
        return;
    }

    MultiByteToWideChar(CP_ACP, 0, input, -1, utf16Str, requiredSize);

    // Scan for Chinese-related characters
    bool found = false;
    for (int i = 0; i < requiredSize - 1; ++i)
    {
        if (IsChineseOrFullwidth(utf16Str[i]))
        {
            found = true;
            break;
        }
    }

    // Output result
    if (found)
    {
        std::cout << "Chinese or related characters found." << std::endl;
    }
    else
    {
        std::cout << "No Chinese characters found." << std::endl;
    }

    delete[] utf16Str;
}

int main()
{
    const char* input = "Hello, 世界！注音：ㄅㄆㄇ，ＦＵＬＬ！";  // Try with Chinese, Bopomofo, or fullwidth characters
    DetectChineseChar(input);
    return 0;
}
