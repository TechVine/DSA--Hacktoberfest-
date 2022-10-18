# Insertion Sort Using Python


def insertion_sort(array):
    for step in range(1, len(array)):
        key = array[step]
        j = step - 1
    
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1
        
        array[j + 1] = key
       
array= [9,3,5,1,4,6,8,0,2,7]
print("The Array Before Sorting: ")
print(array)
insertion_sort(array)
print('Sorted Array in Ascending Order:')
print(array)
