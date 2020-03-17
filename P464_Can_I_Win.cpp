class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= 0) return true;
        if(desiredTotal > maxChoosableInteger * (maxChoosableInteger + 1) / 2) return false;
        int value = minimax(0, desiredTotal, 1, maxChoosableInteger, -2, 2);
        return (value == 1);
        
    }
    unordered_map<int, int> win;
    int minimax(int state, int total, int player, int maximum, int alpha, int beta){
        //cout << state << endl;
        if(win.find(state) != win.end()) return win[state];
        int value, i;
        if(player == 1){
            value = -2;
            for(i = 0; i < maximum; i++){
                
                if((((1 << i) & state) == 0) && total <= i + 1){
                    value = 1;   
                }     
            } 
            
            if(value == -2){
                for(i = 0; i < maximum; i++){
                    if(((1 << i) & state) == 0){
                        int tmp = minimax((state|(1<<i)), total - i - 1, !player, maximum, alpha, beta);
                        value = max(value, tmp);
                        alpha = max(alpha, value);
                        
                        if(value == 1) break;
                        if(alpha >= beta) break;
                    }
                }
            }
        }
        else{
            value = 2;
            for(i = 0; i < maximum; i++){
                
                if((((1<<i) & state) == 0) && total <= i + 1){
                    value = -1;
                }
            }
            if(value == 2){
                for(i = 0; i < maximum; i++){
                    if(((1 << i) & state) == 0){
                        int tmp = minimax((state | (1<<i)), total - i - 1, !player, maximum, alpha, beta);
                        value = min(value, tmp);
                        if(value == -1) break;
                        beta = min(beta, value);
                        if(beta <= alpha) break;
                    }
                }
            }
        }
        win[state] = value;
        return value;
    }
};
