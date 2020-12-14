from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys


def part1():
    lines = [line.strip() for line in sys.stdin if line.strip()]
    m = defaultdict(int)
    for line in lines:
        a, b = line.split(" = ")
        if a == "mask":
            mask = b
        else:
            a = int(a[4:-1])
            b = int(b)
            v = 0
            for i in range(36):
                c = mask[-i-1]
                if c == '1' or (c == 'X' and (b & (1 << i)) > 0):
                    v |= (1 << i)

            m[a] = v

    print(sum(m.values()))


def part2():
    lines = [line.strip() for line in sys.stdin if line.strip()]
    m = defaultdict(int)
    for line in lines:
        a, b = line.split(" = ")
        if a == "mask":
            mask = b
        else:
            a = int(a[4:-1])
            b = int(b)
            v = 0
            extra = []
            for i in range(36):
                c = mask[-i-1]
                if c == 'X':
                    extra.append(1 << i)
                elif c == '1' or (a & (1 << i)) > 0:
                    v += (1 << i)

            for k in range(len(extra) + 1):
                for c in itertools.combinations(extra, k):
                    s = sum(c)
                    m[v + s] = b

    print(sum(m.values()))


main()
