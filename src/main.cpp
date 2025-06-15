#include <glm/glm.hpp>
#include <iostream>
#include "color.hpp"
#include "stb.h"

int main() {

    // Image
    const int image_width = 256;
    const int image_height = 256;

    glm::vec3 data[image_width][image_height];

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << '\n' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0);
            
            data[i][j] = write_color(std::cout, pixel_color);
        }
    }

    stbi_write_jpg("../image.jpg", image_width, image_height, 3, data, 100);

    std::clog << "\rDone.\n";       
    return 0;
}
