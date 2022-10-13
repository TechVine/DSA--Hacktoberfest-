// Rotate the matrix by 90 degrees.

#include <bits/stdc++.h>
using namespace std;
#define N 3

void rotateMatrix(int matrix[][N]){
    /* Reverse each array in the matrix
        3 2 1 
        6 5 4
        9 8 7
    */
    for(int i=0; i<N; i++){
        reverse(matrix[i], matrix[i]+N);
    }

    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

}

void displayMatrix(int matrix[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/* Driver code*/
int main(){
    
    int matrix[N][N] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    
    rotateMatrix(matrix);
    displayMatrix(matrix);

    return 0;
}
