cmake_minimum_required (VERSION 3.24...3.30)

project (hello-raylib VERSION 1.0.0 LANGUAGES C CXX)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set (CMAKE_CXX_STANDARD 20)

include (FetchContent)

find_package (raylib 5.5 QUIET)

if (raylib_FOUND)
    message (STATUS "Raylib found: ${raylib_DIR}")
else ()
    message (STATUS "Raylib not found, fetching...")
    set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE INTERNAL "") # prevent installing to system directories
    set (RAYLIB_VERSION 5.5)
    FetchContent_Declare (
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
        FIND_PACKAGE_ARGS
    )
    FetchContent_MakeAvailable (raylib)
endif ()

add_executable (${PROJECT_NAME})

add_subdirectory (src)

# set_target_properties (${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
# set_property (TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)

target_link_libraries (${PROJECT_NAME} raylib)

if (APPLE)
    target_link_libraries (${PROJECT_NAME} "-framework IOKit")
    target_link_libraries (${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries (${PROJECT_NAME} "-framework OpenGL")
endif ()
