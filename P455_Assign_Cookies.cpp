class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int si = 0;
        for(int gi = 0; gi < g.size(); gi++){
            int tmp = 0;
            while(si < s.size()){
                tmp += s[si];
                if(s[si] >= g[gi]){
                    si++;
                    ans++;
                    break;
                }
                si++;
            }
        }
        return ans;
    }
};
