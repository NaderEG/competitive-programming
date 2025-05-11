def parse_input():
    lists = []
    with open('input.txt', 'r') as file:
        for line in file:
            lists.append(list(map(float, line.split())))
    return lists

def is_valid(arr):
    flag = True
    if len(arr) < 2:
        return flag

    if arr[0] < arr[1]:
        for i in range(len(arr)-1):
            if arr[i+1] - arr[i] > 3 or arr[i+1] - arr[i] <= 0:
                flag = False
                break

    elif arr[0] > arr[1]:
        for i in range(len(arr)-1):
            if arr[i] - arr[i+1] > 3 or arr[i] - arr[i+1] <= 0:
                flag = False
                break

    else:
        flag = False
    
    return flag

def is_valid_2(arr):
    if is_valid(arr):
        return True
    for i in range(len(arr)):
        if is_valid(arr[:i]+arr[i+1:]):
            return True
    return False
        
    

def part1():
    lists = parse_input()
    count = 0
    for lst in lists:
        if is_valid(lst):
            count+=1
    return count

def part2():
    lists = parse_input()
    count = 0
    for lst in lists:
        if is_valid_2(lst):
            count+=1
    return count

print(part1())
print(part2())
