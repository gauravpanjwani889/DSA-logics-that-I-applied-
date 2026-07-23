class Solution {



     int bhai(vector<int>& nums) {
        int n=nums.size();
        
        int prev=nums[0];
        int prev2=0;

        for(int i=0;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;

            int nottake=0+prev;
            int curri=max(take,nottake);
            prev2=prev;
            prev=curri;
        }
        return prev;

        
    }
public:
    int rob(vector<int>& nums) {

        int m=nums.size();
        if(m==0) return 0;
        if(m==1) return nums[0];
        vector<int> temp1,temp2;

        for(int i=0;i<m;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=m-1) temp2.push_back(nums[i]);

            
        }
        return max(bhai(temp1),bhai(temp2));
        
    }
};