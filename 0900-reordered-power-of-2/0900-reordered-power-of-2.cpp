class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string x = to_string(n);
        sort(x.begin(),x.end());
        do {
            bool flag = true;
            if(x[0] == '0') flag = false;
            if(flag) {
                long long t = stoll(x);
                //cout<<t<<endl;
                if((t&(t-1)) == 0) return true;
            }
        }
        while(next_permutation(x.begin(),x.end()));
        return false;
    }
};