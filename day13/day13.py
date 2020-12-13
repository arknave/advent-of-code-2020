from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def euclid(a, b):
    if b == 0:
        return a, 1, 0
    d, y, x = euclid(b, a % b)
    return d, x, y - (a // b) * x

def gcd(a, b):
    d, _, _ = euclid(a, b)
    return d

def crt(p1, p2):
    a, m = p1
    b, n = p2
    if a < 0 or b < 0:
        return (-1, -1)

    d = gcd(m, n)
    if (a - b) % d != 0:
        return (-1, -1)

    g, x, y = euclid(m // d, n // d)
    l = (a - b) // d
    ret_mod = m // d * n
    l %= ret_mod
    ret = b + n * l * y
    ret %= ret_mod

    return (ret, ret_mod)


def main():
    early = int(input())
    avail = input().split(",")

    """
    # Part 1
    avail = [int(x) for x in avail if x != "x"]
    ans = math.inf
    for y in avail:
        x = early
        while x % y != 0:
            x += 1

        print(y, x)
        if x < ans:
            yy = y
            ans = x
    print(ans, ans - early, yy, (ans - early) * yy)
    """

    want = []
    for i, s in enumerate(avail):
        if s == "x":
            continue
        s = int(s)
        if not i:
            want.append((0, s))
        else:
            want.append((s - i, s))

    print(want)
    ans = want[0]
    for p in want[1:]:
        ans = crt(ans, p)
    print(ans)
