class Solution {

  static  int dp [] = new int [100000+1];

 

    static int fillingBucket(int N) {

        // code here

     

        if(N>1)

        {

            int ans1;

            int ans2;

            if(dp[N-1]>0)

            {

              ans1 = dp[N-1]; 

            }

            else 

            {

                ans1 = fillingBucket(N-1);

            }

            if(dp[N-2]>0)

            {

              ans2 = dp[N-2]; 

            }

            else 

            {

                ans2 = fillingBucket(N-2);

            }

           return dp[N]= (ans1 +

            ans2)%100000000;

        }

        return dp[N]=1;

    }

};
