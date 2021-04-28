#pragma once
#include "Struct.h"

int CallingFunction(Coefficients coefficientsFirstSegment, Coefficients coefficientsSecondSegment, Segment *segmentFirst, Segment *segmentSecond, Point *intersection);
void CalculatingCoefficients(Coefficients *coefficientsFirstSegment, Coefficients *coefficientsSecondSegment, Segment segmentFirst, Segment segmentSecond);