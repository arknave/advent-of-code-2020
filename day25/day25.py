from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

m = 20201227

def calc(s, p):
    ans = 0
    v = 1
    while v != p:
        ans += 1
        v = (s * v) % m

    return ans

def main():
    p1 = int(input())
    p2 = int(input())

    ls1 = calc(7, p1)
    ls2 = calc(7, p2)
    print(ls1, ls2)
    print(pow(p2, ls1, m), pow(p1, ls2, m))

main()
