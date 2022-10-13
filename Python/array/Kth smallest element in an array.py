def kth_smallest(nums, n, k):
    #nums -> array given as an input
    #n -> length of the array
    #k -> returning k'th smallest element in the given array
    
    
    if k >= n or n == 0: #invalid value of k which is greater than length of the array
        return -1 #exceptionl case we return -1
    nums.sort()
    #sort the array in the ascending order
    return nums[k-1]


if __name__ == "__main__":
    nums = [4,2,3,-1]
    length = len(nums)
    k = 2
    print("k'th smallest element in the array is: ", kth_smallest(nums,length, k))
"""Code provided by K sanketh Kumar"""

