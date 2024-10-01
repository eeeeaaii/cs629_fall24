#include "midpoint_line.h"

#include "vect/vect.h"

void drawMidpointLineWithColor(Frame* frame, Vect p0, Vect p1, Color c) {
	// to implement
}

void drawMidpointLine(Frame* frame, Vect p0, Vect p1) {
	drawMidpointLineWithColor(frame, p0, p1, {1.0, 1.0, 1.0});
}
