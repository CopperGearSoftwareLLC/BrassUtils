#pragma once
#include <bit>
#include <cstdint>
#include <cstring>
#include <glm/glm.hpp>
#include <glm/gtc/bitfield.hpp>
#include <glm/gtc/packing.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <span>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>
#include <boost/static_string.hpp>
struct ByteError : std::runtime_error
{
	ByteError() : std::runtime_error("ByteError") {}
	using std::runtime_error::runtime_error;
};
// Use std::bit_cast if available (C++20)
#if defined(__cpp_lib_bit_cast) && __cpp_lib_bit_cast >= 201806L
#include <bit>
template <typename To, typename From>
constexpr To bit_cast(const From& src) noexcept {
    return std::bit_cast<To>(src);
}
#else
// Fallback for older compilers
template <typename To, typename From>
To bit_cast(const From& src) noexcept {
    static_assert(sizeof(To) == sizeof(From), "bit_cast requires source and destination to be the same size");
    static_assert(std::is_trivially_copyable<From>::value, "bit_cast requires source to be trivially copyable");
    static_assert(std::is_trivially_copyable<To>::value, "bit_cast requires destination to be trivially copyable");
    To dst;
    std::memcpy(&dst, &src, sizeof(To));
    return dst;
}
#endif