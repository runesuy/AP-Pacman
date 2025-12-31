//
// Created by runes on 28/11/2025.
//

#ifndef AP_PACMAN_IHIGHSCOREPARSER_H
#define AP_PACMAN_IHIGHSCOREPARSER_H

namespace logic
{
    /**
     * Parser for reading and writing high scores to a file.
     */
    class IHighScoreParser
    {
    public:
        virtual ~IHighScoreParser() = default;

        [[nodiscard]] virtual std::vector<int> getHighScores(const std::string& file) const =0;

        virtual void writeHighScores(const std::vector<int>& highScores, const std::string& file) =0;
    };
} // logic

#endif //AP_PACMAN_IHIGHSCOREPARSER_H
