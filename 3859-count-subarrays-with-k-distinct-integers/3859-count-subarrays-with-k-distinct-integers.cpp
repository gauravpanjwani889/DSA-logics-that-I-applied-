class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n=nums.size();
        long long ans=0;

        map<int,int> freq1,freq2;

        int j1=-1,j2=-1,cnt=0;

        for(int i=0; i<n; i++){
            while(j1<n && freq1.size()<k+1){
                j1++;

                if(j1<n){
                    freq1[nums[j1]]++;
                }
            }
            while(j2<n && cnt<k){
                j2++;

                if(j2<n){
                    freq2[nums[j2]]++;
                    if(freq2[nums[j2]]==m){
                        cnt++;
                    }
                }
            }
            if(j2<j1) ans+=j1-j2;
         freq1[nums[i]]--;
         if(!freq1[nums[i]]) freq1.erase(nums[i]);

         freq2[nums[i]]--;
         if(freq2[nums[i]]==m-1) cnt--;
        }
        return ans;
    }
};