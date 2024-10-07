#pragma once
#include "vect/vect.h"
#include "configfile/scenedata.h"

struct Intersection {
  Vect point;
  Vect normal;
  float t;
  Material* material;
};

