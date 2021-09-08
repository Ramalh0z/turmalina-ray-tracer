#include <iostream>
#include "vec3.hpp"


int main(){
    // image dimensions
    constexpr int image_w = 256;
    constexpr int image_h = 256;

    // magic numbers for P3 (ASCII) image
    std::cout << "P3\n" << image_w << ' ' << image_h << "\n255\n";

    for (int j = image_h-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_w; ++i) {
            auto r = double(i) / (image_w-1);
            auto g = double(j) / (image_h-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::cerr << "\nDone. \n";
    return 0;
}