// Student task: implement this module using the milestone specification.
#pragma once
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>

#include "constants.h"

namespace seneca {
    class MenuItem {
        uint m_enumeration;
        uint m_indentation;
        uint m_chars_per_indent;
        char m_contents[MenuItemContentsLimit + 1];

        public:
            MenuItem(const char *contents, uint enumeration, uint indentation, uint chars_per_indent);
            operator bool() const;
            std::ostream& display(std::ostream& ostr = std::cout) const;

            MenuItem(const MenuItem&)            = delete;
            MenuItem& operator=(const MenuItem&) = delete;
    };
}

#endif /* SENECA_MENU_H */