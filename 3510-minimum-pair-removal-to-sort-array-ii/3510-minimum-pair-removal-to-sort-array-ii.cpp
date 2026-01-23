class Node {
public:
    long long val;
    int ind;
    Node* next;
    Node* prev;
    Node(int n,int i) {
        val = n;
        ind = i;
        next = NULL;
        prev = NULL;
    }
};
class Solution {
public:
    Node* findPrev(Node* back) {
        if(back == NULL) return back;
        return back->prev;
    }
    Node* findNext(Node* front) {
        if(front == NULL) return front;
        return front->next;
    }
    int minimumPairRemoval(vector<int>& nums) {
        Node* front = new Node(-1,2);
        Node* back = front;
        int n = nums.size();
        set<pair<pair<long long,int>,pair<Node*,Node*>>> st;
        multiset<vector<long long>> p;
        for(int i = 0; i<n; i++) {
            Node* curr = new Node(nums[i],i);
            if(i>0) {
                st.insert({{nums[i]+nums[i-1],i-1},{back,curr}});
                if(nums[i-1] > nums[i]) p.insert({nums[i-1],nums[i]});
            }
            curr->prev = back;
            back->next = curr;
            back = curr;
        }
        Node* next = findNext(front);
        next->prev = NULL;
        front = next;
        int ans = 0;
        while(!p.empty() && !st.empty()) {
            //cout<<p.size()<<" "<<st.size()<<endl;
            auto q = *(st.begin());
            Node* first = q.second.first;
            Node* second = q.second.second;
            int ind = q.first.second;
            long long f = first->val;
            long long s = second->val;
            auto x = p.find({f,s});
            if(x != p.end()) {
                p.erase(x);
            }
            Node* prev = findPrev(first);
            Node* next = findNext(second);
            if(prev && prev->val > first->val) {
                x = p.find({prev->val,first->val});
                if(x != p.end()) {
                    p.erase(x);
                }
            }
            if(next && second->val > next->val) {
                x = p.find({second->val,next->val});
                if(x != p.end()) p.erase(x);
            }
            if(prev) {
                st.erase({{prev->val+first->val,prev->ind},{prev,first}});
            }
            if(next) {
                st.erase({{second->val+next->val,second->ind},{second,next}});
            }
            first->val += second->val;
            if(prev && prev->val > first->val) {
                p.insert({prev->val,first->val});
            }
            if(next && first->val > next->val) {
                p.insert({first->val,next->val});
            }
            if(next) next->prev = first;
            first->next = next;
            st.erase(q);
            if(prev) st.insert({{prev->val+first->val,prev->ind},{prev,first}});
            if(next) st.insert({{first->val+next->val,first->ind},{first,next}});
            ans++;
        }
        return ans;
    }
};