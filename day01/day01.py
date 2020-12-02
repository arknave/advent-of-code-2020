from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def main():
    fin = open("day01.in", "r")
    a = [int(line.strip()) for line in fin.readlines() if line.strip()]
    for x in a:
        for y in a:
            for z in a:
                if x + z + y == 2020:
                    print(x*y*z)

if __name__ == "__main__":
    main()
