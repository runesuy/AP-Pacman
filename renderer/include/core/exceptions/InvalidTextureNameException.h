//
// Created by runes on 20/11/2025.
//

#ifndef AP_PACMAN_INVALIDTEXTURENAMEEXCEPTION_H
#define AP_PACMAN_INVALIDTEXTURENAMEEXCEPTION_H
#include <string>
#include <stdexcept>

namespace renderer {
    /**
     * Exception thrown when a file cannot be opened.
     */
    class InvalidTextureNameException : public std::invalid_argument {
        std::string name;

    public:
        explicit InvalidTextureNameException(const std::string &name) : name(name), std::invalid_argument(
                                                                            name + " is not a valid texture name."
                                                                        ) {
        };

        [[nodiscard]] std::string getPath() const {
            return name;
        }
    };
} // renderer

#endif //AP_PACMAN_INVALIDTEXTURENAMEEXCEPTION_H
