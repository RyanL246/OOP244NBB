// OOP244 Fall 2026 - Seneca Print Desk
// Adapted from code by Fardad Soleimanloo
// Date: 2026-10-15
// C-string helpers adapted from supplied Fardad Soleimanloo Utils.
#include "Utils.h"
#include <limits>
#include <cmath>
#include <cstdio>
using namespace std;
namespace seneca {
   Utils ut;
   int Utils::strlen(const char* s) const {
      int n = 0;
      while (s && s[n]) ++n;
      return n;
   }
   char* Utils::strcpy(char* d, const char* s) const {
      int i = 0;
      while (s && s[i]) { d[i] = s[i]; ++i; }
      d[i] = 0;
      return d;
   }
   char* Utils::strcpy(char* d, const char* s, int n) const {
      int i = 0;
      while (s && s[i] && i < n) { d[i] = s[i]; ++i; }
      d[i] = 0;
      return d;
   }
   char* Utils::alocpy(const char* s) const {
      char* d = nullptr;
      alocpy(d, s);
      return d;
   }
   char* Utils::alocpy(char*& d, const char* s) const {
      char* copy = nullptr;
      if (s) { copy = new char[strlen(s) + 1]; strcpy(copy, s); }
      delete[] d;
      d = copy;
      return d;
   }
   bool Utils::isspace(char c) const {
      return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
   }
   bool Utils::isspace(const char* s) const {
      while (s && isspace(*s)) ++s;
      return !s || !*s;
   }
   // Student task from MS2: implement getInt overloads.
   // From MS3: add read, print, bounded copy and record parsing helpers as needed.
   // From MS4: add ticket filename support.
}
