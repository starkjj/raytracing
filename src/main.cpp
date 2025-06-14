#include <iostream>
#include "stb.h"

int main() {

    // Image
    int image_width = 256;
    int image_height = 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            int ir = int(r * 255);
            int ig = int(g * 255);
            int ib = int(b * 255);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}
