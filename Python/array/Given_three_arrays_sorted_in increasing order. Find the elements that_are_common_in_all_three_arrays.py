

class Solution:
    def commonElements (self,a, b, c, n1, n2, n3):
        # your code here
        temp=[]
        i,j,prev=0,0,None
        while(i<n1 and j<n2):
            if(a[i]==b[j]):
                if(prev==None):
                    temp.append(a[i])
                    prev=a[i]
                elif(prev==a[i]):
                    pass
                else:
                    temp.append(a[i])
                    prev=a[i]
                i+=1
                j+=1
            elif(a[i]>b[j]):
                j+=1
            else:i+=1
        #print(temp)
        temp2=[]
        i,j,prev=0,0,None
        while(i<len(temp) and j<n3):
            if(temp[i]==c[j]):
                if(prev==None):
                    temp2.append(c[j])
                    prev=c[j]
                elif(prev==c[j]):
                    pass
                else:
                    temp2.append(c[j])
                    prev=c[j]
                i+=1
                j+=1
            elif(temp[i]>c[j]):
                j+=1
            else:i+=1
        return temp2


#{ 
 # Driver Code Starts
#Initial Template for Python 3


t = int (input ())
for tc in range (t):
    n1, n2, n3 = list(map(int,input().split()))
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    C = list(map(int,input().split()))
    
    ob = Solution()
    
    res = ob.commonElements (A, B, C, n1, n2, n3)
    
    if len (res) == 0:
        print (-1)
    else:
        for i in range (len (res)):
            print (res[i], end=" ")
        print ()
