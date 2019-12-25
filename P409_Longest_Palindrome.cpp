class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = 0;    
            }
            m[s[i]]++;
        }
        //unordered_map<char,int>::iterator it;
        bool numofone = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second == 1) numofone = 1;
            if(it->second > 1 && it->second % 2 == 0){
                ans += (it->second / 2) * 2;   
            }
            else if(it->second > 1 && it->second % 2 != 0){
                numofone = 1;
                ans += (it->second / 2) * 2;
            }
        }
        return  numofone == 1 ? ans + 1 : ans;
    }
};
