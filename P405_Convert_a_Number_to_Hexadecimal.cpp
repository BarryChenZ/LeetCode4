class Solution {
public:
    char c[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    string toHex(int num) {
        //10 to 2
        //2 to 16
        // 2 complement
        bool tmp = num >= 0 ? 0 : 1; //0 pos , 1 nega
        vector<int> vec; 
        ten_to_two(vec, num);
        if(tmp == 1) two_complement(vec);
        
        int supplement = vec.size() % 4 == 0 ? 0 : 4 - vec.size() % 4;
        for(int i = 0; i < supplement; i++) 
            vec.insert(vec.begin(), 0);
        
        string res = two_to_hex(vec);
        return res;
    }
    
    
    void ten_to_two(vector<int>& vec, int num){
        while(num != 0){
            vec.insert(vec.begin(), num % 2);
            num = num / 2 ;
        }
    }
    void two_complement(vector<int>& vec){
        int n = vec.size();
        while(n < 32){
            vec.insert(vec.begin(), 0);
            n++;
        }
        int temp = 1;
        for(int i = n - 1; i >= 0; i--){
            vec[i] = (vec[i] == 0) ? 1 : 0;
            if(vec[i] == 1 && temp == 1){
                vec[i] = 0;
                temp = 1;
            }
            else if(vec[i] == 0 && temp == 1){
                vec[i] = temp;
                temp = 0;
            }
            else{
                vec[i] = vec[i];
                temp = 0;
            }
        }
        return;
    }
    string two_to_hex(vector<int>& vec){
        string res;
        for(int i = 0; i < vec.size(); i = i + 4){
            int number = 0;
            for(int j = 0; j < 4; j++){
                number += pow(2, 3 - j)*vec[i + j];
            }
            res += c[number];
        }
        return res.empty() ? "0" : res;
    }
};

/*
// fast solution
class Solution {
public:
    string toHex(int num) {
        unsigned int ourNum = num;
        // Implicitly cast negative numbers.
        // -1 turns to the maximum number representable
        // as an unsigned int.
        
        string str; // Our result
        char ourArray[17] = "0123456789abcdef"; // We will pick from this set of characters

        // While our number exists, convert it into base 16.
        // We are going from left to right, so we need to reverse our result
        // when we return it.
        do {
            str += ourArray[ourNum % 16];
            ourNum /= 16;
        } while (ourNum); 

        return {str.rbegin(), str.rend()};
    }
};
*/
