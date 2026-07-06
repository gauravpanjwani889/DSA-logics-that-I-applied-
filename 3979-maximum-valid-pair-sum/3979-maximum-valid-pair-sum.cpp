class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();

        int mm=-1,ans=0;

        for(int i=0; i<n; i++){
            if(i-k>=0){
                mm=max(mm,nums[i-k]);

            }
            if(mm!=-1){
                ans=max(ans,mm+nums[i]);
            }
        }
        
        return ans;
    }
};