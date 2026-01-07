cmake_minimum_required(VERSION 3.14)
project(BrassUtils LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Fetch GLM ---
include(cmake/GLM.cmake)  # This file should use FetchContent to get GLM
include(cmake/Boost.cmake)  # This file should use FetchContent to get GLM

# --- Collect all .cpp files recursively ---
file(GLOB_RECURSE BRASS_UTILS_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/cpp/src/*.cpp"
)

# --- Create the library ---
add_library(BrassUtils STATIC ${BRASS_UTILS_SOURCES})

# --- Include directories ---
target_include_directories(BrassUtils
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/cpp/src
        $<BUILD_INTERFACE:${boost_SOURCE_DIR}>
        $<BUILD_INTERFACE:${glm_SOURCE_DIR}>  # optional if needed
)
message(STATUS ${boost_SOURCE_DIR})

# --- Link GLM (header-only) ---
target_link_libraries(BrassUtils
    PRIVATE 
        glm::glm
        Boost::dynamic_bitset
        Boost::multi_array
        Boost::static_string)

add_library(BrassUtils::BrassUtils ALIAS BrassUtils)
