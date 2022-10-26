import java.util.*; 
public class ZeroOneKnapSack{
    public static void main(String[] args){
        Scanner scn = new Scanner (System.in); 
        int n = scn.nextInt(); 
        int [] val = new int[n]; 
        for (int i =0 ; i<n; i++){
            val[i] = scn.nextInt(); 
        }
        int [] wt = new int [n]; 
        for (int i =0; i<n; i++){
            wt[i]= scn.nextInt(); 
            
        }
        int cap = scn.nextInt(); 
        int [][] dp = new int [n+1][cap+1]; 
        for (int i=1; i<dp.length; i++){
            for (int j =1; j<dp[0].length; j++){
                int v = val[i-1]; 
                int w = wt[i-1]; 
                if(j>=w){
                    if(v+dp[i-1][j-w]>=dp[i-1][j]){
                        dp[i][j] = dp[i-1][j-w]+v; 
                    }
                    else{
                        dp[i][j] = dp[i-1][j]; 
                    }
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        System.out.println(dp[n][cap]);
        scn.close();
        
    } 
}