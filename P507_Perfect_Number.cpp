class Solution {
public:
    int tmp = 1;
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int low = 2;
        int large = num-1;
        dfs(low, large, num);
        cout << tmp;
        return (tmp == num);
    }
    void dfs(int low, int large, int num){
        while(low <= large){
            if(num % low == 0){
                tmp += low + (((num/low) == low) ? 0 : num/low );
                dfs(low + 1, num / low - 1, num);
                break;
            }
            low++;
        }
        return;
    }
};
