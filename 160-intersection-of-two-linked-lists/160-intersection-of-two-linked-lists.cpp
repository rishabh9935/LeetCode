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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        // if(headA == headB) return headA;
        ListNode* ans = NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        map<ListNode*, int> mp;
        while(temp1!=NULL){
            mp[temp1]++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            if(mp.find(temp2) != mp.end()){
                ans = temp2;
                break;
            }
            temp2 = temp2->next;
        }
        // while(temp1 != NULL){
        //     while(temp2 != NULL){
        //         if(temp1 == temp2){
        //             ans = temp1;
        //             break;
        //         }
        //     }
        // }
        return ans;
    }
};