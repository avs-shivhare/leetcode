class Node {
public:
    string val;
    Node* next;
    Node* prev;
    Node(string home) {
        val = home;
        next = NULL;
        prev = NULL;
    }
};
class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* s = new Node(url);
        s->prev = curr;
        curr->next = s;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev && steps--) {
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next && steps--) {
            curr= curr->next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */