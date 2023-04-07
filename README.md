<h1>
	<p align="center">so_long</p>
	<img align="right" alt="Final Grade: 120/ 100%" src="https://img.shields.io/badge/-%20120%20%2F%20100-success">
</h1>
<p align="center">
	<b><i>And thanks for all the fish!</b></i>
</p>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/WudDoo/so_long">
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/WudDoo/so_long">
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/WudDoo/so_long">
</p>

<table>
<tr>
<td>
	1. <a href="https://github.com/WudDoo/so_long#-about">About</a><br>
	2. <a href="https://github.com/WudDoo/so_long#%EF%B8%8F-installation">Installation</a><br>
	3. <a href="https://github.com/WudDoo/so_long#-running">Running</a><br>
	4. <a href="https://github.com/WudDoo/so_long#-game-rules">Game Rules</a><br>
</td>
</tr>
</table>

## 💡 About

> _This project is a very small 2D game. Its purpose is to make you work with textures, sprites, 
and some other very basic gameplay elements. :)_

	You must create a basic 2D game in which a dolphin escapes Earth after eating some
	fish. Instead of a dolphin, fish, and the Earth, you can use any character, any 
	collectible and any place you want.

I took <b>HEAVY</b> inspiration from Pokemon games that I played as a kid. All sprites were downloaded from <a href="https://www.spriters-resource.com/">Spriters Resource</a> and edited/scaled to meet my requirements.
<br>

#### Games used:
* Pokemon Fire Red/Leaf Green
* Pokemon Emerald
* Pokemon Diamond/Pearl
* Pokemon HeartGold/SoulSilver

#### Requirements
* Linux

<br>

## 🛠️ Installation

### Cloning the repository

```
git clone git@github.com:WudDoo/so_long.git
```

### Installing the mlx library

```
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
cd ..
mv minilibx-linux so_long
```

### Compiling

To compile, run `make` at the root of the `so_long` directory.

<br>

## 🎮 Running

Run the executable file followed by a valid map file, at the root of the `so_long` directory. Example:
```Shell
$ ./so_long maps/map1.ber
```

### Using your own map files

You can run the game with a custom map file as long as it follows the <a href="https://github.com/WudDoo/so_long#-game-rules">Game Rules</a>.

<br>

## 🎮 Game Rules

The executable so_long will receive a map as the only argument, and this map must have a `.ber` filetype.

The file also must follow these rules:

* The only accepted characters are:
	* `P` (player)
	* `1` (wall)
	* `0` (empty)
	* `C` (collectible)
	* `E` (exit)

* The map must be rectangular, i.e. all rows must have the same length
* There must be only one exit and one player, and at least one collectible in the map
* The map must be surrounded by walls
* There must be a valid path the player can take from the starting position, to the exit, collecting all colletibles.

<br>

If any of these checks fail, the game will end with `Error\n` followed by a custom message.

The goal is for the player( to collect all the collectibles on the map before going to an exit in the least possible number of steps
