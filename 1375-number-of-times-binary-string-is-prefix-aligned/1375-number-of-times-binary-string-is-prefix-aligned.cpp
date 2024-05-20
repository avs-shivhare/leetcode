class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        string s = "";
        int n = flips.size();
        for(int i =0; i<n; i++) s+="0";
        int cnt = 0;
        for(int i =0; i<n; i++) {
            int x = flips[i];
            while(s[x-1] == '0') {
                int temp = flips[flips[x-1]-1];
                s[x-1] = '1';
                x = temp;
            }
            bool flag = true;
            for(int j =0; j<i; j++) {
                if(s[j] == '0') {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                for(int j =i+1; j<n; j++) {
                    if(s[j] == '1') {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};