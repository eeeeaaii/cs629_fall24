#include "raytracer.h"

#include "configfile/scenedata.h"
#include "renderer/color.h"
#include "renderer/frame.h"
#include "vect/vect.h"
#include "intersection.h"
#include "debugger.h"
#include "sphere.h"
#include "triangle.h"

#include <iostream>

#define LOG_XMIN 398
#define LOG_XMAX 402
#define LOG_YMIN 298
#define LOG_YMAX 302

extern Debugger DEBUGGER;

  std::vector<Shape*> scene;

std::vector<Shape*> setup_scene(RenderingInfo* info)
{
  for (auto sphere : info->spheres) {
    Sphere* obj = new Sphere(sphere);
    scene.push_back(obj);
  }
  for (auto triangle : info->triangles) {
    Triangle* tri = new Triangle(triangle);
    scene.push_back(tri);
  }
  return scene;
}


bool find_closest_intersection(std::vector<Shape*> scene,
                               Intersection* closest,
                               Vect origin,
                               Vect ray)
{
  // This is where you go over all the shapes in the
  // scene and find the one that is closest.
  // Use the "t" value in the intersection point
  // to tell you how close it is.
  // return false if there are no intersections along
  // this ray.

  return found_any_intersections;
}



Color computeBRDF(float E,
                  Intersection *intersection,
                  Vect to_eye,
                  Vect to_light,
                  float distance_to_light,
                  std::vector<Shape*> scene,
                  RenderingInfo *info)
{
  // Compute the BRDF at a given intersection point.
  // The E term passed in here is irradiance.
  // Remember to use the correct color from the intersection
  // point's material: ambient and diffuse use the material
  // color, while specular just uses white.
  // Remember to scale the specular component by the 
  // glossiness.
  // This is where you would compute shadows, if you 
  // are doing it.

  return Color(/* something */);
}

Color illuminate_point_light(Intersection *intersection,
                             Vect eye,
                             Vect ray,
                             PointLightData *light,
                             std::vector<Shape*> scene,
                             RenderingInfo *info)
{
  // This function calculates the color contribution of the
  // given point light source. You will use the BRDF
  // function to do the majority of the shading work.

  return computeBRDF(/* something */);
}

Color illuminate_directional_light(Intersection *intersection,
                                   Vect eye,
                                   Vect ray,
                                   DirectionalLightData *light,   
                                   std::vector<Shape*> scene,
                                   RenderingInfo *info)
{
  // This function calculates the color contribution of the
  // given directional light source. You will use the BRDF
  // function to do the majority of the shading work.

  return computeBRDF(/* something */);
}


Color render_ray(Vect eye,
                 Vect ray,
                 int depth,
                 std::vector<Shape*> scene,
                 RenderingInfo* info)
{
  Color c = Color(0.0f, 0.0f, 0.0f);

  // This function starts with a color of zero and progressively
  // adds color to the pixel. First, determine if there is an
  // intersection point (if not, the color is zero).
  //
  // If there is an intersection point, then go over all the light
  // sources and add the contribution of that light source.
  //
  // If doing mirror reflections, add those also.
  //
  // Make sure you also add in ambient illumination.
  //
  // Finally, after adding all the color to the pixel,
  // return the color.

  return c;
}

// The implementation of "get_ray" is provided for you.
// This projects rays through the viewing plane into the scene.
Vect get_ray(int x, int y, RenderingInfo *info)
{
  // origin point is (0, 0, 0)
  float aspect_ratio = (float)WIDTH / (float)HEIGHT; // 800/ 600 = 1.3333
  float screen_space_width = 2.0f;
  float screen_space_height = screen_space_width / aspect_ratio;
  float halfSSW = screen_space_width / 2.0f;
  float halfSSH = screen_space_height / 2.0f;

  // A 45 degree field of view is actually fine.
  float dist_origin = info->focal_length;

  float x_offset = ((float)x / (float)WIDTH) * screen_space_width - halfSSW;
  float y_offset = ((float)y / (float)HEIGHT) * screen_space_height - halfSSH;
  Vect ray = Vect(x_offset, y_offset, dist_origin);
  return ray.normalize();
}

// This is the main raytracer loop, where it goes over
// every pixel.
void raytrace_scene(Frame *frame, RenderingInfo *info)
{
  DEBUGGER.start_debug();

  std::vector<Shape*> scene = setup_scene(info);

  int num_bounces = 5;

  for (int i = 0; i < WIDTH; i++)
  {
    for (int j = 0; j < HEIGHT; j++)
    {
      DEBUGGER.start_pixel(i, j);
      Vect v = get_ray(i, j, info);
      Color c = render_ray(Vect(0.0f, 0.0f, 0.0f), v, num_bounces, scene, info);
      frame->setColor(i, j, c);
    }
  }
  DEBUGGER.draw_debug_frame(frame);
}