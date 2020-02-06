class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len <= 1) return s;
        int dp[len + 1][len + 1];
        memset(dp,0,sizeof(dp));
        int i,j,longest = 1, start = 0,end = 0,cur = 0 ;
        for(i = 0; i < len+1;i++)
            dp[i][i] = 1;
        for(i = 1;i<len + 1; i++)
            for(j = 0; j < i; j++)
            {
                if(i == j+1 && s[i] == s[j])
                {
                    dp[j][i] = 1;
                    if(longest < 2)
                    {
                        longest = 2;
                        start = j;
                        end = i;
                    }
                }
                else if(dp[j+1][i-1] == 1 && s[j] == s[i])
                {
                    dp[j][i] = 1;
                    cur = i -j +1;
                    if(cur > longest)
                    {
                        longest = cur;
                        start = j;
                        end = i;
                    }
                }
            }
        string ret = s.substr(start,longest);
        return ret;
        
    }
};