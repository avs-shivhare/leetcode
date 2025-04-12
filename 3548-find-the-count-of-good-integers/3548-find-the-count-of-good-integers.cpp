class Solution {
public:
    unordered_set<string> st;
    unordered_map<int,int> mpp;
    vector<long long> fact;
    string temp = "";
    long long ans = 0;
    void find(int l,int r,int &k,int &n) {
        if(l > r) {
            //cout<<temp<<endl;
            string x = temp;
            sort(x.begin(),x.end());
            if(st.count(x) || stoll(temp)%k != 0) return;
            if(mpp[0] > 0) {
                long long t = 1;
                int cnt = 0;
                for(auto i: mpp) {
                    if(i.first == 0) cnt = i.second;
                    else {
                        t *= fact[i.second];
                    }
                }
                if(cnt > 1) ans += (fact[n]/(t*fact[cnt]))-(fact[n-1]/(t*(fact[cnt-1])));
                else ans += (fact[n]/(t*fact[cnt]))-(fact[n-1]/(t));
            }
            else {
                long long t = 1;
                for(auto i: mpp) {
                    t *= fact[i.second];
                }
                ans += fact[n]/t;
            }
            st.insert(x);
            return;
        }
        for(int i = 0; i<=9; i++) {
            if(l == 0 && i == 0) continue;
            temp[l] = i+'0';
            temp[r] = i+'0';
            if(l == r) mpp[i]++;
            else mpp[i] += 2;
            find(l+1,r-1,k,n);
            if(l == r) mpp[i]--;
            else mpp[i] -= 2;
            temp[l] = '0';
            temp[r] = '0';
        }
        return;
    }
    long long countGoodIntegers(int n, int k) {
        fact.resize(11,0);
        fact[0] = 1;
        for(int i = 1; i<=10; i++) {
            fact[i] = (long long)i*fact[i-1];
        }
        for(int i = 0; i<n; i++) {
            temp += '0';
        }
        find(0,n-1,k,n);
        return ans;
    }
};