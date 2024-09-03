class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for(auto i: s) {
            temp += to_string((i-'a')+1);
        }
        
        while(k--) {
            int ans = 0;
            for(auto i: temp) {
                ans += (i-'0');
            }
            temp = to_string(ans);
            // cout<<temp<<endl;
            // cout<<k<<endl;
        }
        return stoi(temp);
    }
};