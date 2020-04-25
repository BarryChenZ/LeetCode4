class Solution {
public:
    string convertToBase7(int num) {
        int res = 0;
        for(int i = 0; num != 0; res += pow(10, i++)*(num % 7), num = num / 7){}
        return to_string(res);
    }
};
