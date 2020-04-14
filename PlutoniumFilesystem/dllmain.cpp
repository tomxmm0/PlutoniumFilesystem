// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Filesystem.hpp"

extern "C"
{
    __declspec(dllexport) void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
    {
        auto module_ptr = chaiscript::ModulePtr(new chaiscript::Module());

        module_ptr->add(chaiscript::user_type<Filesystem>(), "Filesystem");
        module_ptr->add(chaiscript::constructor<Filesystem(const std::string&, const std::string&)>(), "Filesystem");
        module_ptr->add(chaiscript::fun(&Filesystem::Read), "Read");
        module_ptr->add(chaiscript::fun(&Filesystem::Write), "Write");
        module_ptr->add(chaiscript::fun(&Filesystem::Close), "Close");

        chai->add(module_ptr);
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

