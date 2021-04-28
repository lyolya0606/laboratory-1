#include <iostream>
#include "Struct.h"
#include "FormattingInput.h"

using namespace std;

void KeyboardInput(Segment *segmentFirst, Segment *segmentSecond) {

  do {
    cout << "Input the first line points: " << endl;
    cout << "Point 1: " << endl << "x1 = ";
    (*segmentFirst).startPoint.x = GetDouble();
    cout << "y1 = ";
    (*segmentFirst).startPoint.y = GetDouble();
    cout << "Point 2: " << endl << "x2 = ";
    (*segmentFirst).endPoint.x = GetDouble();
    cout << "y2 = ";
    (*segmentFirst).endPoint.y = GetDouble();

    if ((((*segmentFirst).startPoint.x == (*segmentFirst).endPoint.x) && ((*segmentFirst).startPoint.y == (*segmentFirst).endPoint.y))) {
      cout << "You entered a point. Please, try again." << endl;
    }

  } while (((*segmentFirst).startPoint.x == (*segmentFirst).endPoint.x) && ((*segmentFirst).startPoint.y == (*segmentFirst).endPoint.y));
    

  do {
    cout << "Input the second line points: " << endl;
    cout << "Point 1: " << endl << "x3 = ";
    (*segmentSecond).startPoint.x = GetDouble();
    cout << "y3 = ";
    (*segmentSecond).startPoint.y = GetDouble();
    cout << "Point 2: " << endl << "x4 = ";
    (*segmentSecond).endPoint.x = GetDouble();
    cout << "y4 = ";
    (*segmentSecond).endPoint.y = GetDouble();

    if ((((*segmentSecond).startPoint.x == (*segmentSecond).endPoint.x) && ((*segmentSecond).startPoint.y == (*segmentSecond).endPoint.y))) {
      cout << "You entered a point. Please, try again." << endl;
    }

  } while (((*segmentSecond).startPoint.x == (*segmentSecond).endPoint.x) && ((*segmentSecond).startPoint.y == (*segmentSecond).endPoint.y));

}
