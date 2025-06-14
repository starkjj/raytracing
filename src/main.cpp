#include <iostream>
#include "stb.h"

int main() {

    struct RGB {
        unsigned char r, g, b;
    };

    // Image
    int image_width = 256;
    int image_height = 256;

    struct RGB data[image_width][image_height];

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto r = double(j) / (image_width - 1);
            auto g = double(i) / (image_height - 1);
            auto b = 0.0;

            int ir = int(r * 255);
            int ig = int(g * 255);
            int ib = int(b * 255);

            data[i][j].r = ir;
            data[i][j].g = ig;
            data[i][j].b = ib;

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    stbi_write_jpg("image.jpg", image_width, image_height, 3, data, 100);
}
