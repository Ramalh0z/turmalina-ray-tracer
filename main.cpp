#include <iostream>
#include "color.hpp"
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

            color pixel_color(float(i) / (image_w-1),
                              float(j) / (image_h-1),
                              0.25);

            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone. \n";
    return 0;
}