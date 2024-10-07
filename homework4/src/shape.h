#pragma once
#include "intersection.h"
#include "vect/vect.h"

class Shape {
public:
    virtual bool intersect(Intersection* intersection, Vect origin, Vect ray) { return false; }
};