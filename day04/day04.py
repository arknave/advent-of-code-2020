from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

def main():
    fin = open("day04.in", "r")
    lines = [line.strip() for line in fin.readlines()]
    ans = 0
    exps = ["pid", "ecl", "hcl", "hgt", "eyr", "iyr", "byr"]

    s = {}
    bounds = [("byr", 1920, 2002), ("iyr", 2010, 2020), ("eyr", 2020, 2030)]

    for line in lines:
        if not line:
            valid = True
            if not all(x in s for x in exps):
                valid = False
            
            # comment out the next if statement for part 1
            if valid:
                for yr, lo, hi in bounds:
                    valid = valid and lo <= int(s[yr]) <= hi

                if s["hgt"].endswith("cm"):
                    valid = valid and 150 <= int(s["hgt"][:-2]) <= 193
                else:
                    valid = valid and 59 <= int(s["hgt"][:-2]) <= 76

                valid = valid and s["hcl"][0] == "#" and len(s["hcl"]) == 7 and all(c in "abcdef0123456789" for c in s["hcl"][1:])
                valid = valid and s["ecl"] in ("amb", "blu", "brn", "gry", "grn", "hzl", "oth")
                valid = valid and len(s["pid"]) == 9 and all("0" <= c <= "9" for c in s["pid"]):

            ans += valid
            s = {}

        chunks = line.split()
        for c in chunks:
            k, v = c.split(":")
            s[k] = v

    print(ans)


if __name__ == "__main__":
    main()
