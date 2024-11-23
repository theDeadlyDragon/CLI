project "core"
    kind "StaticLib"  -- or "SharedLib" if it's a dynamic library
    language "C++"
    targetdir ("../build/%{cfg.buildcfg}/%{prj.name}")
    objdir ("../build/intermediate/%{cfg.buildcfg}/%{prj.name}")

    files { "**.h", "**.cpp" }

    filter "configurations:Debug"
        symbols "On"
    
    filter "configurations:Release"
        optimize "On"