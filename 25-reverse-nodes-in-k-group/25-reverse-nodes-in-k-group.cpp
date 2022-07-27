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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        ListNode* curr = head;
        ListNode* tr = head;
        int cnt = 0;
        int cnt1 = 0;
        while(tr != NULL){
            tr = tr->next;
            cnt1++;
        }
        if(cnt1 < k) return head;
        while(curr != NULL && cnt<k){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }
        if(temp != NULL){
            head->next = reverseKGroup(temp, k);
        }
        return prev;
    }
};