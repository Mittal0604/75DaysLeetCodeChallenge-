class Node {
public:
    string val;
    Node* next;
    Node* prev;
    Node(string val) {
        this->val = val;next = nullptr; prev = nullptr;
    }
};
class BrowserHistory {
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        if (curr->next != nullptr) curr->next->prev = nullptr;
        // Node* second = curr->next;
        curr->next = newNode;
        newNode->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while (steps>0 && curr->prev != nullptr) {
            steps--;
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while (steps>0 && curr->next != nullptr) {
            steps--;
            curr = curr->next;
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