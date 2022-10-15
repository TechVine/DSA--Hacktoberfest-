# python program for the basic functions of singly linked list

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def createList(self):
        print("Creating Linked List...")
        print("Enter -1 to end")
        num = int(input("Enter the data: "))
        while(num != -1):
            newNode = Node(num)
            if self.head is None:
                self.head = newNode
            else:
                last = self.head
                while last.next:
                    last = last.next
                last.next = newNode
            num = int(input("Enter the data: "))

    def displayList(self):
        if self.head is None:
            print("List is empty")
            return
        print("HEAD", end='')
        temp = self.head
        while temp:
            print(" -> " + str(temp.data), end='')
            temp = temp.next
        print(" -> NULL\n")

    def insertAtFirst(self):
        num = int(input("Enter the data: "))
        newNode = Node(num)
        newNode.next = self.head
        self.head = newNode

    def insertAtLast(self):
        num = int(input("Enter the data: "))
        newNode = Node(num)
        if self.head is None:
            self.head = newNode
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = newNode

    def insertAtAny(self):
        pos = int(input("Enter Position of insertion: "))
        num = int(input("Enter the data: "))
        newNode = Node(num)
        temp = self.head
        i = 1
        while i < pos-1 and temp is not None:
            temp = temp.next
            i += 1
        if temp is None:
            print("Index out of bound")
        else:
            newNode.next = temp.next
            temp.next = newNode

    def deleteFromFirst(self):
        if self.head is None:
            print("List is empty")
            return
        self.head = self.head.next

    def deleteFromLast(self):
        if self.head is None:
            print("List is empty")
            return
        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None

    def deleteFromAny(self):
        if self.head is None:
            print("List is empty")
            return
        pos = int(input("Enter Position of Deletation: "))
        temp = self.head
        i = 1
        while i < pos-1 and temp is not None:
            temp = temp.next
            i += 1
        if temp is None:
            print("Index out of bound")
        else:
            temp.next = temp.next.next


if __name__ == '__main__':
    myList = LinkedList()
    myList.createList()
    print("*** MAIN MENU ***")
    print("1. Insert at First")
    print("2. Insert at Last")
    print("3. Insert at Any")
    print("4. Delete from First")
    print("5. Delete from Last")
    print("6. Delete from Any")
    print("7. Display List")
    print("8. Exit")
    while True:
        option = int(input("Enter Choice: "))
        if option == 1:
            myList.insertAtFirst()
        elif option == 2:
            myList.insertAtLast()
        elif option == 3:
            myList.insertAtAny()
        elif option == 4:
            myList.deleteFromFirst()
        elif option == 5:
            myList.deleteFromLast()
        elif option == 6:
            myList.deleteFromAny()
        elif option == 7:
            myList.displayList()
        elif option == 8:
            break
        else:
            print("Invalid Choice!")

# OUTPUT
# Creating Linked List...
# Enter - 1 to end
# Enter the data: 5
# Enter the data: -1
# *** MAIN MENU ** *
# 1. Insert at First
# 2. Insert at Last
# 3. Insert at Any
# 4. Delete from First
# 5. Delete from Last
# 6. Delete from Any
# 7. Display List
# 8. Exit
# Enter Choice: 1
# Enter the data: 1
# Enter Choice: 2
# Enter the data: 18
# Enter Choice: 3
# Enter Position of insertion: 3
# Enter the data: 9
# Enter Choice: 7
# HEAD -> 1 -> 5 -> 9 -> 18 -> NULL

# Enter Choice: 6
# Enter Position of Deletation: 2
# Enter Choice: 4
# Enter Choice: 5
# Enter Choice: 7
# HEAD -> 9 -> NULL

# Enter Choice: 8
