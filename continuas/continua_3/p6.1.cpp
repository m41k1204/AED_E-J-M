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
    int cont[20005];
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = 0; i<20004;i++){
            cont[i] = 0;
        }
        for(auto v:lists){
            ListNode* head = v;
            while(head!= nullptr){
                cont[head->val + 10000]++;
                head = head->next;
            }
        }
        ListNode* prev = new ListNode();
        ListNode* head = nullptr;
        bool first = true;
        for(int i = 0; i<20004;i++){
            while(cont[i]--){
                ListNode* a = new ListNode(i-10000);
                prev->next = a;
                prev = a;
                if(first){
                    head = prev;
                    first = !first;    
                }
            }
        }
        return head;
    }
};
