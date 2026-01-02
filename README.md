# AP Pacman Project

student nr: s0241648

Rune Suy

## CI
CI is done via GitHub Actions inside this repository.

There is a workflow to build the project, and one that builds and uploads the doxygen.

## Doxygen
Doxygen documentation is automatically generated and uploaded to the [GitHub Pages of this repository](https://runesuy.github.io/AP-Pacman/).

## Running the project
To run the project, SFML needs to be installed on your system.
Set the working directory inside renderer/ .

## Maps
This game supports a custom map format.
It loads the map from resources/maps/map.txt.
More about the map format can be found [here](renderer/resources/maps/MapGuide.md).

## Configuration
The game uses config.json to configure graphics settings.
This file is located in the renderer/ directory.

This file contains a font path for the labels, along with a selection of sprites to be loaded from a given file.

## HighScores
High scores are stored in highscores.txt in the renderer/ directory.
