#pragma once
#include <glm/glm.hpp>

class ray {
public:
    ray() {}

    ray(const glm::vec3 origin, const glm::vec3& direction) : orig(origin), dir(direction) {}

    auto origin() -> glm::vec3 const { return orig; }
    auto direction() -> glm::vec3 const { return dir; }

    auto at(float t) const -> glm::vec3 {
        return orig + t*dir;
    }

private:
    glm::vec3 orig;
    glm::vec3 dir;
};