#include "turmalina.hpp"

#include "math/color.hpp"
#include "objects/sphere.hpp"
#include "objects/hittable_list.hpp"

#include <iostream>

color ray_color(const ray& r, hittable& world)
{
    hit_record rec;
    if (world.hit(r, 0, infinty, rec) ){
        return 0.5 * (rec.normal + color(1,1,1));
    }

    vec3 unit_direction = unit_vector(r.direction);
    auto t = 0.5 * (unit_direction.y + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0); 
}

int main(){

    // image
    constexpr double aspect_ratio = 16.0 / 9.0;
    constexpr int image_w = 400;
    constexpr int image_h = static_cast<int>(image_w / aspect_ratio);

    // world
    hittable_list world;
    world.add(make_shared<sphere> ( point3(0,0,-1), 0.5));
    world.add(make_shared<sphere> ( point3(0, -100.5, -1), 100));

    // camera
    auto viewport_h = 2.0;
    auto viewport_w = aspect_ratio * viewport_h;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_w, 0, 0);
    auto vertical = vec3(0, viewport_h, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    // magic numbers for P3 (ASCII) image
    std::cout << "P3\n" << image_w << ' ' << image_h << "\n255\n";

    for (int j = image_h-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        
        for (int i = 0; i < image_w; ++i) {
            auto u = double(i) / (image_w-1);
            auto v = double(j) / (image_h-1);

            // magic stuff with camera, well as i know... (ramalh0z)
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r, world);

            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone. \n";
}