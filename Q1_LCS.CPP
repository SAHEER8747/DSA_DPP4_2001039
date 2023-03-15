//recursive


 int lcs(int m, int n, string s1, string s2)
    {
        if(m==0 or n==0) return 0;
        if(s1[m-1]==s2[n-1]) return 1+lcs(m-1,n-1,s1,s2);
        else return max(lcs(m-1,n,s1,s2),lcs(m,n-1,s1,s2));
       
    }


//memoize


int LCS(int m, int n, string s1, string s2)
{
         if(m==0 or n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s1[m-1]==s2[n-1]) return dp[m][n] = 1+LCS(m-1,n-1,s1,s2);
        else return dp[m][n] = max(LCS(m-1,n,s1,s2),LCS(m,n-1,s1,s2));
    }
    
    int lcs(int m, int n, string s1, string s2)
    {
        memset(dp,-1,sizeof(dp));
       return LCS(m,n,s1,s2);
       
    }
