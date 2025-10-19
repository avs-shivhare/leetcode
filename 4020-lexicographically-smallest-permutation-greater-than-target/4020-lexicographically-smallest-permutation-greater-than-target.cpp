class Solution {
public:
    vector<int> st;
    string ans = "";
    bool find(int i,string &target,bool flag) {
        if(i == target.size()) {
            if(ans > target) return true;
            return false;
        }
        if(flag) {
            for(int i = 0; i<26; i++) {
                while(st[i]) {
                    ans += i+'a';
                    st[i]--;
                }
            }
            return true;
        }
        else {
            if(st[target[i]-'a']) {
                ans.push_back(target[i]);
                st[target[i]-'a']--;
                if(find(i+1,target,flag)) return true;
                st[target[i]-'a']++;
                ans.pop_back();
            }
            for(int j = (target[i]-'a')+1; j<26; j++) {
                if(st[j]) {
                    ans.push_back(j+'a');
                    st[j]--;
                    if(find(i+1,target,true)) return true;
                    ans.pop_back();
                    st[j]++;
                }
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        st.resize(26,0);
        for(auto &i: s) st[i-'a']++;
        find(0,target,false);
        return ans;
    }
};