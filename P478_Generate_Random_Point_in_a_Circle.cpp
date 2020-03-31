class Solution {
private:
    double x, y, r;
public:
    
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
    }
    
    vector<double> randPoint() {
        while(true){
            cout << 2.0 * 1.0 * rand() / RAND_MAX << endl;// 0-1->0-2->-1~1
            double x1 = (2.0 * 1.0 * rand() / RAND_MAX - 1.0) * r;
            double y1 = (2.0 * 1.0 * rand() / RAND_MAX - 1.0) * r;
            if(x1 * x1 + y1 * y1 <= r * r) return {x + x1, y + y1};
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
