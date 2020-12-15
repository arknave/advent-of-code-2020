from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def main():
    a = [0, 3, 6]
    a = list(map(int, input().split(",")))
    occ = defaultdict(list)
    for i, x in enumerate(a):
        occ[x].append(i)

    while len(a) != 30000000:
    #while len(a) != 2020:
        v = a[-1]
        l = occ[v]
        if len(l) <= 1:
            a.append(0)
        else:
            d = occ[v][-1] - occ[v][-2]
            a.append(d)

        occ[a[-1]].append(len(a) - 1)

    print(a[-1])


main()
