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
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        ListNode* SeLast ;
        while(temp != NULL){
            node->val = temp->val;
            SeLast = node;
            node = node->next;
            temp = temp->next;
        }
        SeLast->next = NULL;
        // delete(node);
    }
};