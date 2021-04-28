#include <iostream>
#include "Struct.h"
#include "Solution.h"

using namespace std;

bool Test1(Coefficients *coefficientsFirstSegment, Coefficients *coefficientsSecondSegment, Segment *segmentFirst, Segment *segmentSecond, Point *intersection, Point *correct) {
  (*segmentFirst).startPoint.x = 2;
  (*segmentFirst).startPoint.y = 3;
  (*segmentFirst).endPoint.x = 1;
  (*segmentFirst).endPoint.y = 5;
  (*segmentSecond).startPoint.x = 2;
  (*segmentSecond).startPoint.y = 5;
  (*segmentSecond).endPoint.x = 2;
  (*segmentSecond).endPoint.y = 3;
  CalculatingCoefficients(coefficientsFirstSegment, coefficientsSecondSegment, *segmentFirst, *segmentSecond);
  CallingFunction(*coefficientsFirstSegment, *coefficientsSecondSegment, segmentFirst, segmentSecond, intersection);

  (*correct).x = 2;
  (*correct).y = 3;

  if ((*intersection).x == (*correct).x && (*intersection).y == (*correct).y) {
    return true;
  } else {
    return false;
  }
}

bool Test2(Coefficients *coefficientsFirstSegment, Coefficients *coefficientsSecondSegment, Segment *segmentFirst, Segment *segmentSecond, Point *intersection, Point *correct) {
  (*segmentFirst).startPoint.x = 0;
  (*segmentFirst).startPoint.y = 0;
  (*segmentFirst).endPoint.x = 2;
  (*segmentFirst).endPoint.y = 2;
  (*segmentSecond).startPoint.x = 2;
  (*segmentSecond).startPoint.y = 1;
  (*segmentSecond).endPoint.x = 1;
  (*segmentSecond).endPoint.y = 2;

  CalculatingCoefficients(coefficientsFirstSegment, coefficientsSecondSegment, *segmentFirst, *segmentSecond);
  CallingFunction(*coefficientsFirstSegment, *coefficientsSecondSegment, segmentFirst, segmentSecond, intersection);

  (*correct).x = 1.5;
  (*correct).y = 1.5;

  if ((*intersection).x == (*correct).x && (*intersection).y == (*correct).y) {
    return true;
  } else {
    return false;
  }
}

bool Test3(Coefficients *coefficientsFirstSegment, Coefficients *coefficientsSecondSegment, Segment *segmentFirst, Segment *segmentSecond, Point *intersection, Point *correct) {
  (*segmentFirst).startPoint.x = 1;
  (*segmentFirst).startPoint.y = 1;
  (*segmentFirst).endPoint.x = 4;
  (*segmentFirst).endPoint.y = 2;
  (*segmentSecond).startPoint.x = 1;
  (*segmentSecond).startPoint.y = 1;
  (*segmentSecond).endPoint.x = 3;
  (*segmentSecond).endPoint.y = 4;

  CalculatingCoefficients(coefficientsFirstSegment, coefficientsSecondSegment, *segmentFirst, *segmentSecond);
  CallingFunction(*coefficientsFirstSegment, *coefficientsSecondSegment, segmentFirst, segmentSecond, intersection);

  (*correct).x = 1;
  (*correct).y = 1;

  if ((*intersection).x == (*correct).x && (*intersection).y == (*correct).y) {

    return true;
  } else {
    return false;
  }
}

bool Test4(Coefficients *coefficientsFirstSegment, Coefficients *coefficientsSecondSegment, Segment *segmentFirst, Segment *segmentSecond, Point *intersection, Point *correct) {
  (*segmentFirst).startPoint.x = 0;
  (*segmentFirst).startPoint.y = 0;
  (*segmentFirst).endPoint.x = 4;
  (*segmentFirst).endPoint.y = 1;
  (*segmentSecond).startPoint.x = 2;
  (*segmentSecond).startPoint.y = -2;
  (*segmentSecond).endPoint.x = 2;
  (*segmentSecond).endPoint.y = 2;

  CalculatingCoefficients(coefficientsFirstSegment, coefficientsSecondSegment, *segmentFirst, *segmentSecond);
  CallingFunction(*coefficientsFirstSegment, *coefficientsSecondSegment, segmentFirst, segmentSecond, intersection);

  (*correct).x = 2;
  (*correct).y = 0.5;


  if ((*intersection).x == (*correct).x && (*intersection).y == (*correct).y) {
    return true;
  } else {
    return false;
  }
}

