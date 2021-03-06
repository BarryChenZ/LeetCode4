class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string>ans;
        for(int h = 0; h <= 11; h++) {
            for(int m = 0; m <= 59; m++) {
                if(bitset<10>(h).count() + bitset<10>(m).count() == num) {
                    ans.push_back(to_string(h) + ":" + ((m < 10) ? ("0" + to_string(m)) : to_string(m)));
                }
            }
        }
        return ans;
    }
};
