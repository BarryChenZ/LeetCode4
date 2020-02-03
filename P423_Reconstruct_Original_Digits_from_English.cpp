class Solution {
public:
    string originalDigits(string s) {
        string ans;
        
        string digit[10] = {
            "zero", "one", "two", "three", "four", "five",
            "six", "seven", "eight", "nine"
        };
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        vector<int>counts(10);
        counts[0] = mp['z'];
        counts[2] = mp['w'];
        counts[4] = mp['u'];
        counts[6] = mp['x'];
        counts[8] = mp['g'];
        for(int i = 0; i <= 8; i += 2) {
            for(char c: digit[i]) {
                mp[c] -= counts[i];
            }
        }
        counts[1] = mp['o'];
        counts[3] = mp['t'];
        counts[5] = mp['f'];
        counts[7] = mp['s'];
        for(int i = 1; i <= 7; i += 2) {
            for(char c : digit[i]) {
                mp[c] -= counts[i];
            }
        }
        
        counts[9] = mp['i'];
        
        for(int i = 0; i <= 9; i++) {
            ans = ans + string(counts[i], '0' + i);
        }
        return ans;
    }
};
