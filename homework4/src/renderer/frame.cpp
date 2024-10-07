#include "frame.h"
#include "color.h"
#include "filewriter.h"

Frame::Frame() {
    colors.resize(WIDTH * HEIGHT);
}

Color Frame::getColor(int x, int y) const {
    return colors[y * WIDTH + x];
}

void Frame::setColor(int x, int y, Color p) {
    colors[y * WIDTH + x] = p;
}

void Frame::clear() {
    colors = std::vector<Color>(WIDTH * HEIGHT);
}

void Frame::outputToFile(std::string filename)  {
  FileWriter fw;
  fw.writeFile(colors, filename);
}
