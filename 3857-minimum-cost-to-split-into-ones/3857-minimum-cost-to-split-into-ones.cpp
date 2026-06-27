class Solution {
public:
int func(int n){
    if(n==1) return 0;
    if(n==2) return 1;

    return func(n/2)+ func((n+1)/2)+ (n/2)*((n+1)/2);
}
    int minCost(int n) {
        return func(n);
        
    }
};