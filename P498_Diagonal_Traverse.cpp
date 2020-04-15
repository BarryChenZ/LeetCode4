class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> res;
        int N = matrix.size(),M = matrix[0].size();
        for(int s = 0; s <= N + M - 2; s++){
            for(int x = 0 ; x <= s; x++){
                int i, j;
                i = (s % 2) ? x : s - x;
                j = s - i;
                
                if(i >= N || j >= M) continue;
                res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};
