// Student task: implement this module using the milestone specification.
#include "Menu.h"
#include "Utils.h"

// Declared here instead of constants.h as it is only used here
#define INDENT_DIMENSIONS_LIMIT 4 

using namespace seneca;

MenuItem::MenuItem(const char *contents, uint indentation, uint chars_per_indent, int enumeration) {
    const int  size                 = ut.strlen(contents);
    const bool has_contents         = size > 0 && size < MenuItemContentsLimit && !ut.isspace(contents);
    const bool within_indent_bounds = indentation <= INDENT_DIMENSIONS_LIMIT && chars_per_indent <= INDENT_DIMENSIONS_LIMIT;

    if (!has_contents || !within_indent_bounds || enumeration > MaximumNumberOfMenuItems) {
        m_contents[0] = 0;
    } else {
        m_enumeration = enumeration;
        m_indentation = indentation;
        m_chars_per_indent = chars_per_indent;
        ut.strcpy(m_contents, contents);
    }
}


MenuItem::operator bool() const {
    return m_contents[0];
}


std::ostream& MenuItem::display(std::ostream& ostr) const {
    const char *trimmed_contents = m_contents;
    char indent[INDENT_DIMENSIONS_LIMIT + 1] = {0};

    if (*this) {
        while (ut.isspace(*trimmed_contents)) trimmed_contents++;

        for (int i = 0; i < m_chars_per_indent; i++) {
            indent[i] = ' ';
        }

        for (int i = 0; i < m_indentation; i++) {
            ostr << indent;
        }

        if (m_enumeration >= 0) {
            ostr.width(2);
            ostr << m_enumeration << "- ";
        }

        ostr << trimmed_contents;
    } else {
        ostr << "??????????";
    }

    return ostr;
}
