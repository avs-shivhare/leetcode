class Bank {
public:
    vector<long long> ans;
    int n;
    Bank(vector<long long>& balance) {
        ans = balance;
        n = ans.size();
    }
    
    bool transfer(int ac1, int ac2, long long m) {
        ac1--;
        ac2--;
        if(ac1 < 0 || ac1 >= n || ac2 < 0 || ac2 >= n) return false;
        if(ans[ac1] >= m) {
            ans[ac2] += m;
            ans[ac1] -= m;
            return true;
        }
        return false;
    }
    
    bool deposit(int ac, long long m) {
        ac--;
        if(ac < 0 || ac >= n) return false;
        ans[ac] += m;
        return true;
    }
    
    bool withdraw(int ac, long long m) {
        ac--;
        if(ac < 0 || ac >= n || ans[ac] < m) return false;
        ans[ac] -= m;
        return true; 
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */