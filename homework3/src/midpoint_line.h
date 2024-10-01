#pragma once

#include "renderer/renderer_types.h"
#include "vect/vect.h"

// defined for you
void drawMidpointLine(Frame* frame, Vect p0, Vect p1);
void drawMidpointLineWithColor(Frame* frame, Vect p0, Vect p1, Color c);

// define helper functions here
// Some helper functions you might need...
// - a function for the implicit line equation
// - whether or not to move up (or down, or left, or right)
// maybe others?
