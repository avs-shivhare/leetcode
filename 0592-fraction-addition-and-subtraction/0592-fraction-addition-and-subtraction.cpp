class Solution {
public:
    int hcf(int x,int y) {
        if(x == 0) return y;
        if(y == 0) return x;
        if(x > y) return hcf(x%y,y);
        return hcf(x,y%x);
    }
    string fractionAddition(string exp) {
        int n = exp.size();
        int no = 0,dn = 1;
        int i =0;
        while(i<n) {
            bool first = false,second = false;
            if(i<n && (exp[i] == '-'|| exp[i] == '+')) {
                if(exp[i] == '-') first = true;
                i++;
            }
            int x =0;
            while(i<n && '0' <= exp[i] && exp[i] <= '9') {
                x = x*10+(exp[i]-'0');
                i++;
            }
            if(first) x *= -1;
            i++;
            if(i<n && exp[i] == '-') {
                second = true;
                i++;
            }
            int y = 0;
            while(i<n && '0' <= exp[i] && exp[i] <= '9') {
                y = y*10+(exp[i]-'0');
                i++;
            }
            if(second) y *= -1;
            int lcm = (y*dn)/(hcf(abs(y),dn));
            no = ((lcm/y)*x+((lcm/dn)*no));
            dn = lcm;
            cout<<x<<" "<<y<<endl;
        }
        int temp = hcf(dn,abs(no));
        dn /= temp;
        no /= temp;
        string ans = to_string(no)+"/"+to_string(dn);
        return ans;
    }
};