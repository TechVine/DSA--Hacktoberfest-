//4 10 100 5 50
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int MatrixChainOrder(vector<vector<int>>& mtable, vector<vector<int>>& s_table, int p[], int i, int j)
{
    if (i == j)
        return 0;  //Base condition
    int mini = INT_MIN; //For maximum cost, doing the opposite. 
    int kval = 0;
    int count; 
    //Applying the top down appraoch
    for (int k = i; k < j; k++)
    {
		//Applying the logic, m[i j] = m[i k] + m[k+1 j] + pi-1 * pk * pj 
        count = MatrixChainOrder(mtable, s_table, p, i, k) + MatrixChainOrder(mtable, s_table, p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if(count > mini){
            //Changing the operator.
            kval=k;
            mini=count;
        }
    }
    mtable[i][j]=mini;  
	s_table[i][j]=kval;  
    return mini;
}
//Referenced Book's Algo to modify accordingly
void Print_Optimal_Parens(vector<vector<int>> s_tabl, string optml, int i, int j){
    if(i==j)
        cout<<optml<<i++;   //As, Ai
    else{
        cout<<"(";
        Print_Optimal_Parens(s_tabl, optml, i, s_tabl[i][j]);
        Print_Optimal_Parens(s_tabl, optml, s_tabl[i][j]+1, j);
        cout<<")";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    vector<vector<int>> mtable(n, vector<int>(n, 0));
	vector<vector<int>> s_table(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //Printing the mtable.
    int min_cst=MatrixChainOrder(mtable,s_table, arr, 1, n-1);
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cout<<mtable[i][j]<<" ";
        }
        cout << "\n";
    }
    //S Table
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cout<<s_table[i][j]<<" ";
        }
        cout << "\n";
    }
    //cout<<MatrixChainOrder(mtable,s_table, arr, 1, n-1);
	cout<<min_cst<<endl;
    string op_parnt="A";
    Print_Optimal_Parens(s_table, op_parnt, 1, n-1);
    //Taking i as 1, to add the suffix for the Optimal matrix parenthesization
    return 0;
}
