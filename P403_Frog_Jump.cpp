class Solution {
public:
    unordered_map<int, bool> flag;
    bool canCross(vector<int>& stones) {   
        return dfs(0, stones, 0);
    }
    
    bool dfs(int position, vector<int>& stones, int jump){
        if(position == stones.size() - 1) return true;
        int key = stones[position] << 11 | jump;
        cout << key << endl;
        auto it = flag.find(key);
        if (it != flag.end()) return it->second;
        for(int i = position + 1; i < stones.size(); i++){
            int next_jump = stones[i] - stones[position];
            if(next_jump - jump < -1) continue;
            if(next_jump - jump > 1)  return flag[key] = false;
            if(dfs(i, stones, next_jump)) return true;
        }
        return false;
    }
    
};
