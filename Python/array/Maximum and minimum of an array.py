# Function to find minimum and maximum position in list
def maxminposition(A, n):
   # inbuilt function to find the position of minimum 
   minposition = A.index(min(A))
   # inbuilt function to find the position of maximum 
   maxposition = A.index(max(A)) 
   print ("The maximum is at position::", maxposition + 1) 
   print ("The minimum is at position::", minposition + 1)
# Driver code
A=list()
n=int(input("Enter the size of the List ::"))
print("Enter the Element ::")
for i in range(int(n)):
   k=int(input(""))
   A.append(k)
maxminposition(A,n)
