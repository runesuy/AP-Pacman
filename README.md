# AP Pacman Project

student nr: s0241648

Rune Suy

## CI

CI is done via GitHub Actions inside this repository.

There is a workflow to build the project, and one that builds and uploads the doxygen.

## Doxygen

Doxygen documentation is automatically generated and uploaded to
the [GitHub Pages of this repository](https://runesuy.github.io/AP-Pacman/).

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

An IConfig can be injected to the game to override certain settings, parsers and factories.
For each interface a default implementation is provided.

The following implementations van be overridden and injected:
- **Parsers**: ITextureParser, IConfigParser, IHighScoreParser
- **Factories**: IEntityFactory, IStateFactory, IStateManagerFactory
- **Other**: TileMap

## HighScores

High scores are stored in highscores.txt in the renderer/ directory.

## Mandatory classes

- **Game**: can be found in [here](renderer/include/game/Game.h). This class is responsible for running the game loop and distributing
  tasks and events to the different components of the game.

- **Stopwatch**: can be found in [here](logic/include/core/utils/Stopwatch.h). The different components can access the delta time
  between frames using this singleton class.

- **World**: can be found in [here](logic/include/core/world/World.h). This class represents the game world, containing
  all entity models and controllers. It is responsible for the simulation of the game logic.

- **Camera**: can be found in [here](renderer/include/core/utils/Camera.h). This class is responsible for translation logic coördinates
    into screen coördinates.

- **Score** : can be found in [here](logic/include/core/world/Score.h). This class is responsible for keeping track of the score
  and lives of the player. To keep the different functionalities separated, the Score class is split into ScoreCounter and LifeCounter.

- **Random**: the random class can be found in [here](logic/include/core/utils/Random.h). This singleton class is responsible for generating
  random numbers for the game and provides an easy-to-use interface that can be accessed from anywhere in the codebase.

