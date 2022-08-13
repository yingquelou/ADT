#include <Windows.h>
DWORD WINAPI thProc(LPVOID lpParam);
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine,
                     int nCmdShow)
{
    TCHAR *str = "1234567890";
    HANDLE Hth = CreateThread(NULL, 0, thProc, str, 0, NULL);
    WaitForSingleObject(Hth, INFINITE);
    return 0;
}
DWORD WINAPI thProc(LPVOID lpParam)
{
    AllocConsole();
    HANDLE stdout = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD realized;
    WriteConsole(stdout, lpParam, strlen(lpParam), &realized, NULL);

    WriteConsole(stdout, "\n", 1, NULL, NULL);
    char *num = "0123456789";
    while (realized % 10 || realized / 10)
    {
        WriteConsole(stdout, num + realized % 10, 1, NULL, NULL);
        realized /= 10;
    }
    WriteConsole(stdout, "\n", 1, NULL, NULL);
}