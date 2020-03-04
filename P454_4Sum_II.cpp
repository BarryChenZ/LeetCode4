class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();
        int res = 0;
        unordered_map<int, int> mp1, mp2;
        for(auto a : A){
            for(auto b : B){
                mp1[a + b]++;
            }
        }
        for(auto c : C){
            for(auto d : D){
                mp2[c + d]++;
            }
        }
        for(auto it = mp1.begin(); it != mp1.end(); it++){
            auto jt = mp2.find(0 - it->first);
            if(jt != mp2.end()){
                res += it->second*jt->second;    
            }
        }
        return res;
    }
};
