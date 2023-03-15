//recursive

#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:

    int knapSack(int W, int wt[], int val[], int n) 
    { 
      
       if(n==0 or W==0) return 0;
       
       if(W>=wt[n])
       {
           int pick = val[n]+knapSack(W-wt[n],wt,val,n-1);
           int notpick=knapSack(W,wt,val,n-1);
           return max(pick,notpick);
       }
       else if(W<wt[n]) 
       {
           return knapSack(W,wt,val,n-1);
       }
    }
};





//  memoize




#include <bits/stdc++.h>
using namespace std;


class Solution
{
    int dp[1010][1010];
    public:
    int ks(int W, int wt[], int val[], int n) 
    { 
       
       if(n==0 or W==0) return 0;
       if(dp[W][n-1] != -1) return dp[W][n-1];
       if(W>=wt[n-1])
       {
           int pick = val[n-1]+ks(W-wt[n-1],wt,val,n-1);
           int notpick=ks(W,wt,val,n-1);
           return dp[W][n-1]= max(pick,notpick);
       }
       else
       {
           return dp[W][n-1]= ks(W,wt,val,n-1);
       }
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(dp,-1,sizeof(dp));
       return ks(W,wt,val,n);
    }
};
