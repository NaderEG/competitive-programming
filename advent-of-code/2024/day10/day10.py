from collections import deque as queue

def parse_input():
    lists = []
    with open('input.txt', 'r') as file:
        for line in file:
            lists.append(list(line[:-1]))
    
    return lists

def isValid(pos, next_pos, mp):
    if next_pos[0] < 0 or next_pos[0] >= len(mp) or next_pos[1] < 0 or next_pos[1] >= len(mp[0]):
        return False
    return mp[next_pos[0]][next_pos[1]] - mp[pos[0]][pos[1]] == 1

def count_peaks(root, mp):
    explored = set(root)
    q = queue()
    q.append(root)
    peaks = []

    while q:
        v = q.popleft()
        if mp[v[0]][v[1]] == 9:
            peaks.append(v)
        down = (v[0]+1, v[1])
        if isValid(v, down, mp):
            explored.add(down)
            q.append(down)
        up = (v[0]-1, v[1])
        if isValid(v, up, mp):
            explored.add(up)
            q.append(up)
        right = (v[0], v[1]+1)
        if isValid(v, right, mp):
            explored.add(right)
            q.append(right)
        left = (v[0], v[1]-1)
        if isValid(v, left, mp):
            explored.add(left)
            q.append(left)
    return peaks


    



def part1():
    mp = parse_input()

    trailheads = []
    for i in range(len(mp)):
        for j in range(len(mp[i])):
            mp[i][j] = int(mp[i][j])
            if mp[i][j] == 0:
                trailheads.append((i, j))
    

    sum = 0
    for trailhead in trailheads:
        sum+= len(set(count_peaks(trailhead, mp)))
    return sum

def part2():
    mp = parse_input()

    trailheads = []
    for i in range(len(mp)):
        for j in range(len(mp[i])):
            mp[i][j] = int(mp[i][j])
            if mp[i][j] == 0:
                trailheads.append((i, j))
    

    sum = 0
    for trailhead in trailheads:
        sum+= len(count_peaks(trailhead, mp))
    return sum

print(part1())
print(part2())