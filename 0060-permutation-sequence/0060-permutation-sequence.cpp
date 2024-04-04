class Solution {
public:
    // void f(int ind,int &n,string &s,set<string> &ans) {
    //     if(ind == n) {
    //         ans.insert(s);
    //         return;
    //     }
    //     for(int i =ind; i<n; i++) {
    //         swap(s[i],s[ind]);
    //         f(ind+1,n,s,ans);
    //         swap(s[i],s[ind]);
    //     }
    //     return;
    // }
    // string getPermutation(int n, int k) {
    //     string s = "";
    //     for(int i=1; i<=n; i++) {
    //         s+= to_string(i);
    //     }
    //     int siz = s.size();
    //     set<string> ans;
    //     f(0,siz,s,ans);
    //     auto it = ans.begin();
    //     advance(it,k-1);
    //     return *it;
    // }

    string getPermutation(int n, int k) {
        vector<int> per;
        int fact = 1;
        for(int i=1; i<n; i++) {
            fact *= i;
            per.push_back(i);
        }
        per.push_back(n);
        string ans = "";
        k = k-1;
        while(true) {
            ans += to_string(per[k/fact]);
            per.erase(per.begin()+(k/fact));
            k = k%fact;
            if(per.size() == 0) break;
            fact /= per.size();
        }
        return ans;
    }
};