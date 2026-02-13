class Solution {
public:
    int find(string &s,char a,char b) {
        int n = s.size();
        unordered_map<int,int> mpp;
        int sum = 0;
        mpp[0] = -1;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == a) sum++;
            else if(s[i] == b) sum--;
            else {
                mpp.clear();
                mpp[0] = i;
                sum = 0;
            }
            if(mpp.find(sum) != mpp.end()) {
                ans = max(ans,i-mpp[sum]);
            }
            else mpp[sum] = i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.size();
        int cnt = 0;
        char el = 'a';
        for(auto &i: s) {
            if(i == el) cnt++;
            else {
                el = i;
                cnt = 1;
            }
            ans = max(ans,cnt);
        }
        ans = max(ans,find(s,'a','b'));
        ans = max(ans,find(s,'b','c'));
        ans = max(ans,find(s,'a','c'));
        map<pair<int,int>,int> mpp;
        vector<int> fre(3,0);
        mpp[{0,0}] = -1;
        for(int i = 0; i<n; i++) {
            fre[s[i]-'a']++;
            int sum1 = fre[0]-fre[1];
            int sum2 = fre[1]-fre[2];
            //cout<<i<<" "<<temp[0]<<" "<<temp[1]<<endl;
            if(mpp.find({sum1,sum2}) != mpp.end()) {
                ans = max(ans,i-mpp[{sum1,sum2}]);
            }
            else mpp[{sum1,sum2}] = i;
        }
        return ans;
    }
};