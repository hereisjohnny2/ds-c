#ifndef PATH_FINDING_H
#define PATH_FINDING_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
  int x, y;
} Point;

void print_maze(size_t maze_rows, size_t maze_columns, char **maze, int **path);
void maze_solver(size_t maze_rows, size_t maze_columns, char **maze, char wall,
                 bool **seen, Point start, Point end, int **path);

#endif // PATH_FINDING_H
