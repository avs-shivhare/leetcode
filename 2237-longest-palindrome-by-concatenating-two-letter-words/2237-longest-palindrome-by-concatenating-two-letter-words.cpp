class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp,notUse;
        int diff = 0;
        for(auto i: words) {
            if(i[0] == i[1]) {
                mpp[i]++;
            }
            else {
                string x = i;
                reverse(x.begin(),x.end());
                if(notUse.count(x)) {
                    diff++;
                    notUse[x]--;
                    if(notUse[x] == 0) notUse.erase(x);
                }
                else notUse[i]++;
            }
        }
        int odd = 0,even = 0;
        for(auto i: mpp) {
            even += i.second/2;
            odd += i.second%2;
        }
        int ans = even*4+diff*4;
        //cout<<even<<" "<<diff<<" "<<odd<<endl;
        if(odd) ans += 2;
        return ans;
    }
};