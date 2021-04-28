#include <iostream>
#include "Struct.h"

bool IsParall(Coefficients coefficientsFirstSegment, Coefficients coefficientsSecondSegment) {
  if ((coefficientsFirstSegment.a * coefficientsSecondSegment.b) == (coefficientsFirstSegment.b * coefficientsSecondSegment.a)) {
    return true;
  }
  else return false;
}

void Intersect(Coefficients coefficientsFirstSegment, Coefficients coefficientsSecondSegment, Point *intersection) {
  double det = coefficientsFirstSegment.a * coefficientsSecondSegment.b - coefficientsSecondSegment.a * coefficientsFirstSegment.b;
  (*intersection).x = (coefficientsFirstSegment.b * coefficientsSecondSegment.c - coefficientsSecondSegment.b * coefficientsFirstSegment.c) / det;
  (*intersection).y = (coefficientsSecondSegment.a * coefficientsFirstSegment.c - coefficientsFirstSegment.a * coefficientsSecondSegment.c) / det;
}

void CalculatingCoefficients(Coefficients *coefficientsFirstSegment, Coefficients *coefficientsSecondSegment, Segment segmentFirst, Segment segmentSecond) {
  (*coefficientsFirstSegment).a = segmentFirst.startPoint.y - segmentFirst.endPoint.y;
  (*coefficientsFirstSegment).b = segmentFirst.endPoint.x - segmentFirst.startPoint.x;
  (*coefficientsFirstSegment).c = segmentFirst.startPoint.x * segmentFirst.endPoint.y - segmentFirst.endPoint.x * segmentFirst.startPoint.y;
  (*coefficientsSecondSegment).a = segmentSecond.startPoint.y - segmentSecond.endPoint.y;
  (*coefficientsSecondSegment).b = segmentSecond.endPoint.x - segmentSecond.startPoint.x;
  (*coefficientsSecondSegment).c = segmentSecond.startPoint.x * segmentSecond.endPoint.y - segmentSecond.endPoint.x * segmentSecond.startPoint.y;

}
