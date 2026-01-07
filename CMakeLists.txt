cmake_minimum_required(VERSION 3.14)
project(BrassUtils LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Fetch GLM ---
include(cmake/GLM.cmake)  # This file should use FetchContent to get GLM

# --- Collect all .cpp files recursively ---
file(GLOB_RECURSE BRASS_UTILS_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/cpp/src/*.cpp"
)

# --- Create the library ---
add_library(BrassUtilsCpp STATIC ${BRASS_UTILS_SOURCES})

# --- Include directories ---
target_include_directories(BrassUtilsCpp
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cpp/include>
        $<INSTALL_INTERFACE:include>
)

# --- Link GLM (header-only) ---
target_link_libraries(BrassUtilsCpp PRIVATE glm::glm)


