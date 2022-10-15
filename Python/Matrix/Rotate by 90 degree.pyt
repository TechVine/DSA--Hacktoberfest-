def rotate(matrix): 
    n = len(matrix);
    for i in range(0, int(n/2)):
    	for j in range(i, n-i-1):
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][n-1-i];        
            matrix[j][n-1-i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = temp;  
