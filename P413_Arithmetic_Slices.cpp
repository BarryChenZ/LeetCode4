//等差，找最長
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        vector<int>   dp(A.size() + 1, 0);
        int max = 0;
        vector<int> front(A.size() - 1, 0);
        for(int i = 0; i < A.size() - 1; i++){
            front[i] = A[i + 1] - A[i];
        }
        
        for(int i = 0; i < A.size() - 1; ){
            cout << i;
            int counter = 1;
            int difference = front[i];
            for(int j = i + 1; j < A.size(); j++){
                if(A[j] - A[j - 1] == difference) counter++;
                else break;
            }
            if(counter >= 3){
                for(int k = 3; k <= counter; k++) max += counter + 1 - k;
                i = i + counter - 1;
            }
            else i++;   
        }
        return max;
    }
};  
