// OOP244 Fall 2026 - Seneca Print Desk
// Adapted from code by Fardad Soleimanloo
// Date: 2026-10-15
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
#include <iostream>
#include <fstream>
#include <cstddef>
namespace seneca {
   class Utils {
   public:
      char* alocpy(const char* src) const;
      char* alocpy(char*& dest, const char* src) const;
      char* strcpy(char* dest, const char* src) const;
      char* strcpy(char* dest, const char* src, int limit) const;
      int strlen(const char* text) const;
      bool isspace(char ch) const;
      bool isspace(const char* text) const;
      int getInt() const;
      int getInt(int min, int max) const;
      char* read(char*& dest, std::istream& input) const;
      std::ostream& print(std::ostream& out, const char* text, std::size_t maxlen) const;
      char* makeTicketFileName(char* dest, std::size_t number) const;
      bool readRecord(std::ifstream& file, char* name, double& price) const;
   };
   extern Utils ut;
}
#endif
