class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0, n = x ^ y;
        while(n){
            ans++;
            n = n & n-1;
        }
        return ans;
    }
};
