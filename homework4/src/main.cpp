#include <iostream>
#include <string>

#include "configfile/parser.h"
#include "configfile/scenedata.h"
#include "renderer/renderer.h"
#include "renderer/color.h"
#include "renderer/frame.h"
#include "raytracer.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <config file>" << std::endl;
    return 1;
  }
  // Output only does something if you have ImageMagick.
  // This is not necessary for the assignment.
  bool do_output = (argc == 3 && std::string(argv[2]) == "--output");

  std::string input_file = std::string(argv[1]);

  auto dot_pos = input_file.find_last_of('.');
  auto file_name_stem = input_file.substr(0, dot_pos);
  auto output_file = file_name_stem + ".png";

  Parser parser;
  RenderingInfo* info = parser.parseFile(input_file);
  if (info == nullptr) {
    std::cout << "Failed to parse file" << std::endl;
    return 1;
  }

  Frame frame;
  Renderer renderer;

  raytrace_scene(&frame, info);

  if (do_output) {
    frame.outputToFile(output_file);
  }

  if (!renderer.init(frame)) {
    std::cout << "Failed to init renderer" << std::endl;
    return 1;
  }
  while (renderer.render()) {
  }
}