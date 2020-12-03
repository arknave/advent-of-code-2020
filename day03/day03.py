from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def main():
    fin = open("day03.in", "r")
    lines = [line.strip() for line in fin.readlines() if line.strip()]

    n, m = len(lines), len(lines[0])
    moves = [(1, 3), (1, 1), (1, 5), (1, 7), (2, 1)]
    ans = 1
    for dx, dy in moves:
        x, y = 0, 0
        cur = 0
        while x < n:
            cur += lines[x][y] == '#'
            x += dx
            y += dy
            y %= m

        ans *= cur
        # uncomment the following line for part 1 solution
        # break 

    print(ans)

if __name__ == "__main__":
    main()
