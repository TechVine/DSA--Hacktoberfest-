class Stack:
   def __init__(self):
      self.stack = []

   def add(self, dataval):
      
      if dataval not in self.stack:
         self.stack.append(dataval)
         return True
      else:
         return False

   def peek(self):     
	   return self.stack[-1]

AStack = Stack()
AStack.add("Mon")
AStack.add("Tue")
AStack.peek()
print(AStack.peek())
AStack.add("Wed")
AStack.add("Thu")
print(AStack.peek())
