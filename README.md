# so_long
> The first 42 Common Core graphic project

</p>
<p align="center">
	<a href="#usage">Usage</a> •
	<a href="#norme">Norme</a>
</p>


Development of a small 2D game in C using the MiniLibX graphics library. In this game the player will control a character that must collect all items before being allowed to leave the stage, all while avoiding enemies and navigating through maze-like levels.

This project introduces concepts such as creating and destroying windows, placing images in a window, handling keypresses, working with sprites and animations.

![So_long Example](https://github.com/MartimPinto/so_long42/assets/128429526/d53fe7cc-1967-4f42-827a-aa54fad9602d)

## Usage
Before compiling the project, it is necessary to download the MLX library which can be found in the [MiniLibX](https://github.com/42Paris/minilibx-linux) repository and follow the guide. The folder with the MLX library must be placed in the `Libs` folder.

### Compilation
This project is divided into two parts: the **mandatory** part (map rendering, player movement, item collection) and the **bonuses** (animations, enemies, move counter). Use `Make` and `Make bonus` to compile the mandatory and bonus parts respectively.

### Running
After compilation, an executable file with the name **so_long** (or **so_long_bonus** for the bonus part) will be created. In order to run the game, call the executable passing the selected map as an argument.

```
$ ./so_long path_to_the_map_file.ber

or

$ ./so_long_bonus path_to_the_map_file.ber
```

## Norme

All 42 projects must be written following the **Norme**. 

