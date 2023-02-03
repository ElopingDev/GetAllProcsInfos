#include <Windows.h>
#include <iostream>
#include <tchar.h>

int yesno = 0;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    TCHAR windowTitle[255];
    GetWindowText(hwnd, windowTitle, sizeof(windowTitle) / sizeof(TCHAR));

    
#ifdef UNICODE
    std::wcout << L"Window HWND: " << hwnd << L" Title: " << windowTitle << std::endl;
#else
    std::cout << "Window HWND: " << hwnd << " Title: " << windowTitle << std::endl;
#endif

    return TRUE;
}

int main() {
    std::cout << "Made by Eloping" << std::endl;
    std::cout << "Send 1 to continue" << std::endl;
    std::cin >> yesno;

    if (yesno == 1)
        goto code;
    else {
        goto nop;
    }
code:
    EnumWindows(EnumWindowsProc, 0);
nop:
    std::cin.ignore();
    std::cin.get();
    return 0;
}
