// OOP244 Fall 2026 - Seneca Print Desk
// Adapted from code by Fardad Soleimanloo
// Date: 2026-10-15
/***********************************************************************
// OOP244 Project, milestone 56 : tester program
//
// File  ms56.cpp
// Version 1.0
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Menu.h"
#include "PrintDesk.h"
using namespace std;
using namespace seneca;
int main() {
   cout << "Testing an invalid PrintDesk when a data file contains malformed data." << endl;
   PrintDesk badord("prints.csv", "badfinishes.csv");
   if (badord) {
      cout << "The print desk should have been invalid" << endl;
   }
   else {
      cout << "Passed!" << endl;
   }
   PrintDesk ord("prints.csv", "finishes.csv");
   cout << "Testing input validation..............................." << endl;
   ord.addPrint();
   return 0;
}
