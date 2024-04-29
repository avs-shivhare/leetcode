class Solution {
public:
    static bool compareS(int x,int y) {
        string t1 = to_string(x);
        string t2 = to_string(y);
        int val = t1.compare(t2);
        if(val < 0) return true;
        return false;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i =1; i<= n; i++) {
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),compareS);
        return ans;
    }
};