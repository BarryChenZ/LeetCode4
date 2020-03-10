class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() < 2) return false;
        string tmp; tmp += s[0];
        int n = s.size();
        for(int i = 1; i < n; i++){
            if(tmp[0] == s[i]){
                if(trace(tmp, s)) return true;    
            }
            tmp += s[i];
        }
        return false;
    }
    bool trace(string tmp, string s){
        string temp;
        for(int i = 0; i < s.size();){
            temp = s.substr(i, tmp.size());
            if(tmp != temp) return false;
            i += tmp.size();
        }
        return true;
    }
};
