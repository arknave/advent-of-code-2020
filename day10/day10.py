from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def main():
    fin = open("day10.in", "r")
    xs = [int(line.strip()) for line in fin.readlines() if line.strip()]
    xs.sort()
    xs = [0] + xs + [xs[-1] + 3]
    last = 0
    a, b = 0, 0
    for x in xs:
        assert x - last <= 3
        if x - last == 1:
            a += 1
        elif x - last == 3:
            b += 1
        last = x
    print("part 1", a, b, a * b)

    dp = [1]
    for i in range(1, len(xs)):
        ans = 0
        for j in range(i):
            if xs[j] + 3 >= xs[i]:
                ans += dp[j]
        dp.append(ans)

    print("part 2", dp[-1])

if __name__ == "__main__":
    main()
