// Student task: implement this module using the milestone specification.
#include "Menu.h"
#include "Utils.h"

using namespace seneca;

MenuItem::MenuItem(const char *contents, uint enumeration, uint indentation, uint chars_per_indent) {
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

}
