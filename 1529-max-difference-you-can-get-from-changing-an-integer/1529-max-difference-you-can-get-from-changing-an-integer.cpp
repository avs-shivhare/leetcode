class Solution {
public:
    int maxDiff(int num) {
        if(0<= num && num <= 9) return 8;
        string temp = to_string(num);
        string a = temp;
        char x = 'a';
        for(int i = 0; i<a.size(); i++) {
            if(a[i] != '9' && x == 'a') x = a[i];
            if(x == a[i]) {
                a[i] = '9';
            }
        }
        if(temp[0] > '1') {
            for(int i = 1; i<temp.size(); i++) {
                if(temp[i] == temp[0]) temp[i] = '1';
            }
            temp[0] = '1';
        }
        else {
            x = 'a';
            for(int i = 1; i<temp.size(); i++) {
                if(temp[i] != '0' && x == 'a' && temp[0] != temp[i]) x = temp[i];
                if(x == temp[i]) temp[i] = '0';
            }
        }
        cout<<a<<" "<<temp<<endl;
        long long p = stoll(a);
        long long y = stoll(temp);
        return p-y;
    }
};