class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;

        for(int i=3;i<16;i+=3){
            long long base=powl(10LL,i*1LL);
            if(base>n){
                break;
            }
            ans+=n-base+1;
        }
        return ans;
        
    }
};