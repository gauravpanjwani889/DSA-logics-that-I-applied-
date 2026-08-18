class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[-1]*(n+1)

        def solve(i:int)->int:
            if i==0:
                return nums[i]
            if i<0:
                return 0  
            if(dp[i]!=-1):
                return dp[i]      

            pick= nums[i] + solve(i-2)   
            notpick=0+ solve(i-1) 
            dp[i] = max(pick,notpick)
            return dp[i]
        return solve(n-1)