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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if(list1 == NULL) return list2;
        // if(list2 == NULL) return list1;
        ListNode* ans = new ListNode(-1);
        ListNode* ansTemp = ans;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                ansTemp->next = temp1;
                ansTemp = ansTemp->next;
                temp1 = temp1->next;
            }
            else{
                ansTemp->next = temp2;
                ansTemp = ansTemp->next;
                temp2 = temp2->next;
            }
        }
        while(temp1!=NULL){
            ansTemp->next = temp1;
            ansTemp = ansTemp->next;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            ansTemp->next = temp2;
            ansTemp = ansTemp->next;
            temp2 = temp2->next;
        }
        list1 = ans->next;
        return list1;
    }
};