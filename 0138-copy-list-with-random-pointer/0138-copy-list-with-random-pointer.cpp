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
        if(head == NULL) return head;
        Node* temp = head;
        while(temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp= temp->next->next;
        }
        temp = head;
        while(temp) {
            Node* copy = temp->next;
            if(temp->random) copy->random = temp->random->next;
            else copy->random = NULL;
            temp = temp->next->next;
        }
        temp = head;
        Node* temp2 = new Node(-1);
        Node* newHead = temp2;
        while(temp) {
            temp2->next = temp->next;
            temp->next = temp2->next->next;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return newHead->next;
    }
};