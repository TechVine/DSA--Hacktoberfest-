'''Maximum and minimum of an array.
Find Kth smallest element of the array.
Move all negative numbers to beginning and positive to end with constant extra space.
Sort the given array
Smallest Positive missing number of given array.'''


#4.Sort the given array

n=int(input("Enter size of array\n"))
arr=list(map(int,input("Enter elements of array\n").split()))
arr.sort(reverse=False) #arr.sort() also be used
print("Ascending order array")
print(*arr)
arr.sort(reverse=True)
print("Descending order array")
print(*arr)
