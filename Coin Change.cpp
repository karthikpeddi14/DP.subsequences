// recursion and memo
class Solution {
public:
    int noofcoins(vector<int>& coins, int amount, int index,vector<vector<long>>& dp)
    {
        if(index==0)
        {
            if(amount%coins[0]!=0) return 1e9;
            return amount/coins[0];
        }
        if(dp[index][amount]!=-1) return dp[index][amount];

        int nottake = noofcoins(coins,amount,index-1,dp);
        int take = 1e9;
        if(amount>=coins[index]) take = 1 + noofcoins(coins,amount-coins[index],index,dp);
        return dp[index][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        long ans = noofcoins(coins,amount,n-1,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};
// recursion and memo

// tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));
        for(int val = 0 ; val<=amount ;val ++) 
        { 
            if(val%coins[0]==0) dp[0][val] = val/coins[0];
        }
        for(int i=1; i<n ; i++)
        {
            for(int target = 0; target<=amount; target++)
            {
                int nottake = dp[i-1][target];
                int take = 1e9;
                if(coins[i]<=target) take = 1+dp[i][target-coins[i]];
                dp[i][target] = min(take,nottake);
            }
        }
        if(dp[n-1][amount]==1e9) return -1;
        return dp[n-1][amount];
    }
};
// tabulation

// space opti
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<int> prev(amount+1,1e9) , cur(amount+1,1e9);
        for(int val = 0 ; val<=amount ;val ++) 
        { 
            if(val%coins[0]==0) prev[val] = val/coins[0];
        }
        for(int i=1; i<n ; i++)
        {
            for(int target = 0; target<=amount; target++)
            {
                int nottake = prev[target];
                int take = 1e9;
                if(coins[i]<=target) take = 1+cur[target-coins[i]];
                cur[target] = min(take,nottake);
            }
            prev = cur;
        }
        if(prev[amount]==1e9) return -1;
        return prev[amount];
    }
};
// space opti
