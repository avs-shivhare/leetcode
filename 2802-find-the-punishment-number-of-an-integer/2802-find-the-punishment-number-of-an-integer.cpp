class Solution {
public:
    string temp = "";
    bool check(int i,string &s,int sum,int &target) {
        //cout<<temp<<" "<<sum<<" "<<target<<endl;
        if(i == s.size()) {
            if(!temp.empty()) sum += stoi(temp);
            if(sum == target) return true;
            return false;
        }
        string x = temp;
        temp = s[i];
        bool flag = false;
        flag = check(i+1,s,sum+(x.empty()?0:stoi(x)),target);
        temp = x;
        temp += s[i];
        flag |= check(i+1,s,sum,target);
        temp.pop_back();
        return flag;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i<=n; i++) {
            long long x = (long long)i*(long long)i;
            string s = to_string(x);
            //cout<<i<<" -> "<<x<<endl;
            if(check(0,s,0,i)) ans += x;
        }
        return ans;
    }
};