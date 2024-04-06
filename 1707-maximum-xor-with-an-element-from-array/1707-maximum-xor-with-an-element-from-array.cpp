class Node {
    Node* link[2];
    public:
    bool isContain(int ind) {
        return link[ind] != NULL;
    }
    void put(int ind,Node* temp) {
        link[ind] = temp;
    }
    Node* get(int ind) {
        return link[ind];
    }
};
class Trie {
    private: Node* root;
    public:
        Trie() {
            root = new Node();
        }
        void insert(int num) {
            Node* temp = root;
            for(int i =31; i>=0; i--) {
                int bit = (num>>i)&1;
                if(!temp->isContain(bit)) {
                    temp->put(bit,new Node());
                }
                temp = temp->get(bit);
            }
        }
        int maxXOR(int num) {
            int ans = 0;
            Node* temp = root;
            for(int i =31; i>=0; i--) {
                int bit = 1-((num>>i)&1);
                if(temp && temp->isContain(bit)) {
                    ans = ans|(1<<i);
                    temp = temp->get(bit);
                }
                else if(temp) temp = temp->get(1-bit);
            }
            return ans;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* root = new Trie();
        sort(nums.begin(),nums.end());
        int m = queries.size();
        int n = nums.size();
        vector<pair<int,pair<int,int>>> q;
        for(int i =0;i<m; i++) {
            q.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(q.begin(),q.end());
        vector<int> ans(m,0);
        int idx = 0;
        for(auto i: q) {
            int xi = i.second.first;
            int mi = i.first;
            int ind = i.second.second;
            while(idx<n && nums[idx] <= mi) {
                root->insert(nums[idx]);
                idx++;
            }
            if(idx == 0) ans[ind] = -1;
            else ans[ind] = root->maxXOR(xi);
        }
        return ans;
    }
};