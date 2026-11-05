// OOP244 Fall 2026 - Seneca Print Desk
// Adapted from code by Fardad Soleimanloo
// Date: 2026-10-15
#pragma once
#ifndef SENECA_CONSTANTS_H
#define SENECA_CONSTANTS_H

#include <cstddef>

namespace seneca {
   /// Cited from Claude:
   /// "uint isn’t standard C++. Some Linux headers happen to define it, which is why it may compile on one machine and fail on another. 
   ///  Use unsigned int, or make sure your project defines it (e.g., using uint = unsigned int;) somewhere this header includes."
   using uint = unsigned int;

   const std::size_t MaximumNumberOfMenuItems = 20;
   const std::size_t MaximumNumberOfTicketItems = 20;
   const std::size_t MenuItemContentsLimit = 40;
   const double Tax = 0.13;
}

#endif /* SENECA_CONSTANTS_H */