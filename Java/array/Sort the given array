class Solu
{
    public long[] sortArray(long []arr, int n, long A, long B, long C)
    {
        for (int i = 0; i < n; i++) 
        arr[i] = A*arr[i]*arr[i] + B*arr[i] + C; 
        int f = 1;
        if(A > 0) f = 2;
        int i = 0, j = n-1; 
        long new_arr[]=new long[n]; 
        int k = 0; 
        if(f==1){
            while (i <=j){
                if (arr[i] < arr[j])
                    new_arr[k++] = arr[i++];
                else
                    new_arr[k++] = arr[j--];
            }
        }else{
            while (i <=j){
                if (arr[i] > arr[j])
                    new_arr[k++] = arr[i++];
                else
                    new_arr[k++] = arr[j--];
            }
        } 
        
        for(i = 0; i < n; i++)
            arr[i] = new_arr[i];
    
        if(f == 2){
            for(i = 0; i < n / 2; i++){
                long temp=arr[i];
                arr[i]=arr[n-i-1];
                arr[n-i-1]=temp;
            }
        }
    
        return arr;
    }
}
