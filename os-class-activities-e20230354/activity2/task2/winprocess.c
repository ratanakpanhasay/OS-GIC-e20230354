
/* winprocess.c — Process creation on Windows */
#include <stdio.h>
#include <windows.h>

int main(void) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent process (PID: %lu) - creating child...\n",
           GetCurrentProcessId());

    const char *appPath =
        "C:\\Program Files\\WindowsApps\\Microsoft.Paint_11.2605.81.0_x64__8wekyb3d8bbwe\\PaintApp\\mspaint.exe";

    if (!CreateProcessA(
            appPath,
            NULL,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi)) {

        fprintf(stderr, "CreateProcess failed (error %lu).\n",
                GetLastError());
        return 1;
    }

    printf("Child process created!\n");
    printf("Child PID: %lu\n", pi.dwProcessId);
    printf("Child Thread ID: %lu\n", pi.dwThreadId);

    printf("Parent: waiting for Paint to close...\n");
    printf("Open Task Manager to observe the processes.\n");

    WaitForSingleObject(pi.hProcess, INFINITE);

    printf("Parent: child has exited. Cleaning up.\n");

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
