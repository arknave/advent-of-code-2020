from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

moves = {'N': (0, 1), 'E': (1, 0), 'S': (0, -1), 'W': (-1, 0)}

s = "NESW"

def part2():
    lines = [line.strip() for line in sys.stdin if line.strip()]

    x, y = 0, 0
    wx, wy = 10, 1
    f = 1
    for line in lines:
        d = line[0]
        k = int(line[1:])

        if d in moves:
            dx, dy = moves[d]
            wx += k * dx
            wy += k * dy
        else:
            dc = (k // 90)
            dc %= 4
            if d == 'L':
                dc = 4 - dc
            if d in 'LR':
                for _ in range(dc):
                    wx, wy = wy, -wx
            else:
                print("moving", s[f], moves[s[f]])
                x += k * wx
                y += k * wy

        print("x y", x, y, "wx wy", wx, wy)


def main():
    lines = [line.strip() for line in sys.stdin if line.strip()]

    x, y = 0, 0
    f = 1
    for line in lines:
        d = line[0]
        print(line[1:])
        k = int(line[1:])

        if d in moves:
            dx, dy = moves[d]
            x += k * dx
            y += k * dy
        else:
            dc = (k // 90)
            if d == 'L':
                f = (f - dc) % 4
            elif d == 'R':
                f = (f + dc) % 4
            else:
                print("moving", s[f], moves[s[f]])
                dx, dy = moves[s[f]]
                x += k * dx
                y += k * dy

        print(x, y)

    print(x, y, abs(x) + abs(y))


if __name__ == "__main__":
    part2()
