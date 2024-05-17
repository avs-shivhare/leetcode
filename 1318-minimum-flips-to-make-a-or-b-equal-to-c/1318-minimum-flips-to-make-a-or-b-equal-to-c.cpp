class Solution {
public:
    int minFlips(int a, int b, int c) {
        int Or = a | b;
        int ans = 0;
        for(int i =0; i<32; i++) {
            if(((c & (1<<i)) == 0 && (Or & (1<<i)) == 0) || ((c & (1<<i)) >=1 && (Or & (1<<i)) >= 1)) continue;
            else {
                //cout<<c<<endl;
                if((c & (1<<i)) >= 1) {
                    //cout<<"done"<<endl;
                    ans++;
                }
                else {
                    if((a & (1<<i)) >= 1) ans++;
                    if((b & (1<<i)) >= 1) ans++;
                }
            }
            //cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};