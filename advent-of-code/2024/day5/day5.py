def parse_input():
    rules = []
    lists = []
    with open('input.txt', 'r', encoding='utf-8') as file:
        for line in file:
            if "|" in line:
                x, y = line.split("|")
                rules.append((int(x), int(y)))

            if "," in line:
                lists.append(list(map(int, line.split(","))))
    
    return rules, lists

def get_depends(rules):
    depends = {}
    for x, y in rules:
        if not depends.get(y):
            depends[y] = set()
        depends[y].add(x)
    return depends


def part1():
    rules, lists = parse_input()

    # list of values that must come before x
    comes_before = get_depends(rules)
    sum = 0
    for list in lists:
        valid = True
        for i in range(len(list)):
            if comes_before[list[i]].intersection(set(list[i+1:])):
                valid = False
        if valid == True:
            sum += list[len(list)//2]
    
    return sum

def get_adjacency(rules):
    adjacency = {}
    for x, y in rules:
        if not adjacency.get(x):
            adjacency[x] = set()
        adjacency[x].add(y)
    return adjacency

def get_starting_set(lst, comes_before):
    res = set()
    for i in lst:
        if not comes_before[i].intersection(set(lst)):
            res.add(i)
    return res


def part2():
    rules, lists = parse_input()
    incoming = get_depends(rules)
    outgoing = get_adjacency(rules)
    sum = 0

    for lst in lists:
        incoming = get_depends(rules)
        outgoing = get_adjacency(rules)

        valid = True
        for i in range(len(lst)):
            if incoming[lst[i]].intersection(set(lst[i+1:])):
                valid = False
        if valid == True:
            continue


        
        L = []
        S = get_starting_set(lst, incoming)
        while S:
            n = S.pop()
            L.append(n)
            for m in outgoing[n].copy().intersection(set(lst)):
                outgoing[n].remove(m)
                incoming[m].remove(n)
                if not incoming[m].intersection(set(lst)):
                    S.add(m)
        sum += L[len(L)//2]
    return sum


            


    

print(part1())
print(part2())
    
