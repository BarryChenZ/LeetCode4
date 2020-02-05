class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        const int n = nums.size();
        vector<vector<long long>> dp(m+1 , vector<long long>(n, INT_MAX));
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) prefix[i] = nums[i] + prefix[i - 1];
        
        for(int i = 0; i < n; i++){
            dp[1][i] = prefix[i];
        }
        
        for(int i = 2; i <= m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < j; k++) dp[i][j] = min(dp[i][j], max(dp[i-1][k], prefix[j] - prefix[k]));
            }
        }
        return dp[m][n - 1];    
    }
    
};
