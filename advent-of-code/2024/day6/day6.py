def parse_input():
    lists = []
    with open('input.txt', 'r') as file:
        for line in file:
            lists.append(list(line[:-1]))
    start_pos = (0, 0)
    for i in range(len(lists)):
        for j in range(len(lists[i])):
            if lists[i][j] == "^":
                start_pos = (i, j)
    return lists, start_pos

def part1():
    maze, start_pos = parse_input()
    dir = [(0, -1), (1, 0), (0, 1), (-1, 0)]
    d = 0

    i, j = start_pos
    pos_hist = set()
    while True:
        pos_hist.add((i, j))

        x, y = dir[d]

        if i+y < 0 or i+y >= len(maze) or j+x < 0 or j+x >= len(maze[i]):
            break

        if maze[i+y][j+x] == "#":
            d = (d+1)%4
        else:
            i = i+y
            j = j+x
    return len(pos_hist)

def causes_loop(obj_pos, starting_pos, maze):
    if starting_pos == obj_pos:
        return False
    

    maze[obj_pos[0]][obj_pos[1]] = "#"
    dir = [(0, -1), (1, 0), (0, 1), (-1, 0)]
    d = 0

    
    pos_dir_hist = {}
    for i in range(len(maze)):
        for j in range(len(maze[i])):
            pos_dir_hist[(i, j)] = set()
    i, j = starting_pos
    while True:
        if d in pos_dir_hist[(i, j)]:
            return True
        pos_dir_hist[(i, j)].add(d)

        x, y = dir[d]

        if i+y < 0 or i+y >= len(maze) or j+x < 0 or j+x >= len(maze[i]):
            return False

        if maze[i+y][j+x] == "#":
            d = (d+1) % 4
        else:
            i = i+y
            j = j+x




def part2():
    maze, start_pos = parse_input()
    count = 0
    for i in range(len(maze)):
        for j in range(len(maze[i])):
            flag = causes_loop((i, j), start_pos, [row[:] for row in maze])
            if flag:
                count+=1
    return count


print(part1())
print(part2())