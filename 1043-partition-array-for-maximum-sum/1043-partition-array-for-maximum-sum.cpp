class Solution {
public:
int solve(int ind, vector<int> &arr, int k, vector<int> &dp){
    int n=arr.size();
    if(ind==n) return 0;
    if(dp[ind]!=-1) return dp[ind];


int maxi=INT_MIN;
int len=0;
int maxans=INT_MIN;
    for(int j=ind; j< min(n,ind+k); j++){


        len++;
        maxi=max(maxi,arr[j]);
        int sum=(len*maxi) + solve(j+1,arr,k,dp);

        maxans=max(maxans,sum);

    }
    return dp[ind]=maxans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);

        return solve(0,arr,k,dp);
        
    }
};