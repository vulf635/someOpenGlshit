# CMakeList.txt : CMake project for newc, include source and define
# project specific logic here.
#

# Add source to this project's executable.



add_executable (newc "main.cpp" "main.h"
        engine/Objects/Texture2d.cpp
        engine/Objects/Texture2d.h
        engine/Objects/Sprite.cpp
        engine/Objects/Sprite.h
        engine/Objects/Shader.cpp
        engine/Objects/Shader.h
        engine/Objects/ResourceManager.cpp
        engine/Objects/ResourceManager.h )


target_include_directories(newc PRIVATE ${stb_SOURCE_DIR})
target_link_libraries(newc PRIVATE glfw glad glm)

# On Windows: link OpenGL32
if (WIN32)
    target_link_libraries(newc PRIVATE opengl32)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET newc PROPERTY CXX_STANDARD 20)
endif()

