class Solution {
public:
    bool check(string s,string next,int k) {
        int j = 0;
        int n = next.size();
        int cnt = 0;
        for(auto i: s) {
            if(next[j] == i) {
                j++;
                cnt += j/n;
                j %= n;
            }
        }
        return cnt >= k;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        q.push("");
        string ans = "";
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            for(char i = 'a'; i<='z'; i++) {
                string newCurr = curr+i;
                if(check(s,newCurr,k)) {
                    q.push(newCurr);
                    ans = newCurr;
                }
            }
        }
        return ans;
    }
};