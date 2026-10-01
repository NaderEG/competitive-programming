class Node:
    def __init__(self, open_brackets, closed_brackets, string):
        self.open_brackets = open_brackets
        self.closed_brackets = closed_brackets
        self.string = string
        self.child1 = None
        self.child2 = None

class Tree:
    def __init__(self, root, n):
        self.root = root
        self.n = n


    def generate_children(self, node):
        if self.n == node.open_brackets == node.closed_brackets:
            return

        elif self.n == node.open_brackets and node.closed_brackets < node.open_brackets:
            node.child2 = Node(node.open_brackets, node.closed_brackets+1, node.string+")")
            self.generate_children(node.child2)
        else:
            if node.open_brackets == node.closed_brackets:
                node.child1 = Node(node.open_brackets+1, node.closed_brackets, node.string+"(")
                self.generate_children(node.child1)
            elif node.closed_brackets < node.open_brackets:
                node.child1 = Node(node.open_brackets+1, node.closed_brackets, node.string+"(")
                self.generate_children(node.child1)
                node.child2 = Node(node.open_brackets, node.closed_brackets+1, node.string+")")
                self.generate_children(node.child2)

    def find_leaves(self, root):
        if not (root.child1 or root.child2):
            return [root.string]

        leaves = []

        if root.child1:
            leaves.extend(self.find_leaves(root.child1))
        if root.child2:
            leaves.extend(self.find_leaves(root.child2))

        return leaves


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return []

        tree = Tree(Node(1, 0, "(" ), n)

        tree.generate_children(tree.root)
        return tree.find_leaves(tree.root)



        