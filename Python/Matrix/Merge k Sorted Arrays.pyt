class lst_entry:
    def __init__(self,x,y,z):
        self.val=x
        self.lst=y
        self.inx=z

class min_heap:
    def __init__(self):
        self.heap_lst=[]
    
    def add(self,x,y,z):
        self.heap_lst.append(lst_entry(x,y,z))
        index=len(self.heap_lst)-1
        while(index>0 and self.heap_lst[index].val < self.heap_lst[(index-1)//2].val):
            parent = (index-1)//2
            self.heap_lst[index] , self.heap_lst[parent] = self.heap_lst[parent] , self.heap_lst[index]
            index = parent
    
    def pop(self):
        ret=(self.heap_lst[0].val, self.heap_lst[0].lst, self.heap_lst[0].inx)
        l=len(self.heap_lst)
        self.heap_lst[0]=self.heap_lst[l-1]
        self.heap_lst.pop()
        l=l-1
        i=0
        while(1):
            if(2*i+1>=l):
                break
            child=2*i+1
            if(2*i+2<l and self.heap_lst[2*i+2].val < self.heap_lst[2*i+1].val):
                child=2*i+2
            if(self.heap_lst[child].val >= self.heap_lst[i].val):
                break
            self.heap_lst[i] , self.heap_lst[child] = self.heap_lst[child] , self.heap_lst[i]
            i=child
        return ret
    
    def available(self):
        if(len(self.heap_lst)>0):
            return True
        return False

class Solution:
    #Function to merge k sorted arrays.
    def mergeKArrays(self, numbers, n):
        n=len(numbers)
        h=min_heap()
        
        #adding arrays to the heap.
        for i in range(n):
            h.add(numbers[i][0],i,0)
        arr=[]
        
        #using a loop while heap is not empty.
        while(h.available()):
            
            val,i,j = h.pop()
            #adding the element at current in list.
            arr.append(val)
            if(j+1 < len(numbers[i]) ):
                h.add(numbers[i][j+1],i,j+1)
                
        #returning the list.
        return arr
