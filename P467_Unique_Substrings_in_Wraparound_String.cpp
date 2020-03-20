class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> alphabet(26, 0);
        int ans = 0, i = 0, left = 0;
        while(i < p.size()){
            if(i + 1 == p.size() || (i + 1 < p.size() && (p[i] - 'a' + 1) % 26 != (p[i + 1] - 'a'))){
                for(int j = left; j <= i; j++){
                    alphabet[p[j] - 'a'] = max(alphabet[p[j]-'a'], i - j + 1); 
                }    
                left = i + 1;
            }
            i++;
        }
        for(int k = 0; k < 26; k++){
            ans += alphabet[k];
        }
        return ans;
    }
};
