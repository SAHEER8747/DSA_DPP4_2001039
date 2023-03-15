//recursive


  int ed(int e,int f)
  {
        if(f==0 or e==1 or f==1) 
        {
            return f;
        }
        int mini = INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int temp_ans = max(ed(e-1,k-1),ed(e,f-k))+1;
            mini = min(temp_ans,mini);
        }
        return mini;
    }
    int eggDrop(int n, int k) 
    {
       
        return ed(n,k);
    }



//memoize



 int ed(int e,int f)
 {
        if(f==0 or e==1 or f==1)
        {
            return f;
        }
        if(dp[e][f] != -1)  return dp[e][f];
        int mini = INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int temp_ans = max(ed(e-1,k-1),ed(e,f-k))+1;
            mini = min(temp_ans,mini);
        }
        return dp[e][f]=mini;
    }


    int eggDrop(int n, int k) 
    {
      
        memset(dp,-1,sizeof(dp));
        return ed(n,k);
    }
};
