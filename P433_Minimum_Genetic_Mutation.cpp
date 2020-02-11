class Solution {
private:
    bool isAdjacent(string a , string b){
        int count = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) count++;
            if(count > 1) break;
        }
        if(count == 1) return true;
        return false;
        
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> s;
        set<string>::iterator it;
        //刪掉重複
        for(int i = 0; i < bank.size(); i++){
            s.insert(bank[i]);
        }
        if(!s.count(end)) return -1;
        
        queue<pair<string, int>> q;
        q.push(make_pair(start, 0));
        if(s.find(start) != s.end()) s.erase(start);
        
        while(!q.empty()){
            pair<string, int> currWord = q.front();
            q.pop();
            
            for(it = s.begin(); it != s.end(); it++){
                string temp = *it;
                if(isAdjacent(currWord.first, temp)){
                    q.push(make_pair(temp, currWord.second + 1));
                    s.erase(temp);
                    
                    if(temp == end) {
                        return currWord.second + 1;
                    }
                }
            }
        }
        return -1;
    }
};
