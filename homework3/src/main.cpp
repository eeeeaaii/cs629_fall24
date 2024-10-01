#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "aa_lines.h"
#include "bezier.h"
#include "midpoint_line.h"
#include "renderer/renderer.h"
#include "renderer/renderer_types.h"
#include "vect/vect.h"

void die() {
  std::cout << "USAGE: homework3_exe [OPCODE OPCODE_ARG]*" << std::endl;
  exit(1);
}

std::vector<std::string> split(std::string str, char splitOn) {
  std::istringstream ss(str + splitOn);
  std::string token;
  std::vector<std::string> results;
  while (std::getline(ss, token, splitOn)) {
    results.push_back(token);
  }
  return results;
}

// x0,y0:x1,y1
void parseLineArgs(std::string opcode_arg, Vect& rp0, Vect& rp1) {
  auto points = split(opcode_arg, ';');
  if (points.size() != 2) die();
  auto p0s = split(points[0], ',');
  auto p1s = split(points[1], ',');
  if (p0s.size() != 2) die();
  if (p1s.size() != 2) die();
  Vect p0(std::stoi(p0s[0]), std::stoi(p0s[1]));
  Vect p1(std::stoi(p1s[0]), std::stoi(p1s[1]));
  rp0 = p0;
  rp1 = p1;
}

void parseBezierArgs(std::string opcode_arg, Vect& rp0, Vect& rp1, Vect& rp2,
                     Vect& rp3) {
  auto points = split(opcode_arg, ';');
  if (points.size() != 4) die();
  auto p0s = split(points[0], ',');
  auto p1s = split(points[1], ',');
  auto p2s = split(points[2], ',');
  auto p3s = split(points[3], ',');
  Vect p0(std::stoi(p0s[0]), std::stoi(p0s[1]));
  Vect p1(std::stoi(p1s[0]), std::stoi(p1s[1]));
  Vect p2(std::stoi(p2s[0]), std::stoi(p2s[1]));
  Vect p3(std::stoi(p3s[0]), std::stoi(p3s[1]));
  rp0 = p0;
  rp1 = p1;
  rp2 = p2;
  rp3 = p3;
}

float minx;
float xdiff;
float miny;
float ydiff;

Vect interp(Vect v) {
  float x = v.x;
  float y = v.y;
  x -= minx;
  x /= xdiff;
  x *= 400;
  x += 200;

  y -= miny;
  y /= ydiff;
  y *= 300;
  y += 150;

  return Vect(x, y);
}

int main(int argc, char** argv) {
  Frame frame;
  Renderer renderer;

  if (argc % 2 != 1) {
    die();
  }

  for (int i = 1; i < argc; i += 2) {
    std::string opcode = argv[i];
    std::string opcode_arg = argv[i + 1];
    if (opcode == "--line") {
      Vect p0;
      Vect p1;
      parseLineArgs(opcode_arg, p0, p1);
      drawMidpointLine(&frame, p0, p1);
    } else if (opcode == "--aaline") {
      Vect p0;
      Vect p1;
      parseLineArgs(opcode_arg, p0, p1);
      drawAntiAliasedLineBoxFilter(&frame, p0, p1);
    } else if (opcode == "--aalinewas") {
      Vect p0;
      Vect p1;
      parseLineArgs(opcode_arg, p0, p1);
      drawAntiAliasedLineWASFilter(&frame, p0, p1);
    } else if (opcode == "--bezier") {
      Vect p0;
      Vect p1;
      Vect p2;
      Vect p3;
      parseBezierArgs(opcode_arg, p0, p1, p2, p3);
      drawMidpointBezier(&frame, p0, p1, p2, p3);
    } else if (opcode == "--aabezier") {
      Vect p0;
      Vect p1;
      Vect p2;
      Vect p3;
      parseBezierArgs(opcode_arg, p0, p1, p2, p3);
      drawAntiAliasedBezier(&frame, p0, p1, p2, p3);
    } else if (opcode == "--faded") {
      Vect p0;
      Vect p1;
      Vect p2;
      Vect p3;
      parseBezierArgs(opcode_arg, p0, p1, p2, p3);
      drawFadedBezier(&frame, p0, p1, p2, p3);
    }
  }
  if (!renderer.init(frame)) {
    std::cout << "Failed to init renderer" << std::endl;
    return 1;
  }
  while (renderer.render()) {
  }
  return 0;
}