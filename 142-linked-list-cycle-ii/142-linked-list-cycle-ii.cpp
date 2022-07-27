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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        map<ListNode*, bool> vis;
        ListNode* temp = head;
        while(temp!=NULL){
            if(vis[temp] == true) return temp;
            vis[temp] = true;
            temp = temp->next;
        }
        return NULL;
    }
};