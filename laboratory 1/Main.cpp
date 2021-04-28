#include <iostream>
#include "Struct.h"
#include "FormattingInput.h"
#include "Beginning.h"
#include "WorkingWithFiles.h"
#include "Input.h"
#include "Solution.h"

enum endOfProgram {
  QUIT = 1,
  CONTINUE
};

using namespace std;

enum choiceInput {
  CHOICE_KEYBOARD = 1,
  CHOICE_TEST,
  CHOICE_FILE
};

enum choosingDesicion {
  PARALL = 1,
  INTERSECT,
  NO_INERSECT
};

int main() {
  Greeting();
  int userChoice = 0;
  int result = 0;
  bool stop;

  do {

    Menu();


    do {
	    userChoice = GetInt();
      Coefficients coefficientsFirstSegment = {0, 0, 0};
      Coefficients coefficientsSecondSegment = {0, 0, 0};
      Segment segmentFirst = {0, 0, 0, 0};
      Segment segmentSecond = {0, 0, 0, 0};
      Point intersection = {0, 0};

      switch (userChoice) {

        case CHOICE_KEYBOARD:
          KeyboardInput(&segmentFirst, &segmentSecond);
          CalculatingCoefficients(&coefficientsFirstSegment, &coefficientsSecondSegment, segmentFirst, segmentSecond);
          result = CallingFunction(coefficientsFirstSegment, coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection);

          if (result == PARALL) {
            cout << "Lines are parallel!" << endl;
          } else if (result == INTERSECT) {

            if (intersection.x == -0) {
              intersection.x = 0;
            }

            if (intersection.y == -0) {
              intersection.y = 0;
            }

            cout << "Point of intersection: " << "x = " << intersection.x << ", "
              << "y = " << intersection.y << endl;
          } else {
            cout << "Line segments don't intersect!" << endl;
          }

          SavingFilesInput(segmentFirst, segmentSecond);
          SavingFilesResult(segmentFirst, segmentSecond, result, intersection);
          stop = true;
          break;

        case CHOICE_FILE:          
          FileInput(&segmentFirst, &segmentSecond);
          CalculatingCoefficients(&coefficientsFirstSegment, &coefficientsSecondSegment, segmentFirst, segmentSecond);
          result = CallingFunction(coefficientsFirstSegment, coefficientsSecondSegment, &segmentFirst, &segmentSecond, &intersection);

          if (result == PARALL) {
            cout << "Lines are parallel!" << endl;
          } else if (result == INTERSECT) {

            if (intersection.x == -0) {
              intersection.x = 0;
            }

            if (intersection.y == -0) {
              intersection.y = 0;
            }

            cout << "Point of intersection: " << "x = " << intersection.x << ", "
              << "y = " << intersection.y << endl;
          } else {
            cout << "Line segments don't intersect!" << endl;
          }    

          SavingFilesResult(segmentFirst, segmentSecond, result, intersection);

          stop = true;
          break;

        case  CHOICE_TEST:
          CheckingTests();
          stop = true;
          break;

        default:
          cout << "There is no such choice!" << endl;
          stop = false;
          Menu();
          break;
      }
      
    } while (stop != true);


    do {
      cout << endl << "Press 1 to finish" << endl;
      cout << "Press 2 to continue" << endl;
      userChoice = GetInt();
      if (userChoice != QUIT && userChoice != CONTINUE) {
        cout << "There is no such choice!" << endl;
      }
    } while (userChoice != QUIT && userChoice != CONTINUE);

  } while (userChoice != QUIT);
    
  return 0;
}