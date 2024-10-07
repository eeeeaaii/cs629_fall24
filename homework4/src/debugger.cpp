#include "debugger.h"
#include <vector>
#include <iostream>
#include "renderer/frame.h"
#include "renderer/color.h"

Debugger DEBUGGER;

Debugger::Debugger() {
    std::vector<std::vector<float>> vect(800, std::vector<float>(600));
    values = vect;
    debugged = false;
}

void Debugger::set_value(float v) {
    if (!debugged) {
        debugged = true;
        min = max = v;
    } else {
        if (v < min) min = v;
        if (v > max) max = v;
    }
    if (v < 0 || v > 1) found_out_of_range = true;
    values[currentX][currentY] = v;
}

void Debugger::start_pixel(int x, int y) {
    currentX = x;
    currentY = y;
}

void Debugger::start_debug() {
    currentX = 0;
    currentY = 0;
    max = 0;
    min = 0;
}

bool Debugger::has_debug_info() {
    return debugged;
}

float Debugger::get_at(int x, int y) {
    if (!found_out_of_range) {
        return values[x][y];
    }
    float v = values[x][y] - min;
    float span = max - min;
    return v / span;
}

void Debugger::print_value(int x, int y) {
    std::cout << "(" << x << "," << y << ") = " << values[x][y] << std::endl;
}

void Debugger::print() {
    std::cout << "DEBUG INFO" << std::endl;
    std::cout << "min: " << min << std::endl;
    std::cout << "max: " << max << std::endl;
    print_value(200, 200);
    print_value(400, 200);
    print_value(600, 200);
    print_value(200, 400);
    print_value(400, 400);
    print_value(600, 400);
}

void Debugger::draw_debug_frame(Frame* frame) {
  if (has_debug_info())
  {
    for (int i = 0; i < WIDTH; i++)
    {
      for (int j = 0; j < HEIGHT; j++)
      {
        float val = get_at(i, j);
        frame->setColor(i, j, Color(val, val, val));
      }
    }
  }

}