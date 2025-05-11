import math

def parse_input():
    lists = []
    with open('input.txt', 'r') as file:
        for line in file:
            lists.append(list(line[:-1]))
    
    return lists


def part1():
    signal_pos = {}
    mp = parse_input()
    for i in range(len(mp)):
        for j in range(len(mp[i])):
            if mp[i][j] == ".":
                pass
            else:
                if mp[i][j] not in signal_pos:
                    signal_pos[mp[i][j]] = [(i, j)]
                else:
                    signal_pos[mp[i][j]].append((i, j))
    antinodes = set()
    for key in signal_pos.keys():
        for i in range(len(signal_pos[key])):
            for j in range(i+1, len(signal_pos[key])):
                p1 = signal_pos[key][i]
                p2 = signal_pos[key][j]

                mid = ((p1[0]+ p2[0])/2, (p1[1]+ p2[1])/2)

                slope = (p1[0]-p2[0], p1[1]-p2[1])

                a1 = (int(mid[0] + 1.5*slope[0]), int(mid[1]+1.5*slope[1]))
                a2 = (int(mid[0] -1.5*slope[0]), int(mid[1]-1.5*slope[1]))

                if not (a1[0] < 0 or a1[0] >= len(mp) or a1[1] < 0 or a1[1] >= len(mp[0])):
                    if mp[a1[0]][a1[1]] == ".":
                        mp[a1[0]][a1[1]] = "#"
                    antinodes.add(a1)
                if not (a2[0] < 0 or a2[0] >= len(mp) or a2[1] < 0 or a2[1] >= len(mp[0])):
                    if mp[a2[0]][a2[1]] == ".":
                        mp[a2[0]][a2[1]] = "#"
                    antinodes.add(a2)
    return len(antinodes)

def part2():
    signal_pos = {}
    mp = parse_input()
    for i in range(len(mp)):
        for j in range(len(mp[i])):
            if mp[i][j] == ".":
                pass
            else:
                if mp[i][j] not in signal_pos:
                    signal_pos[mp[i][j]] = [(i, j)]
                else:
                    signal_pos[mp[i][j]].append((i, j))
    antinodes = set()
    for key in signal_pos.keys():
        for i in range(len(signal_pos[key])):
            for j in range(i+1, len(signal_pos[key])):
                p1 = signal_pos[key][i]
                p2 = signal_pos[key][j]

                slope = (p1[0]-p2[0], p1[1]-p2[1])

                gcd =  math.gcd(slope[0], slope[1])

                slope = (slope[0]//gcd, slope[1]//gcd)

                x, y = p1

                while True:
                    antinodes.add((x, y))
                    x = x+slope[0]
                    y = y+slope[1]
                    if x < 0 or x >= len(mp) or y < 0 or y >= len(mp[0]):
                        break
                x, y = p1
                while True:
                    antinodes.add((x, y))
                    x = x-slope[0]
                    y = y-slope[1]
                    if x < 0 or x >= len(mp) or y < 0 or y >= len(mp[0]):
                        break
    return len(antinodes)

                
print(part1())
print(part2())

