class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = "";
        int cnt = 0;
        while(true) {
            if(temp.size()>= b.size()) {
                if(temp.find(b) != string::npos) return cnt;
                temp +=a;
                if(temp.find(b)!= string::npos) return cnt+1;
                else return -1;
            }
            temp += a;
            cnt++;
        }
        return -1;
    }
};