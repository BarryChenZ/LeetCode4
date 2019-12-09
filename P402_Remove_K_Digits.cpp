class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        string res = "";
        
        for(char n : num){
            while(!res.empty() && n < res.back() && k > 0){
                res.pop_back();
                k--;
            }
            if(!res.empty() || n != '0') res.push_back(n);
        }
        while(!res.empty() && k--) res.pop_back();
        if(res == "") res = "0";
        return res;
    }
};
