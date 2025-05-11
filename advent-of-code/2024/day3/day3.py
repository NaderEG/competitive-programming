import re

def parse_input():
    with open('input.txt', 'r', encoding='utf-8') as file:
        file_content = file.read()
    return file_content

def part1():
    text = parse_input()
    ex = r'mul\(\d{1,3},\d{1,3}\)'
    expr = re.findall(ex, text)
    sum = 0
    for exp in expr:
        nums = exp[4:-1]
        num1, num2 = nums.split(",")
        sum += int(num1)*int(num2)
    return sum

def part2():
    text = parse_input()
    ex = r'mul\(\d{1,3},\d{1,3}\)|do\(\)|don\'t\(\)'
    expr = re.findall(ex, text)
    sum = 0
    enabled = True
    for exp in expr:
        if exp == "do()":
            enabled = True
        elif exp == "don\'t()":
            enabled = False
        else:
            nums = exp[4:-1]
            num1, num2 = nums.split(",")
            if enabled:
                sum += int(num1)*int(num2)
    return sum

print(part1())
print(part2())