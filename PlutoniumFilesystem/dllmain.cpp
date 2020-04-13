// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Filesystem.hpp"

namespace ChaiFunctions
{
    Filesystem OpenFile(const std::string& file, const std::string& mode)
    {
        return Filesystem(file, mode);
    }

    std::string ReadFile(Filesystem* fs)
    {
        return fs->Read();
    }

    void WriteFile(Filesystem* fs, const std::string& text)
    {
        fs->Write(text);
    }

    void CloseFile(Filesystem* fs)
    {
        fs->Close();
    }
}

extern "C"
{
    __declspec(dllexport) void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
    {
        chai->add(chaiscript::fun(ChaiFunctions::OpenFile), "OpenFile");
        chai->add(chaiscript::fun(ChaiFunctions::ReadFile), "ReadFile");
        chai->add(chaiscript::fun(ChaiFunctions::WriteFile), "WriteFile");
        chai->add(chaiscript::fun(ChaiFunctions::CloseFile), "CloseFile");
    }

    __declspec(dllexport) void on_script_loaded(const char* script, chaiscript::ChaiScript* chai)
    {
    }

    __declspec(dllexport) void on_script_unloaded(const char* script, chaiscript::ChaiScript* chai)
    {
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

