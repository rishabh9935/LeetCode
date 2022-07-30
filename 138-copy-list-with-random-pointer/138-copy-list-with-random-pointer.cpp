/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            if(cloneHead == NULL){
                cloneHead = newNode;
                cloneTail = newNode;
            }
            else{
                cloneTail->next = newNode;
                cloneTail = cloneTail->next;
            }
            temp = temp->next;
        }
        unordered_map<Node*, Node*> oldToNew;
        temp = head;
        Node* temp2 = cloneHead;
        while(temp!=NULL){
            oldToNew[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp = head;
        temp2 = cloneHead;
        while(temp!=NULL){
            temp2->random = oldToNew[temp->random];
            temp=temp->next;
            temp2 = temp2->next;
        }
        return cloneHead;
    }
};