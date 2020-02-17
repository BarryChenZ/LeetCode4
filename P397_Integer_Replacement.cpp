class Solution {
public:
    int integerReplacement(int n) {
        int res = Replacing((long long)n, 0);
        return res;
    }
    int Replacing(long long n, int k){
        if(n == 1) return k;
        //偶數
        if(n % 2 == 0){
            return Replacing(n / 2, k + 1);            
        }
        //奇數
        else{
            return min(Replacing(n + 1, k + 1), Replacing(n - 1, k + 1));
        }
    }
};
