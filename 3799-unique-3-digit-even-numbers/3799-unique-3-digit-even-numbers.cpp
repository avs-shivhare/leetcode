class Solution {
public:
    unordered_set<int> st;
    vector<int> taken;
    void find(int cnt,int el,vector<int> digit) {
        if(cnt == 3) {
            if(100 <= el && el <= 999 && (el&1) == 0) {
                st.insert(el);
            }
            return;
        }
        for(int i = 0; i<digit.size(); i++) {
            if(taken[i] == -1) {
                taken[i] = 0;
                find(cnt+1,el*10+digit[i],digit);
                taken[i] = -1;
            }
        }
        return;
    }
    int totalNumbers(vector<int>& digits) {
        taken.resize(11,-1);
        find(0,0,digits);
        return st.size();
    }
};