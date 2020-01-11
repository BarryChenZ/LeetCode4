class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0,j = 0;
        string res;
        bool carry = false;
        while(i < num1.size() || j < num2.size()){
            cout << i << j << endl;
            char num;
            int temp = 0;
            if(carry) temp = 1;
            if(i < num1.size() && j < num2.size()){
                if(num1[i] - '0' + num2[j] - '0' + temp >= 10){
                    carry = true;
                    num = '0' + (num1[i] - '0' + num2[j] - '0' + temp - 10);
                }
                else{
                    carry = false;
                    num = '0' + (num1[i] - '0' + num2[j] - '0' + temp);
                }
                cout << num1[i] - '0' + num2[j] - '0' + temp;
                res += num;
            }
            else if(i < num1.size() && j >= num2.size()){
                if(num1[i] - '0' + temp >= 10){
                    carry = true;
                    num = '0' + (num1[i] - '0' + temp - 10);
                }
                else{
                    carry = false;
                    num = '0' + (num1[i] - '0' + temp);
                }
                res += num;
            }
            else{
                if(num2[j] - '0' + temp >= 10){
                    carry = true;
                    num = '0' + (num2[j] - '0' + temp - 10);
                }
                else{
                    carry = false;
                    num = '0' + (num2[j] - '0' + temp);
                }
                res += num;
            }
            i++;
            j++;
        }
        if(carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
