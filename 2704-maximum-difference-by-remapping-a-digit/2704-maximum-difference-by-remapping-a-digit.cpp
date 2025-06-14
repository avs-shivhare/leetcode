class Solution {
public:
    int minMaxDifference(int num) {
        string temp = to_string(num);
        string x = temp;
        string y = temp;
        char t = 'a';
        for(int i = 0; i<x.size(); i++) {
            if(x[i] != '9' && t == 'a') t = x[i];
            if(x[i] == t) x[i] = '9';
        }
        t = 'a';
        for(int i = 0; i<y.size(); i++) {
            if(y[i] != '0' && t == 'a') t = y[i];
            if(y[i] == t) y[i] = '0';
        }
        long long maxi = stoll(x);
        long long mini = stoll(y);
        //cout<<x<<" "<<y<<endl;
        return maxi-mini;
    }
};