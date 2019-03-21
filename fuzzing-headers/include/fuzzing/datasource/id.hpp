#ifndef FUZZING_DATASOURCE_ID_HPP
#define FUZZING_DATASOURCE_ID_HPP

#include <stdio.h>
#include <stdint.h>
#include <utility>
#include <map>

namespace fuzzing {
namespace datasource  {

/* From: https://gist.github.com/underscorediscovery/81308642d0325fd386237cfa3b44785c */
inline uint64_t hash_64_fnv1a(const void* key, const uint64_t len) {

    const char* data = (char*)key;
    uint64_t hash = 0xcbf29ce484222325;
    uint64_t prime = 0x100000001b3;

    for(uint64_t i = 0; i < len; ++i) {
        uint8_t value = data[i];
        hash = hash ^ value;
        hash *= prime;
    }

    return hash;

} //hash_64_fnv1a

// FNV1a c++11 constexpr compile time hash functions, 32 and 64 bit
// str should be a null terminated string literal, value should be left out 
// e.g hash_32_fnv1a_const("example")
// code license: public domain or equivalent
// post: https://notes.underscorediscovery.com/constexpr-fnv1a/

constexpr uint32_t val_32_const = 0x811c9dc5;
constexpr uint32_t prime_32_const = 0x1000193;
constexpr uint64_t val_64_const = 0xcbf29ce484222325;
constexpr uint64_t prime_64_const = 0x100000001b3;


inline constexpr uint64_t ID(const char* const str, const uint64_t value = val_64_const) noexcept {
    auto ret = (str[0] == '\0') ? value : ID(&str[1], (value ^ uint64_t(str[0])) * prime_64_const);
    return ret;
}

inline constexpr std::pair<const char*, uint64_t> IDPair(const char* const str, const uint64_t value = val_64_const) noexcept {
    return {str, ID(str, value)};
}

using IDMap = std::map<const char*, uint64_t>;

} /* namespace datasource */
} /* namespace fuzzing */

#endif
