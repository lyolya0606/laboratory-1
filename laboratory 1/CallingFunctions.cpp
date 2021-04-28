#include <iostream>
#include "Struct.h"

using namespace std;

enum choosingDesicion {
  PARALL = 1,
  INTERSECT,
  NO_INERSECT
};

bool IsParall(Coefficients coefficientsFirstSegment, Coefficients coefficientsSecondSegment);
void Intersect(Coefficients coefficientsFirstSegment, Coefficients coefficientsSecondSegment, Point *intersection);

int CallingFunction(Coefficients coefficientsFirstSegment, Coefficients coefficientsSecondSegment, Segment *segmentFirst, Segment *segmentSecond, Point *intersection) {
  if (IsParall(coefficientsFirstSegment, coefficientsSecondSegment)) {
    return PARALL;
  } else {
    Intersect(coefficientsFirstSegment, coefficientsSecondSegment, intersection);

    if ((((*segmentFirst).startPoint.y <= (*intersection).y) && ((*segmentFirst).endPoint.y >= (*intersection).y))
      || (((*segmentFirst).startPoint.y >= (*intersection).y) && ((*segmentFirst).endPoint.y <= (*intersection).y))) {

      if ((((*segmentSecond).startPoint.y <= (*intersection).y) && ((*segmentSecond).endPoint.y >= (*intersection).y))
        || (((*segmentSecond).startPoint.y >= (*intersection).y) && ((*segmentSecond).endPoint.y <= (*intersection).y))) {
        return INTERSECT;
      } else {
        return NO_INERSECT;
      }
    } else return NO_INERSECT;
  }
}

