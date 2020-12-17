from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def step(state):
    have = set(state)
    new_state = []

    # just uh
    # remove all the w parts for a sol to part 1
    poss = set([(x + dx, y + dy, z + dz, w + dw) for x, y, z, w in state for dx in range(-1, 2) for dy in range(-1, 2) for dz in range(-1, 2) for dw in range(-1, 2)])
    for nx, ny, nz, nw in poss:
        ct = sum((nx + dx, ny + dy, nz + dz, nw + dw) in have for dx in range(-1, 2) for dy in range(-1, 2) for dz in range(-1, 2) for dw in range(-1, 2))
        ct -= (nx, ny, nz, nw) in have
        if ct == 3 or (ct == 2 and (nx, ny, nz, nw) in have):
            new_state.append((nx, ny, nz, nw))

    return new_state


def main():
    grid = [list(line.strip()) for line in sys.stdin if line.strip()]
    state = []
    for i, row in enumerate(grid):
        for j, cell in enumerate(row):
            if cell == '#':
                state.append((i, j, 0, 0))

    for _ in range(6):
        state = step(state)

    print(len(state))

main()
