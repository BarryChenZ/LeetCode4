class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        int n = p.length();
        unordered_map <char,int> forp;
        unordered_map <char,int> fors;
        vector<int> ans;
        for(auto & i : p) forp[i]++;
        for(int i = 0; i < n; i++) fors[s[i]]++;
        if(fors == forp) ans.push_back(0);
        for(int i = n; i < s.length(); i++){
            fors[s[i-n]]--;
            fors[s[i]]++;
            if(fors[s[i-n]] == 0) fors.erase(s[i-n]);
            if(fors == forp) ans.push_back(i-n+1);
        } 
            return ans;
    }
};
