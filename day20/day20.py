from collections import *
from functools import lru_cache
import re
import heapq
import itertools
import math
import random
import sys

def rot(g):
    g = list(list(r) for r in g)
    n = len(g)
    assert(n == len(g[0]))
    out = [[None for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            out[i][j] = g[n - j - 1][i]

    return tuple(''.join(row) for row in out)

def flip(g):
    g = list(list(r) for r in g)
    n = len(g)
    assert(n == len(g[0]))
    out = [[None for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            out[i][j] = g[j][i]

    return tuple(''.join(row) for row in out)

def place(mat, i, j, block):
    n = len(block)
    for x in range(n):
        for y in range(n):
            mat[i + x][j + y] = block[x][y]

def main():
    data = sys.stdin.read().split("\n\n")
    tiles = []
    for tile in data:
        lines = tile.strip().split('\n')
        tile_id = int(lines[0][-5:-1])
        grid = tuple(lines[1:])
        all_rots = []
        for _ in range(2):
            for _ in range(4):
                all_rots.append(grid)
                grid = rot(grid)
            grid = flip(grid)

        tiles.append((tile_id, all_rots))

    N = int(math.sqrt(len(tiles)))
    K = len(tiles[0][1][0])
    print(N, K, len(tiles))
    stitched = [[None for _ in range(N * K)] for _ in range(N * K)]
    ids = [[-1 for _ in range(N)] for _ in range(N)]
    placed = set()

    def dfs(r, c):
        if c == N:
            return dfs(r + 1, 0)
        if r == N:
            return True

        valid = False
        for tile_id, opts in tiles:
            if tile_id in placed:
                continue

            placed.add(tile_id)
            ids[r][c] = tile_id
            for idx, opt in enumerate(opts):
                place(stitched, K * r, K * c, opt)
                can_place = True
                # some of these str joins are probably no-ops but I've been burned too many times now to check
                if r > 0:
                    top = "".join(opt[0])
                    before = "".join(stitched[K * r - 1][K*c:K*c+K])
                    can_place &= top == before
                    # print("top fail", top, before)
                if c > 0:
                    left = "".join(row[0] for row in opt)
                    before = "".join(stitched[row][K * c - 1] for row in range(K * r, K * r + K))
                    can_place &= left == before
                    # print("left fail", left, before)
                if can_place and dfs(r, c + 1):
                    return True

            placed.remove(tile_id)
            ids[r][c] = -1

        return False
    dfs(0, 0)
    print("part1", ids[0][0] * ids[-1][0] * ids[0][-1] * ids[-1][-1])
    out = [[]]
    for i in range(N * K):
        for j in range(N * K):
            if i % K in (0, K - 1) or j % K in (0, K - 1):
                continue
            if len(out[-1]) == N * (K - 2):
                out[-1] = "".join(out[-1])
                out.append([])
            out[-1].append(stitched[i][j])

    out[-1] = "".join(out[-1])
    # forgive my sins
    monster = [(0, 18)] + [(1, 0), (1, 5), (1, 6), (1, 11), (1, 12), (1, 17), (1, 18), (1, 19)] + [(2, 1), (2, 4), (2, 7), (2, 10), (2, 13), (2, 16)]
    ans = 0
    for _ in range(2):
        for _ in range(4):
            monster_count = 0
            for i in range(len(out) - 2):
                for j in range(len(out[0]) - 19):
                    if all(out[i + dx][j + dy] == '#' for dx, dy in monster):
                        monster_count += 1
            ans = max(ans, monster_count)
            out = rot(out)
        out = flip(out)

    print("part2", "".join(out).count("#") - ans * len(monster))

main()
