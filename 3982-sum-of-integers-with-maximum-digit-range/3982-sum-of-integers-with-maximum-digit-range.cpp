class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxrange=0,sum=0;

        for(auto x:nums){
            int minr=x%10,maxr=x%10;
            int num=x;

            

            while(x){
                int d=x%10;
                minr=min(minr,d);
                maxr=max(maxr,d);

                x=x/10;
                

            }

            if((maxr-minr)>maxrange){
                maxrange=maxr-minr;
                sum=num;
            }
            else if((maxr-minr)==maxrange){
                sum+=num;
            }
        }

        return sum;
        
    }
};