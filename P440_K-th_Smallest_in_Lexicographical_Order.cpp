class Solution {
public:
    int findKthNumber(int n, int k) {
        return dfs(1, k - 1, n);    
    }
    long long dfs(long long root, long long k, long long n){
        if(k == 0) return root;
        long long cnt = count_node(root, n);
        if(cnt > k){
            return dfs(root * 10, k - 1, n);   
        }
        else{
            return dfs(root + 1, k - cnt, n);
        }
    }
    long long count_node(long long root, long long n){
        long long cnt = 0;
        long long son = root + 1;
        while(root <= n) {
            cnt += min(son, n + 1) - root;
            root *= 10;
            son *= 10;
        }
        return cnt;  
    }
};
