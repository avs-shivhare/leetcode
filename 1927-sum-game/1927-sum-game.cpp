class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        bool flag = true;
        int ah = 0,bh = 0;
        int as = 0,bs = 0;
        int sum = 0,ssum = 0;
        for(int i = 0; i<n; i++) {
            if(i<n/2) {
                if(num[i] == '?') {
                    if(flag) ah++;
                    else bh++;
                    flag = !flag;
                }
                else sum += num[i]-'0';
            }
            else {
                if(num[i] == '?') {
                    if(flag) as++;
                    else bs++;
                    flag = !flag;
                }
                else ssum += num[i]-'0';
            }
        }
        //cout<<sum<<" "<<ssum<<endl;
        if(sum-(as*9) >= ssum-(bh*9) && sum+(ah*9) <= ssum+(bs*9)) return false;
        return true;
    }
};