#pragma once

#include "renderer/renderer_types.h"
#include "vect/vect.h"

#define THICKNESS 1.0f
#define TESTPADDING 6
#define WAS_SUBDIVISIONS 4
#define BF_SUBDIVISIONS 4

// defined for you
float boxFilter(Vect center, Vect line, Vect lineOrigin, float thickness, bool forceAllOn);
float wasFilter(Vect center, Vect line, Vect lineOrigin, float thickness, bool forceAllOn);
void drawAntiAliasedLineBoxFilter(Frame* frame, Vect p0, Vect p1);
void drawAntiAliasedLineWASFilter(Frame* frame, Vect p0, Vect p1);
void drawAALine(Frame* frame, Vect p0, Vect p1, bool useBoxFilter);

