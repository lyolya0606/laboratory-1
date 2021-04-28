#pragma once

struct Coefficients {
  //ax + by + c = 0
  double a;
  double b;
  double c;
};

struct Point {
  double x;
  double y;
};

struct Segment {
  Point startPoint;
  Point endPoint;
};