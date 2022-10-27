# create class for stack
class Stack1:

	# create empty list
	def __init__(self):
		self.Elements = []
		
	# push() for insert an element
	def push(self, value):
		self.Elements.append(value)
	
	# pop() for remove an element
	def pop(self):
		return self.Elements.pop()
	
	# empty() check the stack is empty of not
	def empty(self):
		return self.Elements == []
	
	# show() display stack
	def show(self):
		for value in reversed(self.Elements):
			print(value)

# Insert_Bottom() insert value at bottom
def BottomInsert(s, value):

	# check the stack is empty or not
	if s.empty():
		
		# if stack is empty then call
		# push() method.
		s.push(value)
		
	# if stack is not empty then execute
	# else block
	else:
		popped = s.pop()
		BottomInsert(s, value)
		s.push(popped)

# Reverse() reverse the stack
def Reverse(s):
	if s.empty():
		pass
	else:
		popped = s.pop()
		Reverse(s)
		BottomInsert(s, popped)


# create object of stack class
stk0 = Stack1()

stk0.push(1)
stk0.push(2)
stk0.push(3)
stk0.push(4)
stk0.push(5)

print("The Original Stack is")
stk0.show()

print("\nStack after Reversing it -")
Reverse(stk0)
stk0.show()
