<h1 align="center">cub3D_42_1337 </h1>
<p align="center">
  <a href="https://github.com/mohimi-coder/cub3D">
    <img src="https://raw.githubusercontent.com/mohimi-coder/1337_badges/refs/heads/master/cub3dm.png" alt="42 Badge">
  </a>
</p>

This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use
of basic algorithms, information research etc.
As a graphic design project, cub3D will enable you to improve your skills in these
areas: windows, colors, events, fill shapes, etc.
To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.
With the help of the numerous documents available on the internet, you will use
mathematics as a tool to create elegant and efficient algorithms

### **Final Score** - 125/100

The project must respect certain constraints :

- Using minilibx
- Display different wall textures for north, south, east and west
- Set colors for the floor and ceiling
- The left and right arrow keys must allows to rotate the perspective
- `WASD` must allow to move the point of view
- `ESC` and the cross on the window's frame must close the program cleanly
- The program take a map only with the `.cub` extension

The map can be freely created by the user, must be closed, and composed by the following characters to be accepted :
- `0` for the ground
- `1` for a wall
- `N` `S` `E` `W` for the spwaning orientation


Here is an example of a valid map provided by the subject, with the path for textures and the RGB colors for the floor and ceiling :

```shell
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Parsing methodology

According to the constraints imposed by the subject, the parsing was carried out in the following way :

![parsing_check](https://user-images.githubusercontent.com/93100775/217233450-89ad0f51-8bbe-48e6-8e9e-41b7f6090c3f.png)

- **Take data** : first pass on the .cub file, for example with a _static variable_, to get the 6 first required data. RGB colors and paths of the images can be placed in an array, and check the validity of each path and colors. In this implementation, the order of declaration of textures or colors does not matter, but must be declared correctly and without gaps or duplication.

- **Turn map into rectangle** : Once the data is retrieved, check the _longest line_ of the map, and enlarge the size of each shorter line with spaces to form a rectangular. This will facilitate the vertical check of the map.

- **Horizontal check** : check for each line if the characters are valid characters `"01NSEW "`. In case of space, check if the character preceding the space is a `1`, and if the next character following the **space string** is a `1` or the end of line. So it is possible to have space holes in a map provided that this hole is surrounded by walls.

- **Vertical check** : The vertical check follows the same logic, constant verification that a wall is present before and after a space string. The combination of the vertical and horizontal check will allow to create any type of map, rounded or with islands, while checking that there is no opening, in example a `0` not surrounded by `1`.

## Definitions / Information:

* **Raycasting** is a rendering technique used to create a 3D perspective within a 2D map.
* **Raycasting** differs from raytracing:
     - **Raycasting** is a quick, semi-3D technique that can run in real-time, even on low-power devices like 4MHz graphical calculators.
     - **Raytracing**, by contrast, is a realistic rendering technique that supports reflections and shadows in true 3D scenes, requiring high processing power to render in real time with high resolution and scene complexity.
* **bresenham_line** - The Bresenham Line algorithm is used to draw lines incrementally on a screen. This algorithm is simple to understand and implement, and it works by interpolating based on the difference between the starting and ending points.
* **Ray Casting Principles**:
   1. Walls maintain a 90° angle with the floor.
   2. Walls are constructed from uniformly sized cubes.
   3. The floor is consistently flat.
* **FOV**(Field of View) - Defines the visible area in front of the player, allowing players to see what's ahead. The player's FOV is determined by the X and Y coordinates, along with the angle they’re facing.
Fisheye Effect - This effect distorts the view by rounding walls when real distances are used, potentially causing discomfort if the player rotates.
## Technical Details:
* bresenham_line handles wall “hits” by calculating ray intersections until contact with a wall is made. This framework allows detection of hit blocks without requiring distance calculations, enabling clearer design.
* bresenham_line can detect block-by-block movement along the ray's path in both x and y coordinates.
* A plane size of 0.66 is often ideal for FPS games.
* Formula: Direction + Plane + Multiplier (-1 to 1)


## Useful Resources Links:
* [Game Wolfenstein 3D](http://users.atw.hu/wolf3d/)
* [MinilibX](https://harm-smits.github.io/42docs/libs/minilibx)
* [Ray casting tutorial demos](https://github.com/permadi-com/ray-cast/tree/master/)
* [Ray Casting tutor](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
* [Trigonometry](https://en.wikipedia.org/wiki/Trigonometry)
* [Lodev - Raycasting](https://lodev.org/cgtutor/raycasting.html)
