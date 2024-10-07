#pragma once
#include <string>
#include <vector>

#include "../renderer/color.h"
#include "../vect/vect.h"

// Do not modify any of this data after parsing.
// Treat this as a read-only data structure.

struct Material {
  Color color;
  float glossiness;
  float p;
  float mirror;
  std::string name;
};

struct SphereData {
  Vect center;
  float radius;
  Material* material;
  std::string material_name;
};

struct TriangleData {
  Vect p0;
  Vect p1;
  Vect p2;
  Material* material;
  std::string material_name;
};

struct PointLightData {
  Vect position;
  float intensity;
};

struct DirectionalLightData {
  Vect direction;
  float h_intensity;
};

struct RenderingInfo {
  float ambient;
  float focal_length;
  bool shadows;
  DirectionalLightData* dir_light;
  std::vector<PointLightData*> point_lights;
  std::vector<TriangleData*> triangles;
  std::vector<SphereData*> spheres;
  std::vector<Material*> materials;
};
