// recur and memo
#include <bits/stdc++.h> 
int f(vector<int> w, vector<int> v, int maxi, int index,vector<vector<int>>& dp)
{
	if(maxi==0) return 0;
	if(index==0) 
	{
		if(maxi>=w[0]) return v[0];
		return 0;
	}
	if(dp[index][maxi]!=-1) return dp[index][maxi];

	int nottake = f(w,v,maxi, index-1,dp);
	int take = -1;
	if(w[index]<=maxi) take = v[index] + f(w,v,maxi-w[index],index-1,dp);
	return dp[index][maxi] = max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(weight,value,maxWeight,n-1,dp);
}
// recur and memo

//tabulation
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));

	for(int i=0; i<n ; i++) dp[i][0] = 0;
	for(int m = 0 ; m<=maxWeight ; m++) 
	{
		if(m>=weight[0]) dp[0][m] = value[0];
	}

	for(int i=1 ; i<n ; i++)
	{
		for(int target =1 ; target<=maxWeight ; target++ )
		{
			int nottake= dp[i-1][target];
			int take = 0;
			if(weight[i]<=target) take = value[i] + dp[i-1][target-weight[i]];
			dp[i][target] = max(take,nottake);
		}
	}
	return dp[n-1][maxWeight];
}
//tabulation

// space opti
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0), cur(maxWeight+1,0);

	prev[0] = cur[0] = 0;
	for(int m = 1 ; m<=maxWeight ; m++) 
	{
		if(m>=weight[0]) prev[m] = value[0];
	}

	for(int i=1 ; i<n ; i++)
	{
		for(int target =1 ; target<=maxWeight ; target++ )
		{
			int nottake= prev[target];
			int take = 0;
			if(weight[i]<=target) take = value[i] + prev[target-weight[i]];
			cur[target] = max(take,nottake);
		}
		prev = cur;
	}
	return prev[maxWeight];
}
//space opti

// further optimization
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0);

	for(int m = weight[0] ; m<=maxWeight ; m++)  prev[m] = value[0];

	for(int i=1 ; i<n ; i++)
	{
		for(int target =maxWeight ; target>=0 ; target-- )
		{
			int nottake= prev[target];
			int take = 0;
			if(weight[i]<=target) take = value[i] + prev[target-weight[i]];
			prev[target] = max(take,nottake);
		}
	}
	return prev[maxWeight];
}
//further optimisation
