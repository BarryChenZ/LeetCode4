class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = 0;
            }
            m[s[i]]++;
        }
        
        vector<pair<char, int>> tmp;
        for(auto it = m.begin(); it!= m.end(); it++) tmp.push_back({it->first,it->second});  
        
        sort(tmp.begin(), tmp.end(), [&](pair<char, int>& a, pair<char, int>& b){
            return a.second > b.second;
        });
        //map<char, int>::iterator it;
        
        for(auto it =  tmp.begin(); it!= tmp.end(); it++){
            for(int i = 0; i < it->second; i++){
                ans += it->first;
            }
        }
        return ans;
    }
};
