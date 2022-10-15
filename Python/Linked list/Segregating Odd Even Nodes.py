class Node:
    def __init__(self, val):
        self.val = val
        self.next =None
 
head = None
 
 
def EvenOddSegregation():
    
    global head
    end = head
    prev = None
    curr = head
 
    while (end.next != None):
        end = end.next
    new_end = end
 
    while (curr.val % 2 !=0 and curr != end):
        new_end.next = curr
        curr = curr.next
        new_end.next.next = None
        new_end = new_end.next
         
    if (curr.val % 2 == 0):
         
        head = curr
 
        while (curr != end):
             
            if (curr.val % 2 == 0):
                 
                prev = curr
                curr = curr.next
                 
            else:
                 
                prev.next = curr.next
 
                curr.next = None
 
                new_end.next = curr
 
                new_end = curr
 
                curr = prev.next
             
    else:
        prev = curr
 
    if (new_end != end and end.val % 2 != 0):
         
        prev.next = end.next
        end.next = None
        new_end.next = end

def insert(new_data):
    global head
    new_node = Node(new_data)
    new_node.next = head
    head = new_node
 
def print_list():
    global head
    temp = head
    while(temp != None):
         
        print(temp.val, end = "->")
        temp = temp.next
         
    print("NULL")


insert(7)
insert(5)
insert(12)
insert(61)
insert(14)
insert(22)
insert(9)

print("Actual Linked List is: ")
print_list()
EvenOddSegregation()
print("Linked List after Segregating Even and Odd nodes is: ")
print_list()
 
"""Code is provided by K sanketh Kumar"""
