#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include "definitions.h"

struct Color {
  float r;
  float g;
  float b;

  Color() : r(0), g(0), b(0) {}
  Color(float in_r, float in_g, float in_b) : r(in_r), g(in_g), b(in_b) {}

  Color operator+(Color p) {
    float newRed = std::min(r + p.r, 1.0f);
    float newGreen = std::min(g + p.g, 1.0f);
    float newBlue = std::min(b + p.b, 1.0f);
    return {newRed, newGreen, newBlue};
  }

  Color clamp() {
    float cr = std::min(r, 1.0f);
    float cg = std::min(g, 1.0f);
    float cb = std::min(b, 1.0f);
    return Color(cr, cg, cb);
  }

  friend std::ostream& operator<<(std::ostream& os, const Color& obj);
};

Color operator*(Color p, float f);

Color operator*(float f, Color p);

Color operator+=(Color &p1, Color p2);

Color operator"" _c(unsigned long long inc);
