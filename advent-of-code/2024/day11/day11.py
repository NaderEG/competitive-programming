import math
import copy

def parse_input():
    with open('input.txt', 'r') as file:
        for line in file:

            lst = line.split()
        return lst

def part1():
    stones = parse_input()
    for _ in range(25):
        
        new_stones = []
        for i in range(len(stones)):
            if stones[i] == "0":
                new_stones.append("1")
            elif len(stones[i]) % 2 == 0:
                stone = stones[i]
                stone1, stone2 = stone[:len(stone)//2], stone[len(stone)//2:]
                while len(stone2) > 1 and stone2[0] == "0":
                    stone2 = stone2[1:]
                new_stones.append(stone1)

                new_stones.append(stone2)
            else:
                new_stones.append(str(int(stones[i])*2024))
        stones = new_stones
    return len(new_stones)

def num_digits(n):
    if n > 0:
        digits = int(math.log10(n))+1
    elif n == 0:
        digits = 1
    return digits

def split_num(n):
    n = str(n)
    num1, num2 = n[:len(n)//2], n[len(n)//2:]
    while len(num2) > 1 and num2[0] == "0":
        num2 = num2[1:]

    return int(num1), int(num2)

def add_to_dict(d, n, nums):
    if n in d:
        d[n] += nums
    else:
        d[n] = nums

def rem_from_dict(d, n, nums):
    d[n]-=nums
    if d[n] <= 0:
        d.pop(n)


def part2():
    stones = parse_input()
    d = {}
    for stone in stones:
        if int(stone) in d:
            d[int(stone)] += 1
        else:
            d[int(stone)] = 1
    for c in range(75):
        print("blink: ", c)
        d2 = copy.deepcopy(d)
        for key in d2.keys():
            if key == 0:
                stones = d2[key]
                rem_from_dict(d, key, stones)
                add_to_dict(d, 1, stones)
            elif num_digits(key) % 2 == 0:
                stones = d2[key]
                key1, key2 = split_num(key)
                rem_from_dict(d, key, stones)
                add_to_dict(d, key1, stones)
                add_to_dict(d, key2, stones)
            else:
                stones = d2[key]
                rem_from_dict(d, key, stones)
                add_to_dict(d, key*2024, stones)
    count = 0
    for key in d.keys():
        count+=d[key]
        
    return count

print(part1())
print(part2())