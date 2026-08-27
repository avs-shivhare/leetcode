class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char,int> mpp;
        for(auto &i: s) {
            mpp[i]++;
        }
        int last = -1;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            auto x = mpp.upper_bound(target[i]);
            if(x != mpp.end()) last = i;
            if(mpp.find(target[i]) == mpp.end()) break;
            mpp[target[i]]--;
            if(mpp[target[i]] == 0) mpp.erase(target[i]);
        }
        if(last == -1) return "";
        string ans = "";
        mpp.clear();
        for(auto &i: s) mpp[i]++;
        //cout<<last<<endl;
        for(int i = 0; i<n; i++) {
            if(i<last) {
                ans += target[i];
                mpp[target[i]]--;
                if(mpp[target[i]] == 0) mpp.erase(target[i]);
            }
            else {
                auto x = mpp.upper_bound(target[i]);
                ans += x->first;
                char c = x->first;
                mpp[c]--;
                if(mpp[c] == 0) mpp.erase(c);
                break;
            }
        }
        for(auto &i: mpp) {
            int el = i.second;
            while(el-- > 0) {
                //cout<<el<<" "<<i.first<<endl;
                ans += i.first;
            }
        }
        return ans;
    }
};