import sys
from z3 import Optimize, Int, Sum, sat


def find_min_pushes2(targets, buttons):
    opt = Optimize()
    x = [Int(f"x{i}") for i in range(len(buttons))]

    for xi in x:
        opt.add(xi >= 0)

    for i, target in enumerate(targets):
        coef = [int(i in button) for button in buttons]
        opt.add(Sum(xi * c for c, xi in zip(coef, x)) == target)

    opt.minimize(Sum(x))

    if opt.check() == sat:
        m = opt.model()
        return sum(m[xi].as_long() for xi in x)


with open(sys.argv[1], "r") as f:
    lines = list(map(str.strip, f.readlines()))

part2 = 0
for line in lines:
    _, *buttons_s, power_s = line.split()
    buttons = [list(map(int, b.strip("()").split(","))) for b in buttons_s]
    targets = list(map(int, power_s.strip("{}").split(",")))
    part2 += find_min_pushes2(targets, buttons)

print(f"Part 2: {part2}")
