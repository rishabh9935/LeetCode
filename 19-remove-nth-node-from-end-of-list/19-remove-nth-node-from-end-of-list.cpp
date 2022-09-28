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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* start = temp;
        ListNode* end = head;
        while(n--){
            end = end->next;
        }
        while(end){
            start = start->next;
            end = end->next;
        }
        if(start->next==head)return head->next;
        start->next = start->next->next;
        return head;
        
    }
};

