#pragma once

#include "configfile/scenedata.h"
#include "renderer/color.h"
#include "renderer/frame.h"
#include "intersection.h"
#include "vect/vect.h"
#include "shape.h"


std::vector<Shape*> setup_scene(RenderingInfo* _info);

bool find_closest_intersection(std::vector<Shape*> scene,
                               Intersection* closest,
                               Vect origin,
                               Vect ray);

Color computeBRDF(float E,
                  Intersection *intersection,
                  Vect to_eye,
                  Vect to_light,
                  float distance_to_light,
                  std::vector<Shape*> scene,
                  RenderingInfo *info);

Color illuminate_point_light(Intersection *intersection,
                             Vect eye,
                             Vect ray,
                             PointLightData *light,
                             std::vector<Shape*> scene,
                             RenderingInfo *info);

Color illumination_directional_light(Intersection *intersection,
                                     Vect eye,
                                     Vect ray,
                                     DirectionalLightData *light,
                                     std::vector<Shape*> scene,
                                     RenderingInfo *info);

Color render_ray(Vect eye,
                 Vect ray,
                 int depth,
                 std::vector<Shape*>,
                 RenderingInfo* info);

Vect get_ray(int x, int y, RenderingInfo *info);

void raytrace_scene(Frame* frame, RenderingInfo *info);
