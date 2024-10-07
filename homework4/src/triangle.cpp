#include "triangle.h"
#include "configfile/scenedata.h"
#include "vect/vect.h"
#include "intersection.h"



Triangle::Triangle(TriangleData* tdata) : triangle_data(tdata) {
}

bool Triangle::intersect(Intersection* intersection, Vect origin, Vect ray) {
  Vect point;
  Vect normal;
  float t;

  // Compute the intersection point, the normal, and the t (distance).
  // If at any point it is determined that there is no intersection,
  // just return false.

  // If you've gotten this far, there is an intersection.
  // Save the data and return true
  intersection->point = point;
  intersection->normal = normal;
  intersection->t = t;
  intersection->material = triangle_data->material;
  return true;
}