class Solution {
public:
    struct info{
        int start_from = 0;
        int start_from1 = 0;
        
        int count = 0;
    };
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> singles;
        info infos[201] = {0};
        
        for(int n : nums){
            info & inf = infos[n + 100];
            int & count = inf.count;
            const int lastanssize = ans.size();
            const int lastsinglessize = singles.size();
            
            for(int i = inf.start_from; i < lastanssize; i++){
                auto& v = ans[i];
                if(n >= v.back()){
                    auto v2 = v;
                    v2.push_back(n);
                    ans.push_back(move(v2));
                }
            }
            
            for (int i=inf.start_from1; i < lastsinglessize;i++){
                if (n >= singles[i] ) {
                    ans.push_back({singles[i],n});
                }
            }
            
            if(!count) singles.push_back(n);
            
            inf.start_from = lastanssize;
            inf.start_from1 = lastsinglessize;
            count++;
        }
        return ans;
    }
};
