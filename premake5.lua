workspace "CLI"
    configurations { "Debug", "Release" }
    
    -- require "cmake"

    location "build"

    -- Include the sub-projects
    include "core"
    include "app"
