from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def main():
    fin = open("day07.in", "r")
    lines = [line.strip() for line in fin.readlines() if line.strip()]
    f = defaultdict(list)
    g = defaultdict(list)

    for line in lines:
        k, vs = line.split(" contain ")
        k = tuple(k.split()[:-1])
        if vs.startswith("no"):
            continue
        f[k] = [(int(v.split()[0]), tuple(v.split()[1:-1])) for v in vs.split(", ")]
        for _, v in f[k]:
            g[v].append(k)

    q = deque([("shiny", "gold")])
    s = set([tuple(q[0])])
    while q:
        u = q.popleft()
        for x in g[u]:
            if x not in s:
                q.append(x)
                s.add(x)

    print("part 1", len(s) - 1)

    @lru_cache()
    def solve(color):
        ans = 1
        for count, subcol in f[color]:
            ans += count * solve(subcol)

        return ans

    print("part 2", solve(("shiny", "gold")) - 1)


if __name__ == "__main__":
    main()
