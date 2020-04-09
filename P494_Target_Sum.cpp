class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || (S + sum) % 2) return false;
        
        sort(nums.begin(), nums.end());
        const int sizeS = (S + sum) / 2;
        const int sizeN = upper_bound(nums.begin(), nums.end(), sizeS) - nums.begin();
        vector<int> dp(sizeS + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < sizeN; i++){
            const int tmp = nums[i];
            for(int j = sizeS; j >= tmp; j--) dp[j] += dp[j - tmp];
        }
        return dp[sizeS];
    }
};
