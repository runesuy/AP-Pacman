//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_FILENOTOPENEDEXCEPTION_H
#define AP_PACMAN_FILENOTOPENEDEXCEPTION_H

#include <stdexcept>

namespace renderer {

    class FileNotOpenedException : public std::runtime_error {
        std::string path;
    public:
        explicit FileNotOpenedException(const std::string& path) : path(path), std::runtime_error(
                "Failed to open file at path: " + path
                ){};

        [[nodiscard]] std::string getPath() const {
            return path;
        }

    };

} // renderer

#endif //AP_PACMAN_FILENOTOPENEDEXCEPTION_H
