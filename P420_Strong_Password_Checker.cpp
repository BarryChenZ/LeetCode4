
// O(N) single-pass solution.
// Key is to recognise changes can simultaneously satisfy multiple conditions at the same time.

#include <string>

using namespace std;

constexpr inline int maxlen = 20;
constexpr inline int minlen = 6;

class Solution {
public:    
    int strongPasswordChecker(string s) {
        int type1=0, type2=0, type3=0;
        
        char prev_char = 0;
        int cur_seq_len = 0;
        
        // A sequence is a contiguous series of the same char. 
        // To fix a sequence to satisfy condition #3, we either delete chars from the sequence, insert chars or replace certain chars in the sequence.
        // The min # of chars to replace is floor(sequence_length / 3).
        // count_seq_mod[i] = # times we can delete (i+1) chars from any sequence so as to reduce the replacement count by 1
        int count_seq_mod[3] = {0};
        
        int replacements = 0;
        
        for (char c: s) {
            if ('a' <= c && c <= 'z') type1=1;
            else if ('A' <= c && c<= 'Z') type2=1;
            else if ('0' <= c&& c <= '9') type3=1;
            
            if (prev_char != c){
                if (cur_seq_len >= 3) {
                    if (cur_seq_len % 3 != 2)
                        count_seq_mod[cur_seq_len % 3]++;
                    
                    count_seq_mod[2] += (cur_seq_len - 2) / 3;
                }
                // we need this min # replacement to fix the sequence
                replacements += cur_seq_len / 3;
                cur_seq_len = 1;
            }
            else {
                cur_seq_len ++;
            }
            
            prev_char = c;
        }    
        
        // End the current sequence. 
        if (cur_seq_len >= 3) {
            if (cur_seq_len % 3 != 2)
                count_seq_mod[cur_seq_len % 3]++;

            count_seq_mod[2] += (cur_seq_len - 2) / 3;
        }
        replacements += cur_seq_len / 3;
        
        int type_count = type1+type2+type3;
        replacements = max(3 - type_count, replacements);
        
        if (s.size() < minlen){
            // Just need to insert or replace chars.
            // Inserting chars can be used instead of replacement to fix sequences and to fulfil the 3 types, hence we use 'max'.
            return max(replacements, minlen - (int)s.size());
        }
        else if (s.size() <= maxlen){
              
            // Maintain the string length and replace min # chars to fix the sequences
            // and to fulfil the 3 types
            return replacements;
        }

        // We must delete this number of chars to fit within maxlen.
        const int deletes = s.size() - maxlen;

        // Since we must delete, we might as well use them to fix sequences and thereby reducing # replacements needed.
        
        int deletes_used = 0;
        
        for (int i = 1; i <= 3; i++){
            int reduced_replacements = min((deletes - deletes_used) / i, count_seq_mod[i - 1]);
            replacements -= reduced_replacements;
            deletes_used += reduced_replacements * i;            
        }

        return deletes + max(3-type_count, replacements);
    }
};
