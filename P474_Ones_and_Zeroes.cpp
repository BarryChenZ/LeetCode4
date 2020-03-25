class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));             int numZeros, numOnes;
        for(auto &s : strs){
            numZeros = numOnes = 0;
            for(auto &c : s){
                if(c == '0') numZeros++;
                else if(c == '1') numOnes++;
            }
            for(int i = m; i >= numZeros; i--){
                for(int j = n; j >= numOnes; j--){
                    memo[i][j] = max(memo[i][j], memo[i - numZeros][j - numOnes] + 1);   
                }
            }
        }
        return memo[m][n];
    }
};
// 0-1 背包問題
