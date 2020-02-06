class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        if(len == 0)
        {
            if(amount == 0) return -1;
            else return 0;
        }

        sort(coins.begin(),coins.end());
        if(amount == 0) return 0;
        
        int i,j,tmp;
        vector<int>dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(i = 1; i<amount+1;i++)
            for(j = 0;j<len;j++)
            {
                if(coins[j]<= i)
                {
                    dp[i] = (dp[i-coins[j]]<INT_MAX)?min(dp[i],1+dp[i-coins[j]]):dp[i];
                }
            }
        return (dp[amount]<INT_MAX)?dp[amount] : -1;
    
        
    }
};



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        if(amount == 0) return 0;
        
        int i,j,tmp;
        vector<int>dp(amount+1,amount+1);
        dp[0] = 0;
        for(i = 1; i<amount+1;i++)
            for(j = 0;j<len;j++)
            {
                
                if(coins[j] <= i) dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        return (dp[amount]<amount+1)?dp[amount] : -1;
    
        
    }
};

