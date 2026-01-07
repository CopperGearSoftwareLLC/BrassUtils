include(FetchContent)

# --- Fetch Boost ---
set(BOOST_INCLUDE_LIBRARIES describe dynamic_bitset multi_array static_string)
set(BOOST_ENABLE_CMAKE ON)
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.90.0
)
FetchContent_MakeAvailable(Boost)