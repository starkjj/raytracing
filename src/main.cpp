#include <glm/glm.hpp>
#include <iostream>
#include "color.hpp"
#include "stb.h"

int main() {

    // Image
    int image_width = 256;
    int image_height = 256;

    color data[image_width][image_height];

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0);
            
            data[j][i] = write_color(std::cout, pixel_color);
        }
    }

    stbi_write_jpg("../image.jpg", image_width, image_height, 3, data, 100);
}
