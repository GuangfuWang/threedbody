
#ifndef INC_3DBODY_3DBODY_DEF_H_
#define INC_3DBODY_3DBODY_DEF_H_

#include <memory>
#include <filesystem>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <string_view>
#include <array>
#include <functional>

namespace gf {

#ifdef GF_WIN
#ifndef GF_IMPORT
#define GF_IMPORT _declspec(dllimport)
#endif

#ifndef GF_EXPORT
#define GF_EXPORT _declspec(dllexport)
#endif

#ifndef GF_API

#endif

#elif defined GF_LINUX

#ifndef GF_IMPORT
#define GF_IMPORT
#endif
#ifndef GF_EXPORT
#define GF_EXPORT
#endif
#ifndef GF_API
#define GF_API
#endif

#endif

#ifndef GF_DEPRECATED
#define GF_DEPRECATED [[deprecated]]
#endif

#ifndef GF_DEPRECATED_MSG
#define GF_DEPRECATED_MSG(msg) [[deprecated(msg)]]
#endif

#ifndef ALIGNED16
#define ALIGNED16 __attribute__((aligned(16)))
#endif

#ifndef ALIGNED32
#define ALIGNED32 __attribute__((aligned(32)))
#endif

#ifndef ALIGNED64
#define ALIGNED64 __attribute__((aligned(64)))
#endif

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T>
using Ref_Unique = std::unique_ptr<T>;

namespace fs = std::filesystem;

using string = std::string;

template<typename T>
using vector = std::vector<T>;

template<typename T>
using list = std::list<T>;

using string_view = std::string_view;

template<typename K, typename V>
using unorder_map = std::unordered_map<K, V>;

template<typename K, typename V>
using map = std::map<K, V>;

template<typename T, unsigned int N>
using array = std::array<T, N>;

using FileLoaderFunc = std::function<void(const std::string &)>;

using RenderIndexType = unsigned int;
}

#endif //INC_3DBODY_3DBODY_DEF_H_