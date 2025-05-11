def parse_input():
    with open('input.txt', 'r', encoding='utf-8') as file:
        return [list(line.strip()) for line in file]
    

def search_right(arr, i, j):
    if i <= len(arr)-4:
        res = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j]
        return res == "XMAS" or res == "SAMX"

def search_down(arr, i, j): 
    if j <= len(arr[i])-4:
        res = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3]
        return res == "XMAS" or res == "SAMX"

def search_down_left(arr, i, j):
    if i >=3 and j <= len(arr[i])-4:
        res = arr[i][j] + arr[i-1][j+1] + arr[i-2][j+2] + arr[i-3][j+3]
        return res == "XMAS" or res == "SAMX"
    
def search_down_right(arr, i, j):
    if i <= len(arr)-4 and j <= len(arr[i])-4:
        res = arr[i][j] + arr[i+1][j+1] + arr[i+2][j+2] + arr[i+3][j+3]
        return res == "XMAS" or res == "SAMX"


def part1():
    word_search = parse_input()
    count=0

    for i in range(len(word_search)):
        for j in range(len(word_search[i])):
            for fun in [search_down, search_right, search_down_left, search_down_right]:
                if fun(word_search, i, j):
                    count+=1
    return count

def is_x_mas(arr, i, j):
    tl_br = arr[i][j] + arr[i+1][j+1] + arr[i+2][j+2]
    bl_tr = arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j]

    return (tl_br == "SAM" or tl_br == "MAS") and (bl_tr == "SAM" or bl_tr == "MAS")



def part2():
    word_search = parse_input()
    count = 0

    for i in range(len(word_search)-2):
        for j in range(len(word_search[i])-2):
            if is_x_mas(word_search, i, j):
                count+=1
    return count

print(part1())
print(part2())


            