#include <iostream>
#include <string>
#include <fstream>
#include "Struct.h"

using namespace std;

ifstream OpenFileInput(void);

void FileInput(Segment *segmentFirst, Segment *segmentSecond) {
  string path;
  string line;
  bool stop;
  ifstream file(path);
  do {

    do {
      file = OpenFileInput();

      try {
        getline(file, line);
        (*segmentFirst).startPoint.x = stod(line);
        getline(file, line);
        (*segmentFirst).startPoint.y = stod(line);
        getline(file, line);
        (*segmentFirst).endPoint.x = stod(line);
        getline(file, line);
        (*segmentFirst).endPoint.y = stod(line);
        getline(file, line);
        (*segmentSecond).startPoint.x = stod(line);
        getline(file, line);
        (*segmentSecond).startPoint.y = stod(line);
        getline(file, line);
        (*segmentSecond).endPoint.x = stod(line);
        getline(file, line);
        (*segmentSecond).endPoint.y = stod(line);
        stop = true;
      }
      catch (invalid_argument coordinates) {
        cout << "Incorrect data in the file! Try again." << endl;
        stop = false;
      }

    } while (stop == false);

    cout << "Read data:" << endl;
    cout << "Points of the first segment:" << endl;
    cout << "Point 1: " << endl << "x1 = " << (*segmentFirst).startPoint.x << endl;
    cout << "y1 = " << (*segmentFirst).startPoint.y << endl;;
    cout << "Point 2: " << endl << "x2 = " << (*segmentFirst).endPoint.x << endl;
    cout << "y2 = " << (*segmentFirst).endPoint.y << endl;
    cout << "Points of the second segment:" << endl;
    cout << "Point 1: " << endl << "x3 = " << (*segmentSecond).startPoint.x << endl;
    cout << "y3 = " << (*segmentSecond).startPoint.y << endl;
    cout << "Point 2: " << endl << "x4 = " << (*segmentSecond).endPoint.x << endl;
    cout << "y4 = " << (*segmentSecond).endPoint.y << endl;

    if ((((*segmentFirst).startPoint.x == (*segmentFirst).endPoint.x) && ((*segmentFirst).startPoint.y == (*segmentFirst).endPoint.y))
      || ((*segmentSecond).startPoint.x == (*segmentSecond).endPoint.x) && ((*segmentSecond).startPoint.y == (*segmentSecond).endPoint.y)) {
      cout << "It is a point. Try again." << endl;
    }

  } while ((((*segmentFirst).startPoint.x == (*segmentFirst).endPoint.x) && ((*segmentFirst).startPoint.y == (*segmentFirst).endPoint.y))
    || ((*segmentSecond).startPoint.x == (*segmentSecond).endPoint.x) && ((*segmentSecond).startPoint.y == (*segmentSecond).endPoint.y));

  
}