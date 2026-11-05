// Student task: implement this module using the milestone specification.
#include "Menu.h"
#include "Utils.h"

using namespace seneca;

MenuItem::MenuItem(const char *contents, uint indentation, uint chars_per_indent, uint enumeration) {
    if (ut.isspace(contents) || ut.strlen(contents) > MenuItemContentsLimit || enumeration > MaximumNumberOfMenuItems) {
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
    const char *trimmed_contents, *enumeration_suffix;
    char indent[m_chars_per_indent + 1];

    if (*this) {
        enumeration_suffix = (m_enumeration < 0) ? " " : "- ";

        for (trimmed_contents = m_contents; ut.isspace(*trimmed_contents); trimmed_contents++);

        for (int i = 0; i < m_chars_per_indent; i++) {
            indent[i] = ' ';
        }

        indent[m_chars_per_indent] = '\0';

        for (int i = 0; i < m_indentation; i++) {
            ostr << indent;
        }

        ostr.width(2);
        ostr << m_enumeration << enumeration_suffix << trimmed_contents;
    } else {
        ostr << "??????????";
    }

    return ostr;
}
