class Trie{
    public:
    vector<Trie*> next;
    Trie() {
        next.resize(2,NULL);
    }
};
class Solution {
public:
    Trie* root = new Trie();
    void add(int n) {
        Trie* temp = root;
        for(int i =30; i>=0; i--) {
            int bit = 0;
            if(n & (1<<i)) bit = 1;
            if(temp->next[bit] == NULL) temp->next[bit] = new Trie();
            temp = temp->next[bit];
        }
    }
    long long find(Trie* temp,int &n,int i,long long ans) {
        //cout<<n<<" "<<i<<" "<<ans<<endl;
        if(temp == NULL) return 0;
        if(i < 0 ) return ans;
        //if(dp[n][i] != -1) return dp[n][i];
        if(n & (1<<i)) {
            return find(temp->next[0],n,i-1,ans);
        }
        long long x = find(temp->next[1],n,i-1,ans|(1<<i));
        if(x != 0) return x;
        return find(temp->next[0],n,i-1,ans);
    }
    long long maxProduct(vector<int>& nums) {
        long long ans = 0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(auto i: st) {
            add(i);
        }
        for(auto i: st) {
            long long x = find(root,i,30,0);
            //cout<<i<<" "<<x<<endl;
            ans = max(ans,x*i);
        }
        return ans;
    }
};