#include <iostream>
#include <string>
#include <fstream>
#include "Struct.h"
#include "FormattingInput.h"

using namespace std;

enum choosingDesicion {
  PARALL = 1,
  INTERSECT,
  NO_INERSECT
};

ofstream OpenFileOutput(void);

void SavingFilesInput(Segment segmentFirst, Segment segmentSecond) {
  cout << endl << "Press 1 if you want to save your input in the file" << endl
    << "Press 2 if you DON'T want to save your input in the file" << endl;
  int choice = GetInt();
  const int SAVING = 1;
  const int NOT_SAVING = 2;

  while (choice != SAVING && choice != NOT_SAVING) {
    cout << "There is no such choice!" << endl
      << "Press 1 if you want to save your input in the file" << endl
      << "Press 2 if you DON'T want to save your input in the file" << endl;

    choice = GetInt();
  }

  if (choice == SAVING) {
    ofstream file = OpenFileOutput();

    file << segmentFirst.startPoint.x << endl;
    file << segmentFirst.startPoint.y << endl;
    file << segmentFirst.endPoint.x << endl;
    file << segmentFirst.endPoint.y << endl;
    file << segmentSecond.startPoint.x << endl;
    file << segmentSecond.startPoint.y << endl;
    file << segmentSecond.endPoint.x << endl;
    file << segmentSecond.endPoint.y << endl;

    file.close();
    cout << "Your input is successfully saved!" << endl;
  } else if (choice == NOT_SAVING) {
  }
}

void SavingFilesResult(Segment segmentFirst, Segment segmentSecond, int result, Point intersection) {

  const int SAVING = 1;
  const int NOT_SAVING = 2;

  cout << endl << "Press 1 if you want to save your result in the file" << endl
    << "Press 2 if you DON'T want to save your result in the file" << endl;
  int choice = GetInt();

  while (choice != SAVING && choice != NOT_SAVING) {
    cout << "There is no such choice!" << endl
      << "Press 1 if you want to save your input in the file" << endl
      << "Press 2 if you DON'T want to save your input in the file" << endl;

    choice = GetInt();
  }

  if (choice == SAVING) {
    ofstream file = OpenFileOutput();

    file << "Points of the first segment:" << endl;
    file << "Point 1:" << endl;
    file << "x1 = " << segmentFirst.startPoint.x << endl;
    file << "y1 = " << segmentFirst.startPoint.y << endl;
    file << "Point 1:" << endl;
    file << "x2 = " << segmentFirst.endPoint.x << endl;
    file << "y2 = " << segmentFirst.endPoint.y << endl;
    file << "Points of the second segment:" << endl;
    file << "Point 1:" << endl;
    file << "x3 = " << segmentSecond.startPoint.x << endl;
    file << "y3 = " << segmentSecond.startPoint.y << endl;
    file << "Point 2:" << endl;
    file << "x4 = " << segmentSecond.endPoint.x << endl;
    file << "y4 = " << segmentSecond.endPoint.y << endl;

    if (result == PARALL) {
      file << "Lines are parallel!" << endl;
    } else if (result == INTERSECT) {
      file << "Point of intersection: " << "x = " << intersection.x << ", "
        << "y = " << intersection.y << endl;
    } else {
      file << "Line segments don't intersect!" << endl;
    }

    file.close();
    cout << "Your result is successfully saved!" << endl;
  }

}
