class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        stack = []
        zipped_lists = list(zip(position, speed))
        cars = sorted(zipped_lists, key=lambda x: x[0], reverse = True)

        for car in cars:
            if not stack:
                stack.append(car)
            else:
                if (target-car[0])/car[1] > (target-stack[-1][0])/stack[-1][1]:
                    stack.append(car)
        return len(stack)