int f(int index,vector<int> &price, int n,vector<vector<int>>& dp )
{
	if(index==0) return price[0]*n;
	if(dp[index][n]!=-1) return dp[index][n];

	int nottake = f(index-1,price,n,dp);
	int take = INT_MIN;
	if(n>=index+1) take = price[index] + f(index,price,n-index-1,dp);
	return dp[index][n] = max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	int prev[n+1];
	for(int i=0 ; i<=n ; i++)
	{
		prev[i] = price[0]*i;
	}

	for(int i=1; i<n ; i++)
	{
		for(int j=0 ; j<=n ; j++)
		{
			int nottake = prev[j];
			int take  = INT_MIN;
			if(j>=i+1) take =price[i] + prev[j-(i+1)];
			prev[j] = max(take,nottake);
		}
	}
	return prev[n];
	
}
