#include <glm/glm.hpp>
#include <iostream>
#include "color.hpp"
#include "stb.h"

int main() {

    auto aspect_ratio = 16.0/9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1/
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Viewport widths less than one are ok since they are real valued.
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);

    RGB data[image_width][image_height];

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0);
            data[i][j] = write_color(std::cout, pixel_color);
        }
    }

    stbi_write_jpg("../image.jpg", image_width, image_height, 3, data, 100);

    std::clog << "\rDone.\n";       
    return 0;
}
