#include "filewriter.h"
#include "color.h"
#include <string>

#ifdef WRITER_INCLUDED
#include <Magick++.h>
#include <iostream>
#endif

void FileWriter::writeFile(std::vector<Color> colors, std::string filename) {
#ifdef WRITER_INCLUDED
    Magick::InitializeMagick(nullptr);

    Magick::Image image(Magick::Geometry(WIDTH, HEIGHT), Magick::Color("black"));

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            Color color = colors[y * WIDTH + x].clamp();
            Magick::Quantum red = color.r * 65535;
            Magick::Quantum green = color.g * 65535;
            Magick::Quantum blue = color.b * 65535;
            image.pixelColor(x, y, Magick::Color(red, green, blue));
        }
    }

    try {
        image.write(filename);
        std::cout << "Successfully wrote image." << std::endl;
    } catch (Magick::Exception &error) {
        std::cout << "Failed to write image." << std::endl;
    }
#endif
}

