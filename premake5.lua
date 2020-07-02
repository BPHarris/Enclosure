workspace "Enclosure"
    architecture "x64"
    configurations { "Debug", "Release" }


-- Output directory (e.g. Debug-windows-x86_64)
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


include "Lexer"
include "Parser"


project "Enclosure"
    location "Enclosure"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/"     .. outputdir .. "/%{prj.name}")
    objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- Precompiled headers
    pchheader "%{prj.name}_pch.h"
    pchsource ("%{prj.name}/src/%{prj.name}_pch.cpp")

    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

    includedirs { 
        "Lexer/src",
        "Parser/src"
    }

    links { "Lexer", "Parser" }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines { "ENC_PLATFORM_WINDOWS" }
    
    filter "system:linux"
        systemversion "latest"
        defines { "ENC_PLATFORM_LINUX" }

    filter "system:macosx"
        systemversion "latest"
        defines { "ENC_PLATFORM_MACOSX" }

    filter "configurations:Debug"
        defines { "ENC_DEBUG", "ENC_ENABLE_ASSERTS" }
        symbols "On"

    filter "configurations:Release"
        defines { "ENC_RELEASE" }
        optimize "On"
