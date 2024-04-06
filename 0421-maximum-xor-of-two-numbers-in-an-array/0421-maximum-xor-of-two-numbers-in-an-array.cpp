class Node {
    public:
        Node* link[2];
        bool isContain(int ind) {
            return link[ind];
        }
        void put(int ind,Node* temp) {
            link[ind] = temp;
        }
        Node* get(int ind) {
            return link[ind];
        }
};
class Trie {
    private:
        Node* root;
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
            int ans =0;
            Node* temp = root;
            for(int i =31; i>=0; i--) {
                int bit = 1-((num>>i)&1);
                if(temp->isContain(bit)) {
                    ans = (ans|(1<<i));
                    temp = temp->get(bit);
                }
                else {
                    temp = temp->get(1-bit);
                }
            }
            return ans; 
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* temp = new Trie();
        for(int i:nums) {
            temp->insert(i);
        }
        int ans = 0;
        for(int i: nums) {
            ans = max(ans,temp->maxXOR(i));
        }
        return ans;
    }
};