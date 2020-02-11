class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        if(s.size() == 0) return 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                count++;
                while(i < s.size()){
                    if(s[i] != ' ') i++;
                    else break;
                }
                i--;
            }
        }
        return count;
    }
};
