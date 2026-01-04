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

- **Game**: can be found in [here](renderer/include/game/Game.h). This class is responsible for running the game loop
  and distributing
  tasks and events to the different components of the game.

- **Stopwatch**: can be found in [here](logic/include/core/utils/Stopwatch.h). The different components can access the
  delta time
  between frames using this singleton class.

- **World**: can be found in [here](logic/include/core/world/World.h). This class represents the game world, containing
  all entity models and controllers. It is responsible for the simulation of the game logic.

- **Camera**: can be found in [here](renderer/include/core/utils/Camera.h). This class is responsible for translation
  logic coördinates
  into screen coördinates.

- **Score** : can be found in [here](logic/include/core/world/Score.h). This class is responsible for keeping track of
  the score
  and lives of the player. To keep the different functionalities separated, the Score class is split into ScoreCounter
  and LifeCounter.

- **Random**: the random class can be found in [here](logic/include/core/utils/Random.h). This singleton class is
  responsible for generating
  random numbers for the game and provides an easy-to-use interface that can be accessed from anywhere in the codebase.

## Core Game Requirements

- [ ] Startup screen is implemented in the [MenuState](renderer/include/game/states/MenuState.h) class. This class
 uses [TXTHighScoreParser](logic/include/core/parsers/TXTHighScoreParser.h)
 to load and display the high scores from the highscores.txt file.
- [ ] The maze is stored in the [TileMap](logic/include/core/world/TileMap.h) class, which loads the map from
 resources/maps/map.txt using the [TXTMapParser](renderer/include/game/parsers/TXTMapParser.h) class. Collisions are
 detected in
 the [CollisionHandler](logic/include/core/world/objects/CollisionHandler.h). This class calls the onCollision methods
 of the controllers of the entities.
- [ ] Movement is done
  using a controller based on
  the [MovingEntityController](logic/include/game/entities/controllers/MovingEntityController.h)
  and [MovingEntityModel](logic/include/game/entities/models/MovingEntityModel.h) classes. These classes provide an
  interface for moving through the maze.
- [ ] Ghosts use the
  [GhostController](logic/include/game/entities/controllers/GhostController.h)
  and [GhostModel](logic/include/game/entities/models/GhostModel.h) classes. The GhostController provides general ghost
  functionality. Direction locking is handled here.
  Specific ghost behaviour is implemented in subclasses of the GhostController, such
  as [ManhattanFollowGhostController](logic/src/game/entities/controllers/ManhattanFollowGhostController.cpp).
  These classes use navigation agents like
  the [AStarNavigationAgent](logic/include/game/entities/controllers/navigation/AStarNavigationAgent.h)
  or [ManhattanNavigationAgent](logic/include/game/entities/controllers/navigation/ManhattanNavigationAgent.h).
  The modes of the ghosts are stored in the [GhostModel](logic/include/game/entities/models/GhostModel.h) class.
- [ ] Different objects send WorldEvents to the world and other objects when a fruit/coin is collected, pacman is eaten
  or
  ghost gets killed.
  [World](logic/include/core/world/World.h) distributes these events and also updates
  it [Score](logic/include/core/world/Score.h) observer. Score changes the score and life counters accordingly.
  Score also uses the Stopwatch to implement score multipliers like requested.
  In [LevelState](renderer/include/game/states/LevelState.h) an extra score bonus is added for clearing a level.
- [ ] When ghosts receive the FRUIT_EATEN_BY_PLAYER world event. They switch to frightened mode.
  This is implemented in the [GhostController](logic/include/game/entities/controllers/GhostController.h) class.
  They will use the manhattan navigation agent to maximize the distance to pacman.
- [ ] In the [LevelState](renderer/include/game/states/LevelState.h) class, when all coins are collected, a VictoryState
  is pushed onto the manager stack. Score is passed with and passed to the next LevelState. A bonus score is added and
  the difficulty-multiplier in Score gets increased. Entities use this multiplier to determine their default speeds.
- [ ] The live system is implemented in the [LifeCounter](logic/include/core/world/LifeCounter.h) class. This class is
  part of Score and gets passed the observer events Score receives. This way it is also passed to the next level. Each
  update, LevelState checks if the game has reached game over. If so, it pushes the GameOverState onto the stack.

## Software Design & Code Architecture

- [ ] Each entity has a model, view and controller. The models and controllers are in the logic/include/game/entities,
  while the views are in
  renderer/include/game/entities/views. The controllers are linked to the models and are stored in the World. The views
  are stored and managed in the WorldView.
- [ ] The **MVC pattern** is implemented using [EntityModel](logic/include/core/entity/EntityModel.h),
  [IEntityController](logic/include/core/entity/IEntityController.h)
  and [IEntityView](renderer/include/core/entity/EntityView.h) interfaces. Other models, views and controllers inherit
  from
  these classes.
  The **observer pattern** is implemented in [IObserver](logic/include/core/observer/IObserver.h)
  and [Observable](logic/include/core/observer/Observable.h). These classes use **templates** to easily link an observer
  to an observable. These classes are widely used in the codebase, for example in the World and Score classes, or the
  models and views.
  The **abstract factory pattern** is implemented using
  the [IEntityFactory](logic/include/core/entity/IEntityFactory.h). This factory gets
  implemented by the renderer in [DefaultEntityFactory](renderer/include/game/factories/DefaultEntityFactory.h) and
  injected into the logic.
  The **singleton pattern** is implemented in for example the [Stopwatch](logic/include/core/utils/Stopwatch.h)
  , [Random](logic/include/core/utils/Random.h) and [Game](renderer/include/game/Game.h) classes.
  The **state pattern** is implemented in the [IState](renderer/include/core/states/IState.h)
  and [StateManager](renderer/include/core/states/StateManager.h) classes.
- [ ] The logic is a standalone library without any SFML or renderer dependencies. The CMakeLists.txt is
  located [here](logic/CMakeLists.txt).
  The renderer depends on the logic and can be found [here](renderer/CMakeLists.txt).
- [ ] The camera class can be found in [here](renderer/include/core/utils/Camera.h).
  It is used in the WorldView to translate world coördinates to screen coördinates. Camera
  supports [Positions](logic/include/core/world/space/Position.h) and [Sizes](logic/include/core/world/space/Size.h),
  which is the way logic represents coördinates.
- [ ] The classes are split up as much as possible into smaller classes with a single responsibility.
  For example, the Score class is split into ScoreCounter and LifeCounter classes to separate the score and life logic.
  Another example is the GhostController class, which provides general ghost functionality, while specific ghost
  behaviour is implemented in subclasses.
  This makes the code more maintainable and expandable.
  The [IAppConfig](renderer/include/core/config/IAppConfig.h) interface provides a way to inject custom parsers,
  factories and a TileMap for
  even more configurability. There also are resources for textures and fonts that can be easily swapped out without
  changing the code in renderer/resources/.

## Bonus Features

- [ ] **Generic programming** is used throughout the codebase. For example, the observer pattern is implemented using
 templates in
 the [IObserver](logic/include/core/observer/IObserver.h)
 and [Observable](logic/include/core/observer/Observable.h) classes. This allows for type-safe observers and observables
 without the need for casting. I also make use of **concepts** and the **using** keyword to create more readable and
 maintainable code.
- [ ] The ghosts use **A\*** pathfinding to navigate to their spawn point after being eaten.
  This is implemented in
  the [AStarNavigationAgent](logic/include/game/entities/controllers/navigation/AStarNavigationAgent.h)
  class.

