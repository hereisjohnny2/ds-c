workspace "dsc"
    configurations { "Debug", "Release" }

project "dsc-lib"
    kind "SharedLib"
    language "C"
    targetdir "bin/%{cfg.buildcfg}"
    
    files { "src/**.c", "include/**.h"  }

    includedirs { "include" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "dsc-tests"
    kind "ConsoleApp"
    language "C"
    targetdir "bin/%{cfg.buildcfg}"

    links { "dsc-lib" }
    includedirs { "include" }

    files { "tests/**.h", "tests/**.c" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
