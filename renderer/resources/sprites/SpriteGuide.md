# Changing spite resources

The game allows for easy modification of sprite resources.
Changing a certain sprite can be done by replacing the original spritemap.png file with a new one,
and modifying the config.json file to reflect the changes.

## spritemap.png
The spritemap.png file contains all the sprites used in the game.
There is no rule in the spacing of the sprites in the spritemap, since selection of the actual sprite box is done via coordinates in the config.json file.

## config.json
In the **sprites** section of the config.json file, each in-game is assigned to a rectangle inside the spritemap.png file.
Each sprite entry has the following format:
```json
"sprite_name": {
    "x": <x-coordinate>,
    "y": <y-coordinate>,
    "width": <width>,
    "height": <height>
}
```

All parameters are in pixels, and the (0,0) coordinate is the top-left corner of the spritemap.png file.

Using the texture system of the games renderer, the sprite can be linked to an in-game object and rendered.