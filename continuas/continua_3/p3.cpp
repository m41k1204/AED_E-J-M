/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * temp = head;
        int mitad = 0;
        
        while (temp != nullptr) {
            temp = temp -> next;
            mitad++;
        }

        if (mitad%2 == 0){ mitad = mitad/2 ;}
        else {mitad = mitad / 2 ;};
        
        temp = head;
        while (mitad != 0) {
            temp = temp -> next;    
            --mitad;
        }
        return temp;
    }
};
