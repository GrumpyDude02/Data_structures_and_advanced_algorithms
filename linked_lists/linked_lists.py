class node:
    def __init__(self, data, next):
        self.data = data
        self.next = next


class linked_list:
    def __init__(self, data):
        head = node(data, None)
        self.head = head

    def print_list(self):
        temp = self.head

        while temp != None:
            print(temp.data)
            temp = temp.next

    def insert(self, index, data):
        if index <= 1:
            new_node = node(data, None)
            new_node.next = self.head
            self.head = new_node
        else:
            new_node = self.head
            for i in range(1, index-1):
                new_node = new_node.next
                if new_node == None:
                    print("no such node")
                    return
            new_node3 = new_node.next
            new_node2 = node(0, None)
            new_node2.next = new_node3
            new_node2.data = data
            new_node.next = new_node2


def print_list(head):
    temp = head
    while temp != None:
        print(temp.data, "\n")
        temp = temp.next


list = linked_list(1)
third_node = node(4, None)
second_node = node(2, third_node)

list.head.next = second_node


list.insert(5, 99)
list.print_list()
