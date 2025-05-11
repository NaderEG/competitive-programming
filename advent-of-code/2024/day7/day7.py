def parse_input():
    eqs = []
    with open('input.txt', 'r') as file:
        for line in file:
            output, terms = line.split(":")
            terms = list(map(int, terms.split()))
            output = int(output)

            eqs.append((output, terms))

    return eqs

def is_valid(target, terms):
    results = [terms[0]]
    for term in terms[1:]:
        results2 = []
        for n in results:
            results2.append(term+n)
            results2.append(term*n)
        results = results2

    return (target in results)

def part1():
    eqs = parse_input()
    sum = 0
    for eq in eqs:
        output, terms = eq
        if is_valid(output, terms):
            sum += output
    return sum

def is_valid2(target, terms):
    results = [terms[0]]
    for term in terms[1:]:
        results2 = []
        for n in results:
            results2.append(term+n)
            results2.append(term*n)
            results2.append(int(str(n)+str(term)))
        results = results2

    return (target in results)

def part2():
    eqs = parse_input()
    sum = 0
    for eq in eqs:
        output, terms = eq
        if is_valid2(output, terms):
            sum += output
    return sum

print(part1())
print(part2())
