class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            int time = 0;
            int num = 0;
            for(int j = i; j < s.size(); j++){
                if(s[j] != s[i]) time++;
                num++;
                if(time > k){
                    num--;
                    break;
                }
            }
            if(time < k){
                if(k - time + num > s.size()) num = s.size();
                else                          num += k - time;
            }
            if(num > ans) ans = num;
            
            while(s[i] == s[i+1] && i < s.size() - 1){
                i++;
            }
        }
        return ans;
    }
};
