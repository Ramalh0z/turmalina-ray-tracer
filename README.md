# Turmalina RayTracer

Just as the title says, is toy project of a sotfware ray-tracer, made with tutorials found in [Peter Shirley's books](https://raytracing.github.io)

## Building Instructions

git clone the repo:

```bash
$ git clone https://github.com/Ramalh0z/turmalina-ray-tracer
```

go to the source directory, and build with any C++17 compatible compiler:

```bash
$ cd src

// i recomend using clang
$ clang++ main.cpp -o main

// bonus: try out with the zig compiler!
$ zig c++ main.cpp -o main
```

to run, use the `">"` operator to save in a `.ppm` file

```bash
// on linux/macOS
$ main > image.ppm

// on winndows
$ main.exe > image.ppm
```
