-- Output directory (e.g. Debug-windows-x86_64)
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "EnclosureParser"
    kind "SharedLib"
    language "C++"

    targetdir ("../bin/"     .. outputdir .. "/%{prj.name}")
    objdir    ("../bin-int/" .. outputdir .. "/%{prj.name}")

    -- Precompiled headers
    pchheader "%{prj.name}_pch.h"
    pchsource ("src/%{prj.name}_pch.cpp")

    files { "src/**.h", "src/**.cpp" }

    includedirs { "src/" }

    -- Copy lib on build
    postbuildcommands {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Enclosure")
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines { "ENC_PLATFORM_WINDOWS", "ENC_BUILD_DLL" }
    
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
