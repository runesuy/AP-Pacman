//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_FILENOTOPENEDEXCEPTION_H
#define AP_PACMAN_FILENOTOPENEDEXCEPTION_H

#include <stdexcept>
#include <iostream>

namespace logic
{
    /**
     * Exception thrown when a file cannot be opened.
     */
    class FileNotOpenedException : public std::runtime_error
    {
        std::string path;

    public:
        explicit FileNotOpenedException(const std::string& path, const std::string& where) : path(path),
            std::runtime_error(
                "Failed to open file at path: " + path
            )
        {
            std::cerr << "At " << where << ": " << std::endl;
        };

        /**
         * @return The path to the file that could not be opened.
         */
        [[nodiscard]] std::string getPath() const
        {
            return path;
        }
    };
} // renderer

#endif //AP_PACMAN_FILENOTOPENEDEXCEPTION_H
