cmake_minimum_required(VERSION 3.10)

project(homework4_exe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(APPLE)
   set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk")
   set(CMAKE_C_COMPILER "/Library/Developer/CommandLineTools/usr/bin/gcc")
   set(CMAKE_CXX_COMPILER "/Library/Developer/CommandLineTools/usr/bin/g++")

   find_package(glfw3 REQUIRED)
   find_package(GLEW REQUIRED)
endif()

if(WIN32)
   set(GLEW_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies/glew-2.1.0/include")
   set(GLFW_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies/glfw-3.3.9.bin.WIN64/include")

   # Set paths to GLEW and GLFW libraries
   set(GLEW_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies/glew-2.1.0/lib/Release/x64/glew32.lib")
   set(GLFW_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies/glfw-3.3.9.bin.WIN64/lib-vc2022/glfw3.lib")

   # Include directories
   include_directories(${GLEW_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})

   # Link directories
   link_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies/glew-2.1.0/lib/Release/x64")
   link_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies/glfw-3.3.9.bin.WIN64/lib-vc2022")
endif()

if(UNIX AND NOT APPLE)
   find_package(glfw3 REQUIRED)
   find_package(GLEW REQUIRED)
   find_package(OpenGL REQUIRED)

   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


# If you want, you can use ImageMagick on Linux to output your
# image to a file.

#   find_package(ImageMagick COMPONENTS Magick++)
#   if (NOT ImageMagick_FOUND)
#      message(FATAL_ERROR "ImageMagick not found")
#   endif()
#   include_directories(${ImageMagick_INCLUDE_DIRS})

endif()

file(GLOB_RECURSE
     SOURCES
     *.cpp)

add_executable(homework4_exe ${SOURCES})


if (APPLE)
   target_link_libraries(homework4_exe PRIVATE glfw GLEW::GLEW)
   target_link_libraries(homework4_exe PRIVATE "-framework OpenGL")   
endif()

if (WIN32)
   target_link_libraries(homework4_exe PRIVATE ${GLEW_LIBRARY} ${GLFW_LIBRARY})
   target_link_libraries(homework4_exe PRIVATE glew32 glfw3 opengl32)
endif()

if (UNIX AND NOT APPLE)
#    target_link_libraries(homework4_exe PRIVATE glfw GLEW::GLEW ${OPENGL_LIBRARIES} ${ImageMagick_LIBRARIES})
    target_link_libraries(homework4_exe PRIVATE glfw GLEW::GLEW ${OPENGL_LIBRARIES})
endif()
