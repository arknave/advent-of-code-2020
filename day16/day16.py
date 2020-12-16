from collections import *
from functools import lru_cache
import heapq
import itertools
import math
import random
import sys

# Taken from (https://github.com/cheran-senthil/PyRival/blob/master/pyrival/graphs/hopcroft_karp.py)
# Apache License 2.0 (https://github.com/cheran-senthil/PyRival/blob/master/LICENSE)
def hopcroft_karp(graph, n, m):
    """
    Maximum bipartite matching using Hopcroft-Karp algorithm, running in O(|E| sqrt(|V|))
    """
    assert (n == len(graph))
    match1 = [-1] * n
    match2 = [-1] * m

    # Find a greedy match for possible speed up
    for node in range(n):
        for nei in graph[node]:
            if match2[nei] == -1:
                match1[node] = nei
                match2[nei] = node
                break
    while 1:
        bfs = [node for node in range(n) if match1[node] == -1]
        depth = [-1] * n
        for node in bfs:
            depth[node] = 0

        for node in bfs:
            for nei in graph[node]:
                next_node = match2[nei]
                if next_node == -1:
                    break
                if depth[next_node] == -1:
                    depth[next_node] = depth[node] + 1
                    bfs.append(next_node)
            else:
                continue
            break
        else:
            break

        pointer = [len(c) for c in graph]
        dfs = [node for node in range(n) if depth[node] == 0]
        while dfs:
            node = dfs[-1]
            while pointer[node]:
                pointer[node] -= 1
                nei = graph[node][pointer[node]]
                next_node = match2[nei]
                if next_node == -1:
                    # Augmenting path found
                    while nei != -1:
                        node = dfs.pop()
                        match2[nei], match1[node], nei = node, nei, match1[node]
                    break
                elif depth[node] + 1 == depth[next_node]:
                    dfs.append(next_node)
                    break
            else:
                dfs.pop()
    return match1, match2


def main():
    specs, ticket, nearby = sys.stdin.read().strip().split('\n\n')
    ticket = list(map(int, ticket.split('\n')[1].split(",")))

    parsed_specs = []
    for spec in specs.split('\n'):
        f = spec.index(":")
        ranges = spec[f+2:].split(" or ")
        out = []
        for r in ranges:
            a, b = map(int, r.split("-"))
            out.append((a, b))
        parsed_specs.append(out)

    def any_valid(x):
        for r in parsed_specs:
            if any(v[0] <= x <= v[1] for v in r):
                return True
        return False

    could_match = [[True for _ in ticket] for _ in parsed_specs]

    part1 = 0
    all_tickets = []
    for nb in nearby.split('\n')[1:]:
        all_tickets.append(tuple(map(int, nb.split(","))))

        part1 += sum(x for x in all_tickets[-1] if not any_valid(x))
        if any(not any_valid(x) for x in all_tickets[-1]):
            continue

        for i, x in enumerate(all_tickets[-1]):
            for j, r in enumerate(parsed_specs):
                could_match[i][j] &= any(v[0] <= x <= v[1] for v in r)

    n = len(parsed_specs)
    assert n == len(ticket)

    """
    # Network flow solution, maybe educational?
    # Replace matched below with m1 if you want to run this
    graph = [[] for _ in ticket]
    for i, row in enumerate(could_match):
        for j, valid in enumerate(row):
            if valid:
                graph[i].append(j)

    m1, _ = hopcroft_karp(graph, n, n)
    print(list(enumerate(m1)))
    """

    matched = []
    for _ in range(n):
        row_sums = [sum(row) for row in could_match]
        i = row_sums.index(1)
        j = could_match[i].index(True)
        matched.append((i, j))
        could_match[i][j] = False
        for r in range(n):
            could_match[r][j] = False

    print(matched)
    part2 = 1
    for r, c in matched:
        if c < 6:
            part2 *= ticket[r]

    print("Part 1", part1)
    print("Part 2", part2)


main()
