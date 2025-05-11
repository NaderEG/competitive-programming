def binary_search(arr, element):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid][1] == element:
            return arr[mid][0]
        elif arr[mid][1] < element:
            low = mid + 1
        else:
            high = mid - 1
    if high < 0:
        return ""
    return arr[high][0]

class TimeMap:

    def __init__(self):
        self.my_dict = dict()

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.my_dict:
            self.my_dict[key].append([value, timestamp])
        else:
            self.my_dict[key] = [[value, timestamp]]

    def get(self, key: str, timestamp: int) -> str:
        if key in self.my_dict:
            if timestamp < self.my_dict[key][0][1]:
                return ""
            return binary_search(self.my_dict[key], timestamp)
        else:
            return ""
