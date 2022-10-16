#Author = Chirag
#Topic: Python program to find Maximum and Minimum element in an array

#input array
arr = [30,20,15,40,10]

#finding max element.
max=arr[0]
n=len(arr)
for i in range(1,n):
    if arr[i]>max:
      max=arr[i]
print("Maximum element is: ", max)
#Finding min element

min=arr[0]
n=len(arr)

for i in range(1,n):
  if arr[i]<min:
    min=arr[i]
print("Minimum element is: ",min)
#Output
#Maximum element is: 40
#Minimum element is: 10
