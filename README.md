# Maze-Solver

This C++ program is a simple maze-solving algorithm using recursive backtracking. It attempts to find a path from the starting point to the endpoint in a given maze represented as a 2D character array.

Here's a brief overview of how the program works:

1. The maze is defined as a 2D character array named Labirint, where '#' represents walls, ' ' (space) represents open paths, and '*' represents the path the algorithm takes to solve the maze.

2. The starting point is defined as PunctDeStart, and the endpoint is defined as PunctDeSfarsit.

3. The function Rezolva is a recursive function that tries to find a path from the given coordinates (X, Y) to the endpoint.

4. The recursive algorithm starts by attempting to move in four directions (up, down, left, and right) from the current position. It marks the current position with '*' (path taken) and recursively tries to find a path from the new position.

5. If the algorithm finds the endpoint, it returns true, indicating that a solution has been found.

6. If the algorithm cannot find a path from the current position, it backtracks by marking the current position as a free space (space character) and returns false, indicating that this path does not lead to the endpoint.

7. The main function calls the Rezolva function with the starting coordinates (PunctDeStart.X and PunctDeStart.Y). If a solution is found, it asks the user if they want to display the solution.

Please note that this program assumes that there is only one path from the starting point to the endpoint, and the maze is solvable. If the maze contains loops or is designed in such a way that there is no path to the endpoint, the program will not find a solution.
