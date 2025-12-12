# How to make custom maps.

## Introduction
This game allows you to create custom maps.
These maps are stored in the `maps/` directory of the game installation.
Maps will be randomly selected from this directory when starting a new game, or when
going to the next level.

## Map Format
Maps are stored in a simple text format.
Each map is represented as a grid of characters, where each character represents a different type of terrain or object.
Here is a list of common characters used in the map files:
- `.` : Coin
- ' ' : Empty space
- `W` : Wall
- `R` : Red Ghost
- 'O' : Orange Ghost
- 'I' : Pink Ghost
- 'B' : Blue Ghost
- `P` : Player start position
- `S` : Ghost spawner (The point the ghosts will respawn when killed)
- `U` : Power-up

Note: the map must be rectangular, meaning all rows must have the same length.

Note: Pacman may not be able to leave the map.

