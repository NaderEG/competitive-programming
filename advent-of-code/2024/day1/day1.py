def parse_input():
    l1 = []
    l2 = []
    with open('input.txt', 'r') as file:
        for line in file:
            x, y = map(float, line.split())
            l1.append(x)
            l2.append(y)

    return l1, l2


def part1():
    l1, l2 = parse_input()

    l1 = sorted(l1)
    l2 = sorted(l2)

    diff = []

    for i in range(len(l1)):
        diff.append(abs(l2[i]-l1[i]))
    return sum(diff)

def part2():
    l1, l2 = parse_input()

    sim = 0

    for i in l1:
        if i in l2:
            sim = sim + i*l2.count(i)
    return sim

print(part1())
print(part2())
