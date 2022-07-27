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
    ListNode* race(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        if(head->next->next == NULL) return head->next;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL) fast = fast->next;
            slow = slow->next;
        }
        return slow;
    } 
    
    int getLen(ListNode* head){
        int cnt = 0;
        while(head!=NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode* middleNode(ListNode* head) {
        return race(head);
        /*
        int length = getLen(head);
        int mid = length/2;
        ListNode* temp = head;
        int cnt = 0;
        while(cnt!=mid){
            temp = temp->next;
            cnt++;
        }
        return temp; */
    }
};