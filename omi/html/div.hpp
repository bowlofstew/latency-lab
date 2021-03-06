#ifndef OMI_HTML_DIV_ELEMENT_HPP_
#define OMI_HTML_DIV_ELEMENT_HPP_

#include <omi/html/elements.hpp>

#include <string>

// Html div element 

namespace omi {
namespace html {

struct div : html::element {

    explicit div(const std::string &id, indent whitespace = indent::none)
     : element{"div", attribute{ "id", id }, whitespace} {}
};

// Stream operator (prints div element)
inline std::ostream &operator<<(std::ostream &out, const div &div) {
    return out << static_cast<html::element>(div);
}

} }

#endif