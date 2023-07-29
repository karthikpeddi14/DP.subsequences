// recur and memo
class Solution {
public:
    int f(int amount ,vector<int>& coins, int index,vector<vector<int>>& dp)
    {
        if(index==0)
        {
            if(amount % coins[0] == 0) return 1;
            return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int nottake = f(amount,coins,index-1,dp);
        int take = 0;
        if(coins[index]<=amount) take = f(amount-coins[index], coins, index,dp);
        return dp[index][amount] = take+nottake;
    }
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return f(amount,coins,n-1,dp);
    }
};
// recur and memo

// tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int i=0 ; i<=amount ; i++)
        {
            if(i%coins[0] == 0) dp[0][i] = 1;
        }

        for(int i=1; i<n ; i++)
        {
            for(int am = 0 ; am<=amount ; am++)
            {
                int nottake = dp[i-1][am];
                int take = 0;
                if(am>=coins[i]) take = dp[i][am-coins[i]];
                dp[i][am] = take + nottake;
            }
        }
        return dp[n-1][amount];
    }
};
// tabulation

// space opti
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        for(int i=0 ; i<=amount ; i++)
        {
            if(i%coins[0] == 0) prev[i] = 1;
        }

        for(int i=1; i<n ; i++)
        {
            for(int am = 0 ; am<=amount ; am++)
            {
                int nottake = prev[am];
                int take = 0;
                if(am>=coins[i]) take = prev[am-coins[i]];
                prev[am] = take + nottake;
            }
        }
        return prev[amount];
    }
};
// space opti
