# CMakeList.txt : CMake project for newc, include source and define
# project specific logic here.
#

# Add source to this project's executable.



add_executable (newc "newc.cpp" "newc.h")

target_compile_definitions(glew_s PUBLIC GLEW_STATIC)


target_link_libraries(newc PRIVATE glfw glad glew_s)

# On Windows: link OpenGL32
if (WIN32)
    target_link_libraries(newc PRIVATE opengl32)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET newc PROPERTY CXX_STANDARD 20)
endif()

