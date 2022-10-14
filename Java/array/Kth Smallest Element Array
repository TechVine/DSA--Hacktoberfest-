import sys
sys.setrecursionlimit(10**8)
class Solu:
    def swap(self,arr, a, b): 
        temp = arr[a] 
        arr[a] = arr[b] 
        arr[b] = temp 
      
    def randomPartition(self,arr, l, r): 
        n = r - l + 1
        pivot = int(random.random() % n)  
        self.swap(arr, l + pivot, r)  
        return self.partition(arr, l, r) 
    def kthSmallest(self,arr, l, r, k): 
        if (k > 0 and k <= r - l + 1): 
              
            pos = self.randomPartition(arr, l, r)  
            if (pos - l == k - 1):  
                return arr[pos]  
            if (pos - l > k - 1):  
                                 
                return self.kthSmallest(arr, l, pos - 1, k)  
      
            
            return self.kthSmallest(arr, pos + 1, r,  
                               k - pos + l - 1) 
      
        return 999999999999
      
    def partition(self,arr, l, r): 
        x = arr[r] 
        i = l 
        for j in range(l, r): 
            if (arr[j] <= x): 
                self.swap(arr, i, j)  
                i += 1
        self.swap(arr, i, r)  
        return i 
   
