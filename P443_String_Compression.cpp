class Solution {
public:
    int compress(vector<char>& chars) {
        //constant space
        for(int i = 0; i < chars.size(); i++){
            int j = i;
            while(j < chars.size() && chars[j] == chars[i]) ++j;
            --j;
            if (j != i) {
                string num = to_string(j-i+1);
                chars.erase(chars.begin()+i+1, chars.begin()+j+1);
                for (char c: num)
                    chars.insert(chars.begin()+ ++i, c);
            }
        }
        return chars.size();
    }
};
