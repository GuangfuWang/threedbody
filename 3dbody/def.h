
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
#include <glm/glm.hpp>

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

#ifndef GF_PI
#define GF_PI 3.14159265358979323846f
#endif

#ifndef GF_ONE_PI
#define GF_ONE_PI 0.318309886183790671538f
#endif

#ifndef COLOR_MAX
#define COLOR_MAX 255
#endif

#ifndef COLOR_MIN
#define COLOR_MIN 0
#endif

#ifndef COLOR_IN_BYTE
#define COLOR_IN_BYTE(byteColor) ((unsigned char)(byteColor*255))
#endif

#ifndef MALLOC_BY_TYPE
#define MALLOC_BY_TYPE(size,type) ((type*)malloc((size)*sizeof(type)))
#endif

#ifndef Vec
    using Vec = glm::vec3;
#endif

#ifndef Vec2i
    using Vec2i = glm::vec<2, int>;
#endif

#ifndef Vec2f
    using Vec2f = glm::vec2;
#endif

#ifndef Quaternion
    using Quaternion = glm::quat;
#endif

#ifndef Point
    typedef struct Point {
        float x, y;
    } Point_;
#endif

#ifndef Pixel
    typedef struct Pixel {
        union {
            unsigned int u;
            unsigned int x;
        };
        union {
            unsigned int v;
            unsigned int y;
        };
    } Pixel_;
#endif

#ifndef Mat4
    using Mat4 = glm::mat4;
#endif

#define UnUsed_Func [[maybe_unused]]

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
    using unordered_map = std::unordered_map<K, V>;

    template<typename K, typename V>
    using map = std::map<K, V>;

    template<typename T, unsigned int N>
    using array = std::array<T, N>;

    using FileLoaderFunc = std::function<void(const std::string &)>;

    using RenderIndexType = unsigned int;

    typedef RenderIndexType* IndexBuffer;

    template<typename T>
    using reference = std::reference_wrapper<T>;

    template<typename T, typename ... Args>
    constexpr Ref<T> createRef(Args &&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<typename T, typename ... Args>
    constexpr Ref_Unique<T> createUniqueRef(Args &&... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
}

#endif //INC_3DBODY_3DBODY_DEF_H_
