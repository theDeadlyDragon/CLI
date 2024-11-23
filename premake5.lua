workspace "CLI"
    configurations { "Debug", "Release" }
    
    location "build"

    -- Include the sub-projects
    include "core"
    include "app"
