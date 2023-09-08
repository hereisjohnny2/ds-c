#include "path_finding.h"

#include <stdio.h>
#include <stdlib.h>

Point directions[] = {
    {.x = -1, .y = 0},
    {.x = 1, .y = 0},
    {.x = 0, .y = -1},
    {.x = 0, .y = 1},
};

void print_maze(size_t maze_rows, size_t maze_columns, char **maze, int **path) {
  for (int i = 0; i < maze_rows; i++) {
    for (int j = 0; j < maze_columns; j++) {
      printf("%c", path[i][j] == 1 ? '1' : maze[i][j]);
    }
    printf("\n");
  }
}

bool walk(size_t maze_rows, size_t maze_columns, char **maze, char wall,
          bool **seen, Point curr, Point end, int **path) {
  // 1. Off the map
  if (curr.x < 0 || curr.x >= maze_columns || curr.y < 0 ||
      curr.y >= maze_rows) {
    return false;
  }
  
  // 2. Hit a wall
  if (maze[curr.y][curr.x] == wall) {
    return false;
  }

  // 3. End point found
  if (curr.x == end.x && curr.y == end.y) {
    path[curr.y][curr.x] = 1;
    return true;
  }

  // 4. Have already seen
  if (seen[curr.y][curr.x]) {
    return false;
  }


  // Pre
  seen[curr.y][curr.x] = true;
  path[curr.y][curr.x] = 1;
  // Recurse
  for (int i = 0; i < 4; i++) {
    Point new_curr = {
        .x = directions[i].x + curr.x,
        .y = directions[i].y + curr.y,
    };
    if (walk(maze_rows, maze_columns, maze, wall, seen, new_curr, end, path)) {
      return true;
    }
  }
  // Pos
  path[curr.y][curr.x] = 0;

  return false;
}

void maze_solver(size_t maze_rows, size_t maze_columns, char **maze, char wall,
                 bool **seen, Point start, Point end, int **path) {
  walk(maze_rows, maze_columns, maze, wall, seen, start, end, path);
}

