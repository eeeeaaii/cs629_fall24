#pragma once
#include <vector>
#include "color.h"

class Frame {
private:
  std::vector<Color> colors;
public:
  Frame();
  Color getColor(int x, int y) const;
  void setColor(int x, int y, Color p);
  void clear();
  void outputToFile(std::string filename);
};
