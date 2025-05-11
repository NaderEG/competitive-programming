class data_block:
    def __init__(self, id, nums):
        self.id = id
        self.nums = nums


def parse_input():
    with open('test_input.txt', 'r') as file:
        for line in file:
            pass
        return line
def part1():
    data = parse_input()
    id = 0
    block = True

    res = []

    for char in data:
        if block:
            res = res + int(char)*[str(id)]
            id+=1
        else:
            res = res + int(char)*["."]
        block = not block
    
    left = 0
    right = len(res)-1
    res = list(res)
    while left < right:
        if res[left] != ".":
            left +=1
        elif res[right] == ".":
            right-=1
        else:
            res[left] = res[right]
            res[right] = "."
    
    checksum = 0
    for i in range(len(res)):
        if res[i] == ".":
            break
        checksum = checksum + i*int(res[i])
    return checksum

def part2():
    data = parse_input()
    id = 0
    block = True

    res = []

    for char in data:
        if block:
            res.append(data_block(str(id), int(char)))
            id+=1
        else:
            res.append(data_block(".", int(char)))
        block = not block

    right = len(res)-1
    left = 0
    while right > 0:
        if res[right].id == ".":
            right-=1
        elif left >= right:
            right-=1
            left = 0
        elif res[left].id == "." and res[left].nums >= res[right].nums:
            rem = res[left].nums - res[right].nums
            res[left] = res[right]
            res[right] = data_block(".", res[left].nums)
            res.insert(left+1, data_block(".", rem))
            right = right-1
            left = 0
        else:
            left +=1
        
        

    
    new_res = []
    for db in res:
        new_res = new_res + [db.id]*db.nums
    
    checksum = 0
    for i in range(len(new_res)):
        if new_res[i] != ".":
            checksum = checksum + i*int(new_res[i])
        
    return checksum
    
        

print(part1())
print(part2())