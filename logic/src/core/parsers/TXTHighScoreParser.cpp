//
// Created by runes on 28/11/2025.
//

#include <vector>
#include <string>
#include "core/parsers/TXTHighScoreParser.h"
#include <fstream>
#include "core/exceptions/FileNotOpenedException.h"

namespace logic {
    std::vector<int> TXTHighScoreParser::getHighScores(const std::string &file) const {
        std::vector<int> result;
        std::ifstream input{file};
        std::string line;
        if (input.is_open()) {
            int i = 0;
            while (std::getline(input, line) && i < 5) {
                result.push_back(std::stoi(line));
                i++;
            }

            return result;
        }
        throw FileNotOpenedException(file, "TXTHighScoreParser::getHighScores(const std::string &file) const");
    }

    void TXTHighScoreParser::writeHighScores(const std::vector<int> &highScores, const std::string &file) {
        std::ofstream output{file};
        if (output.is_open()) {
            for (auto highscore: highScores) {
                output << std::to_string(highscore) << std::endl;
            }
        } else {
            throw FileNotOpenedException(
                file,
                "TXTHighScoreParser::writeHighScores(const std::vector<int> &highScores, const std::string &file) ");
        }
    }
} // logic