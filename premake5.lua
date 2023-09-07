workspace "dsc"
    configurations { "Debug", "Release" }

project "dsc-lib"
    kind "SharedLib"
    language "C"
    targetdir "bin/%{cfg.buildcfg}"

    files { "./src/ds/**.h", "./src/ds/**.c",
            "./src/algo/**.h", "./src/algo/**.c" }

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

    files { "./src/tests/**.h", "./src/tests/**.c" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
