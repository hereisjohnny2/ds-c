#ifndef PATH_FINDING_H
#define PATH_FINDING_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
  int x, y;
} Point;

void print_maze(size_t maze_rows, size_t maze_columns, char **maze,
                bool **path);
bool **maze_solver(size_t maze_rows, size_t maze_columns, char **maze, char wall,
                 Point start, Point end);

#endif // PATH_FINDING_H
