project "app"
    kind "ConsoleApp"
    language "C++"
    targetdir ("../build/%{cfg.buildcfg}/%{prj.name}")
    objdir ("../build/intermediate/%{cfg.buildcfg}/%{prj.name}")

    files { "**.cpp" }

    -- Include directory for core headers
    includedirs { "../core" }

    -- Link against the core library
    links { "core" }

    -- Ensure core is built before app
    dependson { "core" }

    filter "configurations:Debug"
        symbols "On"
    
    filter "configurations:Release"
        optimize "On"
