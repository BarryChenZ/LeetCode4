class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for(int i = 0; i < houses.size(); i++){
            int tmp = findMin(heaters, houses[i]);
            cout << tmp << endl;
            ans = max(ans, tmp);
        }
        return ans;
    }
    int findMin(vector<int>& heaters, int position){//binary search
        int minDis = INT_MAX;
        int i = 0;
        int j = heaters.size() - 1;
        while(i <= j){
            int k = (i + j) / 2;
            int tmp = abs(position - heaters[k]);
            if(tmp < minDis) minDis = tmp;
            
            if(heaters[k] >= position) j = k - 1;//找更小
            else if(heaters[k] < position) i = k + 1;//找更大
        }
        return minDis;
    }
};
