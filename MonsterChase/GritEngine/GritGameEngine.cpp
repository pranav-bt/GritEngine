#include "GritGameEngine.h"
int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow)
{
    // IMPORTANT: first we need to initialize GLib

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF);
    _CrtMemCheckpoint(&gMemState);
    atexit([]() { _CrtMemDumpAllObjectsSince(&gMemState); });
    bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "GLibTest", -1, 800, 600, true);
    if (bSuccess)
    {
        // IMPORTANT Maje sure game is called here.
        Game();

        // IMPORTANT:  Tell GLib to shutdown, releasing resources.
        GLib::Shutdown();
    }
}