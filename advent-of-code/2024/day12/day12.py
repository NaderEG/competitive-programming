from collections import deque as queue

def parse_input():
    lists = []
    with open('input.txt', 'r') as file:
        for line in file:
            lists.append(list(line[:-1]))
    
    return lists


# returns true if the cell we are checking is the same flower type as the current cell
def isValid(pos, next_pos, mp):
    if next_pos[0] < 0 or next_pos[0] >= len(mp) or next_pos[1] < 0 or next_pos[1] >= len(mp[0]):
        return False
    return mp[next_pos[0]][next_pos[1]] == mp[pos[0]][pos[1]]


def get_walks(mp):
    walks = []
    
    for i in range(len(mp)):
        for j in range(len(mp[i])):
            if (i, j) not in {cell for walk in walks for cell in walk}:
                walk = set()
                q = queue()
                q.append((i, j))
                while q:
                    v = q.popleft()
                    if v not in walk:
                        walk.add(v)
                        down = (v[0]+1, v[1])
                        if isValid(v, down, mp):
                            q.append(down)
                        up = (v[0]-1, v[1])
                        if isValid(v, up, mp):
                            q.append(up)
                        right = (v[0], v[1]+1)
                        if isValid(v, right, mp):
                            q.append(right)
                        left = (v[0], v[1]-1)
                        if isValid(v, left, mp):
                            q.append(left)
                walks.append(walk)
    return walks

def part1():
    sums = {}
    garden = parse_input()
    for i in range(len(garden)):
        for j in range(len(garden[i])):
            if garden[i][j] not in sums:
                sums[garden[i][j]] = 0
    
    
    
    walks = get_walks(garden)
    for walk in walks:
        area = 0
        peri = 0
        for step in walk:

            i, j = step
            area +=1
            up, right, left, down = not isValid((i, j), (i-1, j), garden), not isValid((i, j), (i, j+1), garden), not isValid((i, j), (i, j-1), garden), not isValid((i, j), (i+1, j), garden)
            for dir in [up, right, left, down]:
                if dir:
                    peri +=1
        sums[garden[i][j]] += peri*area
    sum = 0
    for key in sums.keys():
        sum += sums[key]
    return sum


def walk_perim(mp, pos):
    i, j = pos
    up, right, left, down = not isValid((i, j), (i-1, j), mp), not isValid((i, j), (i, j+1), mp), not isValid((i, j), (i, j-1), mp), not isValid((i, j), (i+1, j), mp)

    #get Starting direction
    if up: # cant move up
        d = 0 # move left
    elif left: # cant move left
        d = 1 # move down
    elif down: # cant move down
        d = 2 # move right
    elif right: # cant move right
        d = 3 # move up
    else:
        return 0
    dirs = [(0, -1), (1, 0), (0, 1), (-1, 0)]
    sides = 0

    start = (pos, d)

    while True:
        i, j = pos
        if isValid(pos, (i + dirs[(d - 1) % 4][0], j + dirs[(d - 1) % 4][1]), mp):
            d = (d-1) % 4
            pos = (i + dirs[d][0], j + dirs[d][1])
            sides+=1
        elif isValid(pos, (i + dirs[d][0], j + dirs[d][1]), mp):
            pos = (i + dirs[d][0], j + dirs[d][1])
        else:
            d = (d+1) % 4
            sides+=1
        if (pos, d) == start:
            return sides

def explore_side_lenth(i, j, d, mp):
    
        

def part2():
    sums = {}
    garden = parse_input()
    for i in range(len(garden)):
        for j in range(len(garden[i])):
            if garden[i][j] not in sums:
                sums[garden[i][j]] = 0
    
    
    
    walks = get_walks(garden)

    for walk in walks:
        sides = []
        area = 0
        peri = 0
        explored = set()
        for step in walk:

            i, j = step
            area +=1

            possible_dirs = []
            if not isValid((i, j), (i-1, j), garden):
                possible_dirs.append(0)
            if not isValid((i, j), (i, j+1), garden):
                possible_dirs.append(1)
            if not isValid((i, j), (i, j-1), garden):
                possible_dirs.append(2)
            if not isValid((i, j), (i+1, j), garden):
                possible_dirs.append(3)


            for dir in possible_dirs:
                if (i, j, dir) not in explored:
                    explored.add(explore_side_length)
                    sides+=1

                    
                        
        
        sums[garden[i][j]] += len(sides)*area
    sum = 0
    for key in sums.keys():
        sum += sums[key]
    return sum


#print(part1())
print(part2())
                    




            



        