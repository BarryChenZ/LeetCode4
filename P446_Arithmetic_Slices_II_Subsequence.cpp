//brute force
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i, j, k, n = A.size(), ans = 0;
        vector<vector<int>> d(n, vector<int>(n, 0));
        for (i = 0; i < n - 2; i++) {
            for (j = i + 1; j < n - 1; j++) {
                for (k = j + 1; k < n; k++) {
                    if ((long long)A[i] - A[j] == (long long)A[j] - A[k]) {
                        d[j][k] = d[j][k] + d[i][j] + 1;
                    }
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                ans += d[i][j];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        
        int res = 0;
        unordered_map<long long, int> dp[n];
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                long long diff = (long long)A[i] - (long long)A[j];
                if(dp[j].find(diff) != dp[j].end()){
                    res += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                ++dp[i][diff];
            }
        }
        return res;
    }
};
