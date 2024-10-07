#pragma once
#include "shape.h"
#include "configfile/scenedata.h"
#include "intersection.h"

class Triangle : public Shape {
public:
    TriangleData* triangle_data;

    Triangle(TriangleData* tdata);
    bool intersect(Intersection* intersection, Vect origin, Vect ray) override;
};