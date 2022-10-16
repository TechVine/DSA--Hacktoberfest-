class Solution:
    
    #Function to search a given number in row-column sorted matrix.
    def search(self,matrix, n, m, x): 
    	i, j = n - 1, 0 				
    	while (i >= 0 and j < m):
    	    
    	    #if given number is found, we return true.
    		if (matrix[i][j] == x): 
    			return True; 
    		
    		#if current element is greater than given number, we 
    		#decrease i pointer else we increase j pointer.
    		if (matrix[i][j] > x): 
    			i -= 1
    		else: 
    			j += 1
    			
    	#if we reach here, it means given number is not
    	#present in matrix so we return false.
    	return False
    
