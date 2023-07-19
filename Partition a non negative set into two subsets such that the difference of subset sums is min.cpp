// tabulation answer using subsequence sum = k problem
#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int i=0 ; i<n ; i++) sum += arr[i];

	vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
	for(int i=0 ; i<n ; i++) dp[i][0] = true;
	if(arr[0]<=sum) dp[0][arr[0]] = true;

	for(int i=1 ; i<n ; i++)
	{
		for(int target = 1; target<=sum ; target++)
		{
			bool nottake = dp[i-1][target];
			bool take = false;
			if(arr[i]<=target) take = dp[i-1][target-arr[i]];
			dp[i][target] = take | nottake;
		}
	}

	int mini = INT_MAX;
	for(int target=0 ; target<=sum ; target++)
	{
		if(dp[n-1][target])
		{
			mini = min(mini,abs(sum-2*target));
		}
	}
	return mini;
}

// end

// space optimum
#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int i=0 ; i<n ; i++) sum += arr[i];

	vector<bool> prev(sum+1,0) ,cur(sum+1,0);
	cur[0] = prev[0] = true;
	if(arr[0]<=sum) prev[arr[0]] = true;

	for(int i=1 ; i<n ; i++)
	{
		for(int target = 1; target<=sum ; target++)
		{
			bool nottake = prev[target];
			bool take = false;
			if(arr[i]<=target) take = prev[target-arr[i]];
			cur[target] = take | nottake;
		}
		prev = cur;
	}

	int mini = INT_MAX;
	for(int target=0 ; target<=sum ; target++)
	{
		if(prev[target])
		{
			mini = min(mini,abs(sum-2*target));
		}
	}
	return mini;
}
