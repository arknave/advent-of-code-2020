from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

dirs = {"e": (1, 0), "w": (-1, 0), "se": (0, 1), "sw": (-1, 1), "ne": (1, -1), "nw": (0, -1)}

def main():
    state = defaultdict(int)
    for line in sys.stdin:
        line = line.strip()
        i = 0
        x, y = 0, 0
        while i < len(line):
            if line[i] in dirs:
                dx, dy = dirs[line[i]]
                i += 1
            else:
                dx, dy = dirs[line[i:i+2]]
                i += 2
            x, y = x + dx, y + dy
        
        state[(x, y)] ^= 1

    print("part1", sum(v == 1 for v in state.values()))
    for k, v in state.items():
        if v == 1:
            print("Seed", k)

    for _ in range(100):
        opts = set((x + dx, y + dy) for x, y in state.keys() for dx, dy in dirs.values())
        new_state = defaultdict(int)
        for x, y in opts:
            old = state[(x, y)]
            adj = sum(state[x + dx, y + dy] for dx, dy in dirs.values())
            if old == 1 and adj not in [1, 2]:
                new_state[x, y] = 0
            elif old == 0 and adj == 2:
                new_state[x, y] = 1
            else:
                new_state[x, y] = old

        state = new_state
    print("part2", sum(v == 1 for v in state.values()))

    print(state.keys())

main()
