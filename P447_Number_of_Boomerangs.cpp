class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<int, int> m;
            for(int j = 0; j < points.size(); j++){
                if(j != i)
                    m[squareOfDistance(points[i], points[j])]++;
            }
            for(unordered_map<int,int>::iterator it = m.begin(); it != m.end(); it++){
                res += (it->second) * (it->second - 1);
            }
        }
        return res;
    }
    int squareOfDistance(vector<int> pointsA, vector<int> pointsB){
        return (pointsA[0] - pointsB[0])*(pointsA[0] - pointsB[0])+(pointsA[1] - pointsB[1])*(pointsA[1] - pointsB[1]); 
    }
};
