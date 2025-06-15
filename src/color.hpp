#pragma once
#include <glm/glm.hpp>
#include <iostream>

using color = glm::vec3;

struct RGB {
    unsigned char r, g, b;
};

auto write_color_ppm(std::ostream& out, const color& pixel_color) -> void {
    auto r = pixel_color.x;
    auto g = pixel_color.y;
    auto b = pixel_color.z;

    // Translate the [0,1] range to [0,255]
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel color components
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

auto write_color(std::ostream& out, const color& pixel_color) -> RGB {
    auto r = pixel_color.x;
    auto g = pixel_color.y;
    auto b = pixel_color.z;

    // Translate the [0,1] range to [0,255]
    int rbyte = int(255 * r);
    int gbyte = int(255 * g);
    int bbyte = int(255 * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';

    RGB data;
    data.r = static_cast<unsigned char>(rbyte);
    data.g = static_cast<unsigned char>(gbyte);
    data.b = static_cast<unsigned char>(bbyte);

    return data;
}