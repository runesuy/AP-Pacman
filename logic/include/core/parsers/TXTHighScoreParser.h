//
// Created by runes on 28/11/2025.
//

#ifndef AP_PACMAN_TXTHIGHSCOREPARSER_H
#define AP_PACMAN_TXTHIGHSCOREPARSER_H
#include "IHighScoreParser.h"

namespace logic
{
    /**
     * Default implementation of IHighScoreParser.
     * Parses high scores from a TXT file.
     */
    class TXTHighScoreParser : public IHighScoreParser
    {
    public:
        [[nodiscard]] std::vector<int> getHighScores(const std::string& file) const override;

        void writeHighScores(const std::vector<int>& highScores, const std::string& file) override;
    };
} // logic

#endif //AP_PACMAN_TXTHIGHSCOREPARSER_H
