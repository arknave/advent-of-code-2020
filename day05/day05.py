from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def main():
    fin = open("day05.in", "r")
    lines = [line.strip() for line in fin.readlines() if line.strip()]
    ans = 0
    s = set()
    for line in lines:
        lo = 0
        hi = 1 << 7
        for c in line[:7]:
            mid = (lo + hi) // 2
            if c == "F":
                hi = mid
            elif c == "B":
                lo = mid

        l2, r2 = 0, 8
        for c in line[7:]:
            mid = (l2 + r2) // 2
            if c == "L":
                r2 = mid
            else:
                l2 = mid

        x = lo * 8 + l2
        ans = max(ans, x)
        s.add(x)

    print(ans)
    print(set(range(1000)) - s)


if __name__ == "__main__":
    main()
