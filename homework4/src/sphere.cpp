#include "sphere.h"
#include "configfile/scenedata.h"
#include "vect/vect.h"
#include "debugger.h"

extern Debugger DEBUGGER;

Sphere::Sphere(SphereData* sdata) : sphere_data(sdata) {
}

bool Sphere::intersect(Intersection* intersection, Vect origin, Vect ray) {
  Vect point;
  Vect normal;
  float t;

  Vect center = sphere_data->center;
  float radius = sphere_data->radius;

  // Compute the intersection point, the normal, and the t (distance).
  // If at any point it is determined that there is no intersection,
  // just return false.

  // If you've gotten this far, there is an intersection.
  // Save the data and return true
  intersection->point = point;
  intersection->normal = normal;
  intersection->t = t;
  intersection->material = sphere_data->material;
  return true;
}
