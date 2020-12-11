from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def h(grid):
    return "".join("".join(row) for row in grid)


def step1(grid):
    nxt = [['.' for _ in row] for row in grid]

    for i, row in enumerate(grid):
        for j, c in enumerate(row):
            ct = Counter(grid[i + dx][j + dy] for dx in range(-1, 2) for dy in range(-1, 2) if 0 <= i + dx < len(grid) and 0 <= j + dy < len(grid[i]) and (dx, dy) != (0, 0))
            if c == 'L' and ct['#'] == 0:
                nxt[i][j] = '#'
            elif c == '#' and ct['#'] >= 4:
                nxt[i][j] = 'L'
            else:
                nxt[i][j] = grid[i][j]
    return nxt


def step2(grid):
    nxt = [['.' for _ in row] for row in grid]
    n,m = len(grid), len(grid[0])

    for i, row in enumerate(grid):
        for j, c in enumerate(row):
            occ = 0
            for dx in range(-1, 2):
                for dy in range(-1, 2):
                    if (dx, dy) == (0, 0):
                        continue

                    nx = i + dx
                    ny = j + dy
                    while 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == '.':
                        nx += dx
                        ny += dy

                    if 0 <= nx < n and 0 <= ny < m:
                        occ += grid[nx][ny] == '#'


            if c == 'L' and occ == 0:
                nxt[i][j] = '#'
            elif c == '#' and occ >= 5:
                nxt[i][j] = 'L'
            else:
                nxt[i][j] = grid[i][j]
    return nxt


def main():
    grid = [list(line.strip()) for line in sys.stdin if line.strip()]

    while True:
        nxt = step2(grid)
        if h(nxt) == h(grid):
            break

        grid = nxt

    print(h(grid).count("#"))


if __name__ == "__main__":
    main()
