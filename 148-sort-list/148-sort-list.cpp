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
    ListNode* merge(ListNode* left, ListNode* right){
        // if(left == NULL) return right;
        // if(right == NULL) return left;
        ListNode* ans = new ListNode(-1);
        ListNode* ansTail = ans;
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                // ListNode* newNode = new ListNode(left->val);
                ansTail->next = left;
                ansTail = left;
                left = left->next;
            }
            else{
                // ListNode* newNode = new ListNode(right->val);
                ansTail->next = right;
                ansTail = right;
                right = right->next;
            }
        }
        while(left!=NULL){
            ansTail->next = left;
            ansTail = left;
            left = left->next;
        }
        while(right!=NULL){
            ansTail->next = right;
            ansTail = right;
            right = right->next;       
        }
        ans = ans->next;
        return ans;
    }
    
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* mid = findMid(head);
        
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode* res = merge(left, right);
        return res;
    }
};