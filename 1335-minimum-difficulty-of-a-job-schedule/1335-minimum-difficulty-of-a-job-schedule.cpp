class Solution {
public:
int solve(vector<int> &arr,int idx,int d, vector<vector<int>> &dp){
    if(d==1){
        int ans=INT_MIN;
        for(int i=idx;i<arr.size();i++){
            ans=max(ans,arr[i]);

        }
        return ans;
    }
    if(dp[idx][d]!=-1){
        return dp[idx][d];
    }

    int anss=INT_MAX;
    int maxd=arr[idx];
    for(int i=idx;i<=arr.size()-d;i++){
        maxd=max(maxd,arr[i]);

        int result=maxd+solve(arr,i+1,d-1,dp);

        anss=min(anss,result);

    }
    return dp[idx][d]=anss;
}
    int minDifficulty(vector<int>& arr, int d) {
        int n=arr.size();
        if(n<d) return -1;

        vector<vector<int>> dp(arr.size()+1,vector<int>(11,-1));

        return solve(arr,0,d,dp);
    
        
    }
};