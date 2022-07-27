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
    void reverse(ListNode* &head, ListNode* prev, ListNode* curr){
        if(curr == NULL) {
            head = prev;
            return;
        }
        ListNode* temp = curr->next;
        reverse(head, curr, temp);
        curr->next = prev;
    }
    
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        reverse(head, prev, curr);
        return head;
        
        
        // ListNode* prev = NULL;
        // ListNode* curr = head;
        // while(curr != NULL){
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        // }
        // return prev;
    }
};