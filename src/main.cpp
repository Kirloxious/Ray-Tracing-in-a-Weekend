#include "util.h"

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"

#include <iostream>
#include <fstream>
#include <chrono>




int main(int argc, char const *argv[])
{
    //initialize output file
    std::ofstream output_file;
    
    //World
    hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    //Camera
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    auto t1 = std::chrono::high_resolution_clock::now();
    cam.render(world, output_file, "image.ppm");
    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> ms_double = t2-t1;
    std::cout << ms_double.count() << "ms\n";

    return 0;
}
