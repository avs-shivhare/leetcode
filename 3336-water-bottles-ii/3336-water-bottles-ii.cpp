class Solution {
public:
    int maxBottlesDrunk(int n, int ex) {
        int empty = 0;
        int ans = 0;
        while(n || empty >= ex) {
            if(empty >= ex) {
                n++;
                empty -= ex;
                ex++;
            }
            else {
                ans += n;
                empty += n;
                n = 0;
            }
           // cout<<ans<<" "<<n<<" "<<empty<<endl;
        }
        return ans;
    }
};