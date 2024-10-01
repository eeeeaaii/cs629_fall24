#include "bezier.h"
#include "midpoint_line.h"
#include "aa_lines.h"
#include "renderer/renderer_types.h"
#include "vect/vect.h"

Vect findPointOnBezier(float u, Vect p0, Vect p1, Vect p2, Vect p3) {
    // Add implementation here
}

void drawMidpointBezier(Frame* frame, Vect p0, Vect p1, Vect p2, Vect p3) {
    drawBezier(frame, p0, p1, p2, p3, true);
}

void drawAntiAliasedBezier(Frame* frame, Vect p0, Vect p1, Vect p2, Vect p3) {
    drawBezier(frame, p0, p1, p2, p3, false);
}

void drawBezier(Frame* frame, Vect p0, Vect p1, Vect p2, Vect p3, bool useMidpoint) {
    // Add implementation here
}

void drawFadedBezier(Frame* frame, Vect p0, Vect p1, Vect p2, Vect p3) {
    // Add implementation here (will be very similar to drawBezier)
}
