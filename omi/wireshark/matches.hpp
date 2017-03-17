#ifndef OMI_WIRESHARK_MATCHES_HPP_
#define OMI_WIRESHARK_MATCHES_HPP_

#include <omi/wireshark/match.hpp>

#include <vector>
#include <sstream>

// Matches 

namespace omi { 
namespace wireshark {

struct matches : std::vector<match> {

    // Write vector to file 
    void write(const std::string &file) const {
        // Verify file
        std::ofstream stream(file.c_str());
        if (stream.bad()) {
            throw std::invalid_argument("Invalid matches file: " + file);
        }

        stream << output().rdbuf();
        stream.close();
    }

    // Add matches to stream
    std::stringstream output() const {
        std::stringstream stream;
        for (const auto &match : *this) {
            stream << match << std::endl;
        }

        return stream;
    }
};

// Stream operator
inline std::ostream &operator<<(std::ostream &out, const matches &matches) {
    return out << matches.output().str();
}

} }

#endif