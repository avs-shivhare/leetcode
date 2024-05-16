class Solution {
public:
    
    vector<int> sequentialDigits(int low, int high) {
        string s = to_string(low);
        int n = s.size();
        vector<int> ans;
        long long temp = 0;
        char ch = s[0];
        do {
            if(s[0] == '9') {
                s = "";
                for(int i =1; i<=n+1; i++) {
                    s.push_back(i+'0');
                }
                n++;
            }
            else {
                string temp = "";
                for(int i =0; i<n; i++) {
                    temp.push_back(ch+i);
                }
                s = temp;
                ch = s[0]+1;
            }
            if(n > 9) return ans;
            temp = stoul(s);
        }
        while(temp < low);
        while(temp <= high) {
            ans.push_back(temp);
            //cout<<s<<endl;
            if(s[n-1] == '9') {
                s = "";
                for(int i =1; i<=n+1; i++) {
                    s.push_back(i+'0');
                }
                n++;
            }
            else {
                s.erase(s.begin());
                //cout<<s[n-2]+1<<endl;
                s.push_back(s[n-2]+1);
            }
            if(n > 9) return ans;
            temp = stoul(s);
        }
        return ans;
    }
};