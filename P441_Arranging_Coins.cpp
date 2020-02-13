class Solution {
public:
    int arrangeCoins(int n) {
        long long k = 1;
        long long star = k*(1+k)/2;
        while(star <= n){
            k++;
            star = k*(1+k)/2;
        }
        return k - 1;
    }
};
