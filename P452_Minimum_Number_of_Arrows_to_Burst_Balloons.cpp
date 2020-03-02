class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(!points.size()) return 0;
        sort(points.begin(), points.end(), [](const vector<int> &a,const vector<int> &b){return a[1] < b[1] ;});
        int arrows = 0;
        int current = points[0][1];
        int next= 1;
        while(true){
            if(next >= points.size()){   
            //Account the last arrow.
            arrows++;
            break;
            }
            if(current < points[next][0]){//uncover
                arrows++;
                current = points[next][1];
            }
            next++;
        }
        return arrows;
    }
};
