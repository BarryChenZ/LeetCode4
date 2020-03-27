class Solution {
public:
    int findComplement(int num) {
        return Complement(num);            
    }
    int Complement(int num){
        vector<int> tmp;
        while(num > 1){
            tmp.push_back((num % 2 == 0) ? 1 : 0);
            num = num / 2;
        }
        int result = 0;
        for(int i = tmp.size()-1 ; i >= 0; i--){
            result += pow(2, i) * tmp[i];
        }
        return result;
    }
};
