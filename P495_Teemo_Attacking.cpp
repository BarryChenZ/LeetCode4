class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int tp = 0, pe = 0;
        for(int i = 0; i < timeSeries.size(); i++){
            tp += duration - (timeSeries[i] < pe) * (pe - timeSeries[i]);
            pe = timeSeries[i] + duration;
        }
        return tp;
    }
};
