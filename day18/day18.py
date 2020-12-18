from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def parse(eqn, is_part_2=False):
    eqn = eqn.replace("(", "( ")
    eqn = eqn.replace(")", " )")

    # accidentally made this right associative, so reverse all the tokens 
    # and flip parens
    tokens = eqn.split()[::-1]
    stk = []
    ops = []
    for token in tokens:
        if token == '(':
            while ops[-1] != ")":
                stk.append(ops.pop())
            ops.pop()
        elif token == "*":
            # handle precedence
            while is_part_2 and ops and ops[-1] == "+":
                stk.append(ops.pop())
            ops.append(token)
        elif token in ")+":
            ops.append(token)
        else:
            stk.append(int(token))

    while ops:
        stk.append(ops.pop())

    cur = []
    for val in stk:
        if val == "+":
            x = cur[-1] + cur[-2]
            cur.pop()
            cur.pop()
            cur.append(x)
        elif val == "*":
            x = cur[-1] * cur[-2]
            cur.pop()
            cur.pop()
            cur.append(x)
        else:
            cur.append(val)

    return cur[0]


def main():
    lines = [line.strip() for line in sys.stdin if line.strip()]
    part1 = 0
    part2 = 0
    for line in lines:
        part1 += parse(line, False)
        part2 += parse(line, True)

    print("part 1", part1)
    print("part 2", part2)

main()
