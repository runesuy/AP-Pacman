//
// Created by runes on 28/11/2025.
//

#include <vector>
#include <string>
#include "core/parsers/TXTHighScoreParser.h"
#include <fstream>
#include "core/exceptions/FileNotOpenedException.h"

namespace logic
{
    std::vector<int> TXTHighScoreParser::getHighScores(const std::string& file) const
    {
        std::ifstream input{file};

        if (!input.is_open())
        {
            // create the file if it does not exist
            std::ofstream output{file};
            output.close();
        }
        input.close();
        input.open(file);
        if (input.is_open())
        {
            std::string line;
            std::vector<int> result;
            int i = 0;
            while (std::getline(input, line) && i < 5)
            {
                result.push_back(std::stoi(line));
                i++;
            }
            while (result.size() < 5)
            {
                result.push_back(0);
            }

            return result;
        }
        throw FileNotOpenedException(
            file,
            "TXTHighScoreParser::getHighScores(const std::string &file) const ");
    }

    void TXTHighScoreParser::writeHighScores(const std::vector<int>& highScores, const std::string& file)
    {
        std::ofstream output{file};
        if (output.is_open())
        {
            for (auto highscore : highScores)
            {
                output << std::to_string(highscore) << std::endl;
            }
        }
        else
        {
            throw FileNotOpenedException(
                file,
                "TXTHighScoreParser::writeHighScores(const std::vector<int> &highScores, const std::string &file) ");
        }
    }
} // logic
