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
    ListNode* rev(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next!=NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL) return true;
        ListNode* mid = getMid(head);
        ListNode* temp = mid->next;
        mid->next = rev(temp); 
        ListNode* head1 = head;
        ListNode* head2 = mid->next;
        while(head2!=NULL){
            if(head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        mid->next = rev(mid->next); 
        return true;
    }
};