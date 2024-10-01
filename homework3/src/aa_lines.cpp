#include "aa_lines.h"

#include "renderer/renderer_types.h"
#include "vect/vect.h"

#include <cmath>


// Use this function to compute the weight for a given pixel
// using the box filter. "forceAllOn" means you compute
// the weight for a situation where all subpixels are illuminated.
float boxFilter(Vect center, Vect line, Vect lineOrigin,
                              float thickness, bool forceAllOn) {
  // to implement
}


// Use this function to compute the total weight for a given pixel
// using weighted area sampling. "forceAllOn" means you compute
// the weight for a situation where all subpixels are illuminated.
float wasFilter(Vect center, Vect line, Vect lineOrigin,
                               float thickness, bool forceAllOn) {
  // to implement
}

void drawAntiAliasedLineBoxFilter(Frame* frame, Vect p0, Vect p1) {
    drawAALine(frame, p0, p1, true);
}

void drawAntiAliasedLineWASFilter(Frame* frame, Vect p0, Vect p1) {
    drawAALine(frame, p0, p1, false);
}

// One option: 
void drawAALine(Frame* frame, Vect p0, Vect p1, bool useBoxFilter) {
  Vect start = p0;
  Vect end = p1;
  Vect line = end - start;

  struct Pixel {
    int x;
    int y;
  };

  std::vector<Pixel> pixels;

  int minx = (int)std::min(p0.x, p1.x);
  int maxx = (int)std::ceil(std::max(p0.x, p1.x));
  int miny = (int)std::min(p0.y, p1.y);
  int maxy = (int)std::ceil(std::max(p0.y, p1.y));

  for (int x = minx; x <= maxx; x++) {
    for (int y = miny; y <= maxy; y++) {
      Pixel p = {x, y};
      pixels.push_back(p);
    }
  }

  Vect unused = {0.0f, 0.0f, 0.0f};

  float weightScaleFactor = useBoxFilter
        ? boxFilter(unused, unused, unused, 2.0f, true)
        : wasFilter(unused, unused, unused, 2.0f, true);

  for (auto pixel : pixels) {
    float x = pixel.x;
    float y = pixel.y;

    Vect pixelCenter = {x, y, 0.0f};

    float weight = useBoxFilter 
            ? boxFilter(pixelCenter, line, start, THICKNESS, false)
            : wasFilter(pixelCenter, line, start, THICKNESS, false);

    if (weight == 0) {
      continue;
    }
    float realWeight = weight / weightScaleFactor;
    Color white = {1.0, 1.0, 1.0};
    Color finalColor = white * realWeight;
    frame->addColor(pixel.x, pixel.y, finalColor);
  }
}
