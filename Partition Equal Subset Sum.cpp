// recursion and memo
class Solution {
public:
    bool ans(vector<int>& nums, int index, int target,vector<vector<int>>& dp)
    {
        if(target==0) return true;
        if(index==0) return nums[0]==target;
        if(dp[index][target]!=-1) return dp[index][target];

        bool nottake = ans(nums,index-1,target,dp);
        bool take = 0;
        if(nums[index]<=target) take = ans(nums,index-1,target-nums[index],dp);
        return dp[index][target] = take|nottake;
    }
    bool canPartition(vector<int>& nums) 
    {
        int n=nums.size();
        int sum = 0;
        for(int i=0; i<n ; i++)
        {
            sum += nums[i];
        }
        if(sum%2==1) return false;
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return  ans(nums,n-1,sum/2,dp);
    }
};
// recursion and memo

//tabulation and space opti
class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int n=nums.size();
        int sum = 0;
        for(int i=0; i<n ; i++) sum += nums[i];
        if(sum%2==1) return false;

        vector<bool> prev(sum/2+1,0) , cur(sum/2+1,0);
        prev[0] = cur[0] = true;
        if(nums[0]<=sum/2) prev[nums[0]] = true;

        for(int i=1; i<n ; i++)
        {
            for(int target = 1; target<=sum/2 ; target++)
            {
                bool nottake = prev[target];
                bool take = false;
                if(target>= nums[i]) take= prev[target-nums[i]];
                cur[target] = nottake|take;
            }
            prev = cur;
        }
        return cur[sum/2];
    }
};
//tabulation and space opti
