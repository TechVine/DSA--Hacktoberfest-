#finding kth smallest element in array
def kSmallest(arr,n,k):
	arr.sort()
	return arr[k-1]
	
# Driver code
if __name__ == '__main__':
	arr = [10,5,2,3,8,7,19,15]
	n = len(arr)
	k = int(input("Enter value of k:"))
	# function call
	print("kth smallest element is:",
		kSmallest(arr,n,k))

