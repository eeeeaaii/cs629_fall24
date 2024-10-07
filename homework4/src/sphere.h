#pragma once
#include "shape.h"
#include "configfile/scenedata.h"
#include "intersection.h"

class Sphere : public Shape {
public:
    SphereData* sphere_data;

    Sphere(SphereData* sdata);
    bool intersect(Intersection* intersection, Vect origin, Vect ray) override;
};