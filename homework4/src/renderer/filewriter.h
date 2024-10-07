#pragma once
#include <vector>
#include "color.h"
#include <string>

class FileWriter {
public:
    void writeFile(std::vector<Color> colors, std::string filename);
};