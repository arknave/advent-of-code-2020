from collections import *
from functools import lru_cache
import re
import heapq
import itertools
import math
import random
import sys

def main():
    lines = [line.strip() for line in sys.stdin]
    x = lines.index("")
    rules = [rule.split(": ") for rule in lines[:x]]
    rules = dict((int(k), v) for k, v in rules)
    data = lines[x+1:]

    # rules[8] = "42 | 42 8"
    # rules[11] = "42 31 | 42 11 31"

    def solve(k, d=0):
        if d > 10:
            return

        if '"' in rules[k]:
            yield rules[k][1:-1]
        else:
            for sub in rules[k].split(" | "):
                for p in itertools.product(*[solve(int(s), d + 1) for s in sub.split()]):
                    yield "".join(p)

    valid = set(solve(0))
    part1 = sum(s in valid for s in data)

    first = set(solve(42))
    second = set(solve(31))
    part2 = 0
    k = [len(x) for x in first][0]
    assert(all(len(x) == k for x in first | second))
    for s in data:
        if len(s) % k != 0:
            continue

        dp1 = [s[i:i+k] in first for i in range(0, len(s), k)]
        dp2 = [s[i:i+k] in second for i in range(0, len(s), k)]

        part2 += any(all(dp1[:i]) and all(dp2[i:]) and i > (len(dp1) - i) for i in range(len(dp1)))

    print("part 1", part1)
    print("part 2", part2)

main()
