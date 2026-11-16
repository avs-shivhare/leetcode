class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k) {
            string temp = "";
            int cnt = k;
            int sum = 0;
            for(auto &i: s) {
                sum += i-'0';
                cnt--;
                if(cnt == 0) {
                    temp += to_string(sum);
                    sum = 0;
                    cnt = k;
                }
            }
            if((int)s.size()%k != 0) temp += to_string(sum);
            s = temp;
        }
        return s;
    }
};