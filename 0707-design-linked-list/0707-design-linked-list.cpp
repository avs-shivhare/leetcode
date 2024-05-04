class MyLinkedList {
public:
    vector<int> ans;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        //for(int i: ans) cout<<i<<endl;
        if(index < ans.size()) {
            return ans[index];
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ans.insert(ans.begin(),val);
    }
    
    void addAtTail(int val) {
        ans.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > ans.size()) return;
        else if(index == ans.size()) {
            ans.push_back(val);
            return;
        }
        ans.insert(ans.begin()+index,val);
    }
    
    void deleteAtIndex(int index) {
        if(index >= ans.size()) return;
        ans.erase(ans.begin()+index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */