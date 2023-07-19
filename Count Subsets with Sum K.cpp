// recursion and memo
int mod = 1e9 + 7;
int count(vector<int>& arr,int k, int index,vector<vector<int>>& dp)
{
	if(k==0) return 1;
	if(dp[index][k]!=-1) return dp[index][k];
	if(index==0) 
	{
		if(k==arr[0]) return 1;
		return 0;
	}

	int nottake = count(arr,k,index-1,dp);
	int take = 0;
	if(arr[index]<=k) take = count(arr,k-arr[index],index-1,dp);
	return dp[index][k] = (nottake%mod + take%mod)%mod; 

}
int findWays(vector<int>& arr, int k)
{
	int n= arr.size();
	vector<vector<int>> dp(n,vector<int> (k+1,-1));
	return count(arr,k,n-1,dp);
}

// recursion and memo

// tabulation
int mod = 1e9 + 7;

int findWays(vector<int>& arr, int k)
{
	int n= arr.size();
	vector<vector<int>> dp(n,vector<int> (k+1,0));
	if(arr[0]<=k) dp[0][arr[0]] = 1;
	for(int i=0 ; i<n ; i++) dp[i][0] = 1;

	for(int i=1 ; i<n ; i++)
	{
		for(int target = 1; target<=k ; target++)
		{
			int nottake = dp[i-1][target];
			int take = 0;
			if(arr[i]<=target) take = dp[i-1][target-arr[i]];
			dp[i][target] = (nottake%mod + take%mod)%mod; 
		}
	}

	return dp[n-1][k];
	
}

// tabulation

//space optimum
int mod = 1e9 + 7;

int findWays(vector<int>& arr, int k)
{
	int n= arr.size();
	vector<int> prev(k+1,0) , cur(k+1,0);
	cur[0] = prev[0] = 1;
	if(arr[0]<=k) prev[arr[0]] = 1;

	for(int i=1 ; i<n ; i++)
	{
		for(int target = 1; target<=k ; target++)
		{
			int nottake = prev[target];
			int take = 0;
			if(arr[i]<=target) take = prev[target-arr[i]];
			cur[target] = (nottake%mod + take%mod)%mod; 
		}
		prev = cur;
	}

	return prev[k];
	
}

//space optimum
