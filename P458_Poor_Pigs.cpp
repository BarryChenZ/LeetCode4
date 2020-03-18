class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int x = 0;
        int T = minutesToTest/minutesToDie;
        
        while(true){
            if(pow((T+1),x) >= buckets) break;
            x++;
        }
        return x;
    }
};
