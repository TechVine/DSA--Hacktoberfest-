def search_in_matrix(matrix, rows, cols, target):
     
     #returns the first position of the element found in the matrix
    
    # target -> value to be searched in the matrix
    
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == target:
                return i,j
    return -1,-1 #if the target is not found

if __name__ == "__main__":
    matrix = [[1,12,3],[4,6,7],[13,8,2],[9,5,10]]
    rows = len(matrix)
    cols = len(matrix[0])
    target = 13
    curr_row, curr_col = search_in_matrix(matrix, rows, cols, target)
    print("The target =",target,"is found in the row number =", curr_row+1, "and column number =", curr_col+1) # one based indexing to demonstrate rows and columns clearly


# Time Complexity is O(M * N) where M -> rows , n->columns of the matrix 
# Space Complexity IS O(1) (Algorithmic Space Complexity ignoring the space of the input matrix)

"""Code provided by K sanketh Kumar"""

