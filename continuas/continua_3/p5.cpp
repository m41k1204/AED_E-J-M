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
    set<int> num;
    int numComponents(ListNode* head, vector<int>& nums) {
        for(auto x:nums){
            num.insert(x);
        }
        ListNode* cur = head;
        int res = 0;
        bool com = false;
        while(cur != nullptr){
            if(num.count(cur->val)){
                if(com == false){
                    res++;
                    com = true;
                }
            }
            else{
                com = false;
            }
            cur = cur->next;
        }
        return res;
    }
};
