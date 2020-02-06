class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int len = s.length();
        if(len <= 1) return len;
        int dp[len + 1][len + 1];
        memset(dp,0,sizeof(dp));
        int i,j,longest = 1, cur = 0 ;
        for(i = 0; i < len+1;i++)
            dp[i][i] = 1;
        for(j = 1;j<len+1;j++)
            for(i = j-1;i>=0;i--)
            {
                if(j==i+1 && s[i] == s[j])
                    dp[i][j] = 2;
                else if(s[i] == s[j] )
                    dp[i][j] = dp[i+1][j-1]  +2;
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }

        return dp[0][len-1];
    }
};