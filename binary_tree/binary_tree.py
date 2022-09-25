from turtle import right


class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class binary_tree:

    def __init__(self, root):
        self.root = root

    def add_node(self, data):
        if self.root.data > data:
            if self.root.left == None:
                new_node = node(data)
                self.root.left = binary_tree(new_node)
            else:
                self.root.left.add_node(data)
        else:
            if self.root.right == None:
                new_node = node(data)
                self.root.right = binary_tree(new_node)
            else:
                self.root.right.add_node(data)

    def traverse_in_order(self, array):
        if not self.root:
            return
        if self.root.left:
            self.root.left.traverse_in_order(array)
        array.append(self.root.data)
        if self.root.right:
            self.root.right.traverse_in_order(array)
        # return array

    def preorder_traversal(self, array):
        array.append(self.root.data)
        if not self.root:
            return
        if self.root.left:
            self.root.left.preorder_traversal(array)
        if self.root.right:
            self.root.right.preorder_traversal(array)

    def postorder_traversal(self, array):
        if not self.root:
            return
        if self.root.left:
            self.root.left.postorder_traversal(array)
        if self.root.right:
            self.root.right.postorder_traversal(array)
        array.append(self.root.data)


root = node(58)

bt = binary_tree(root)

bt.add_node(2)

bt.add_node(3)
bt.add_node(44)
bt.add_node(3)
bt.add_node(25)
bt.add_node(60)
bt.add_node(7)
bt.add_node(77)
bt.add_node(9)
bt.add_node(10)


in_order = []
pre_order = []
post_order = []
bt.traverse_in_order(in_order)
bt.preorder_traversal(pre_order)
bt.postorder_traversal(post_order)
print(f'in-order:   {in_order}')
print(f'pre-order   {pre_order}')
print(f'post-order: {post_order}')
