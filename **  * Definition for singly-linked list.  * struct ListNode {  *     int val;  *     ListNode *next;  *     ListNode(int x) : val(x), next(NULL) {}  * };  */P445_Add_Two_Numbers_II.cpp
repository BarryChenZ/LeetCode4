/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = l1;
        int size1 = 0;
        while(temp){
            size1++;
            temp = temp->next;
        }
        temp = l2;
        int size2 = 0, tmp;
        while(temp){
            size2++;
            temp = temp->next;
        }
        if(size1 >= size2)
            tmp = Adding(l1, l2, size1, size2);
        else
            tmp = Adding(l2, l1, size2, size1);
        temp = size1 >= size2 ? l1 : l2;
        if(tmp == 1){
            ListNode* newTop = new ListNode(tmp);
            newTop->next = temp;
            temp = newTop;
        }
        return temp;
    }
    int Adding(ListNode* Long, ListNode* Short, int sizeL, int sizeS){
        if(!Long && !Short) return 0;
        int temp, value, carry = 0;
        if(sizeL == sizeS){
            temp = Adding(Long->next, Short->next, sizeL-1, sizeS-1);
            value = Long->val + Short->val + temp;
        }   
        else{
            temp = Adding(Long->next, Short, sizeL-1, sizeS);
            value = Long->val + temp;
        }
        if(value >= 10){
            carry = 1;
            value -= 10;
        }
        Long->val = value;
        return carry;
    }
};
