# creating an empty array
arr = []
  
# number of elements as input in the array
n = int(input("Enter total number of elements you want in ayrray: "))
for i in range(0, n):
    print("Enter the", i, "element of the array:-",end='')
    ele = int(input())
    arr.append(ele) 

print("The array is:-",arr)        #printing the array created .
temp =0;    
     
#Displaying elements of original array    
print("Elements of original array: ");    
for i in range(0, len(arr)):    
    print(arr[i], end=" ");    
     
#Sort the array in ascending order    
for i in range(0, len(arr)):    
    for j in range(i+1, len(arr)):    
        if(arr[i] > arr[j]):    
            temp = arr[i];    
            arr[i] = arr[j];    
            arr[j] = temp;    
     
print();    
     
#Displaying elements of the array after sorting    
    
print("Elements of array sorted in ascending order: ");    
for i in range(0, len(arr)):    
    print(arr[i], end=" ");  