bool Test5(Coefficients *coefficientsFirstSegment, Coefficients *coefficientsSecondSegment, Segment *segmentFirst, Segment *segmentSecond, Point *intersection, Point *correct) {
  (*segmentFirst).startPoint.x = 0;
  (*segmentFirst).startPoint.y = 0;
  (*segmentFirst).endPoint.x = 6;
  (*segmentFirst).endPoint.y = 2;
  (*segmentSecond).startPoint.x = 1;
  (*segmentSecond).startPoint.y = 3;
  (*segmentSecond).endPoint.x = 4;
  (*segmentSecond).endPoint.y = 0;

  CalculatingCoefficients(coefficientsFirstSegment, coefficientsSecondSegment, *segmentFirst, *segmentSecond);
  CallingFunction(*coefficientsFirstSegment, *coefficientsSecondSegment, segmentFirst, segmentSecond, intersection);

  (*correct).x = 3;
  (*correct).y = 1;

  if ((*intersection).x == (*correct).x && (*intersection).y == (*correct).y) {
    return true;
  } else {
    return false;
  }
}


void CheckingTests(void) {
  Segment segmentFirst;
  Segment segmentSecond;
  Point intersection;
  Coefficients coefficientsFirstSegment;
  Coefficients coefficientsSecondSegment;

  int counter = 0;
  const int ALL_TESTS_PASSED = 5;
  bool check;

  Point correct;

 
  check = Test1(&coefficientsFirstSegment, &coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection, &correct);

  if (check == true) {
    counter++;
  } else {
    CalculatingCoefficients(&coefficientsFirstSegment, &coefficientsSecondSegment, segmentFirst, segmentSecond);
    CallingFunction(coefficientsFirstSegment, coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection);
    cout << "Test 1 failed" << endl;
    cout << "Points of the first segment:" << endl;
    cout << "Point 1: " << endl << "x1 = " << segmentFirst.startPoint.x << endl;
    cout << "y1 = " << segmentFirst.startPoint.y << endl;;
    cout << "Point 2: " << endl << "x2 = " << segmentFirst.endPoint.x << endl;
    cout << "y2 = " << segmentFirst.endPoint.y << endl;
    cout << "Points of the second segment:" << endl;
    cout << "Point 1: " << endl << "x3 = " << segmentSecond.startPoint.x << endl;
    cout << "y3 = " << segmentSecond.startPoint.y << endl;
    cout << "Point 2: " << endl << "x4 = " << segmentSecond.endPoint.x << endl;
    cout << "y4 = " << segmentSecond.endPoint.y << endl;
    cout << "Correct point of intersection: x = " << correct.x << ", y = " << correct.y << endl
      << "The resulting point of intersection: x = " << intersection.x << ", "
      << "y = " << intersection.y << endl;
    check = false;
  }


  check = Test2(&coefficientsFirstSegment, &coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection, &correct);

  if (check == true) {
    counter++;
  } else {
    CalculatingCoefficients(&coefficientsFirstSegment, &coefficientsSecondSegment, segmentFirst, segmentSecond);
    CallingFunction(coefficientsFirstSegment, coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection);
    cout << "Test 2 failed" << endl;
    cout << "Points of the first segment:" << endl;
    cout << "Point 1: " << endl << "x1 = " << segmentFirst.startPoint.x << endl;
    cout << "y1 = " << segmentFirst.startPoint.y << endl;;
    cout << "Point 2: " << endl << "x2 = " << segmentFirst.endPoint.x << endl;
    cout << "y2 = " << segmentFirst.endPoint.y << endl;
    cout << "Points of the second segment:" << endl;
    cout << "Point 1: " << endl << "x3 = " << segmentSecond.startPoint.x << endl;
    cout << "y3 = " << segmentSecond.startPoint.y << endl;
    cout << "Point 2: " << endl << "x4 = " << segmentSecond.endPoint.x << endl;
    cout << "y4 = " << segmentSecond.endPoint.y << endl;
    cout << "Correct point of intersection: x = " << correct.x << ", y = " << correct.y << endl
      << "The resulting point of intersection: x = " << intersection.x << ", "
      << "y = " << intersection.y << endl;
    check = false;
  }


  check = Test3(&coefficientsFirstSegment, &coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection, &correct);

  if (check == true) {
    counter++;
  } else {
    CalculatingCoefficients(&coefficientsFirstSegment, &coefficientsSecondSegment, segmentFirst, segmentSecond);
    CallingFunction(coefficientsFirstSegment, coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection);
    cout << "Test 3 failed" << endl;
    cout << "Points of the first segment:" << endl;
    cout << "Point 1: " << endl << "x1 = " << segmentFirst.startPoint.x << endl;
    cout << "y1 = " << segmentFirst.startPoint.y << endl;;
    cout << "Point 2: " << endl << "x2 = " << segmentFirst.endPoint.x << endl;
    cout << "y2 = " << segmentFirst.endPoint.y << endl;
    cout << "Points of the second segment:" << endl;
    cout << "Point 1: " << endl << "x3 = " << segmentSecond.startPoint.x << endl;
    cout << "y3 = " << segmentSecond.startPoint.y << endl;
    cout << "Point 2: " << endl << "x4 = " << segmentSecond.endPoint.x << endl;
    cout << "y4 = " << segmentSecond.endPoint.y << endl;
    cout << "Correct point of intersection: x = " << correct.x << ", y = " << correct.y << endl
      << "The resulting point of intersection: x = " << intersection.x << ", "
      << "y = " << intersection.y << endl;
    check = false;
  }


  check = Test4(&coefficientsFirstSegment, &coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection, &correct);

  if (check == true) {
    counter++;
  } else {
    CalculatingCoefficients(&coefficientsFirstSegment, &coefficientsSecondSegment, segmentFirst, segmentSecond);
    CallingFunction(coefficientsFirstSegment, coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection);
    cout << "Test 4 failed" << endl;
    cout << "Points of the first segment:" << endl;
    cout << "Point 1: " << endl << "x1 = " << segmentFirst.startPoint.x << endl;
    cout << "y1 = " << segmentFirst.startPoint.y << endl;;
    cout << "Point 2: " << endl << "x2 = " << segmentFirst.endPoint.x << endl;
    cout << "y2 = " << segmentFirst.endPoint.y << endl;
    cout << "Points of the second segment:" << endl;
    cout << "Point 1: " << endl << "x3 = " << segmentSecond.startPoint.x << endl;
    cout << "y3 = " << segmentSecond.startPoint.y << endl;
    cout << "Point 2: " << endl << "x4 = " << segmentSecond.endPoint.x << endl;
    cout << "y4 = " << segmentSecond.endPoint.y << endl;
    cout << "Correct point of intersection: x = " << correct.x << ", y = " << correct.y << endl
      << "The resulting point of intersection: x = " << intersection.x << ", "
      << "y = " << intersection.y << endl;
    check = false;
  }



  check = Test5(&coefficientsFirstSegment, &coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection, &correct);

  if (check == true) {
    counter++;
  } else {
    CalculatingCoefficients(&coefficientsFirstSegment, &coefficientsSecondSegment, segmentFirst, segmentSecond);
    CallingFunction(coefficientsFirstSegment, coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection);
    cout << "Test 5 failed" << endl;
    cout << "Points of the first segment:" << endl;
    cout << "Point 1: " << endl << "x1 = " << segmentFirst.startPoint.x << endl;
    cout << "y1 = " << segmentFirst.startPoint.y << endl;;
    cout << "Point 2: " << endl << "x2 = " << segmentFirst.endPoint.x << endl;
    cout << "y2 = " << segmentFirst.endPoint.y << endl;
    cout << "Points of the second segment:" << endl;
    cout << "Point 1: " << endl << "x3 = " << segmentSecond.startPoint.x << endl;
    cout << "y3 = " << segmentSecond.startPoint.y << endl;
    cout << "Point 2: " << endl << "x4 = " << segmentSecond.endPoint.x << endl;
    cout << "y4 = " << segmentSecond.endPoint.y << endl;
    cout << "Correct point of intersection: x = " << correct.x << ", y = " << correct.y << endl
      << "The resulting point of intersection: x = " << intersection.x << ", "
      << "y = " << intersection.y << endl;
    check = false;
  }


  if (counter == ALL_TESTS_PASSED) {
    cout << "All tests passed successfully!" << endl;
  }
}