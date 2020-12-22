import sys


def run_round(a, b, part2):
    """Returns true iff player A wins this round"""
    x, y = a[0], b[0]
    if part2 and x < len(a) and y < len(b):
        a, b = run_game(a[1 : x + 1], b[1 : y + 1], part2)
        return bool(a)
    else:
        return x > y


def run_game(p0, p1, part2=False):
    """Returns the hand states after a player has won"""
    seen = set()
    a, b = p0, p1
    while min(len(p) for p in (a, b)) > 0:
        if (a, b) in seen:
            return a, b

        seen.add((a, b))
        if run_round(a, b, part2):
            a, b = (a[1:] + (a[0], b[0]), b[1:])
        else:
            a, b = (a[1:], b[1:] + (b[0], a[0]))

    return a, b


def main():
    players = [p.split("\n")[1:] for p in sys.stdin.read().split("\n\n")]
    players = tuple(tuple(int(x) for x in p if x) for p in players)

    for part2 in [False, True]:
        a, b = run_game(*players, part2=part2)
        ans = a if a else b

        n = len(ans)
        score = sum((n - i) * x for i, x in enumerate(ans))

        print(score)


main()
