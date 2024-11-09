<h1 align="center">cub3D_42_1337 </h1>
<p align="center">
  <a href="https://github.com/mohimi-coder/cub3D">
    <img src="https://raw.githubusercontent.com/mohimi-coder/1337_badges/refs/heads/master/cub3dm.png" alt="42 Badge">
  </a>
</p>

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
