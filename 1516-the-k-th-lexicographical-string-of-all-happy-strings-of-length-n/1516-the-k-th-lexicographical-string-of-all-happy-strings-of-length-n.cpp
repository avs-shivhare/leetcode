class Solution {
public:
    int cnt = 0;
    string ans = "";
    bool find(int i,int &n,int &k) {
        if(i == n) {
            cnt++;
            if(cnt == k) return true;
            return false;
        }
        for(char j = 'a'; j<='c'; j++) {
            if(i == 0) {
                ans.push_back(j);
                if(find(i+1,n,k)) return true;
                ans.pop_back();
            }
            else if(ans.back() != j) {
                ans.push_back(j);
                if(find(i+1,n,k)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        find(0,n,k);
        return ans;
    } 
};