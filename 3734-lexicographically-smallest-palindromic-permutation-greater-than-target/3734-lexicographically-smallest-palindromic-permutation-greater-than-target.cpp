class Solution {
public:
    bool check(int fre[]) {
        for(int i = 0; i<26; i++) {
            if(fre[i] < 0) return false;
        }
        return true;
    }
    string lexPalindromicPermutation(string s, string target) {
        int fre[26];
        memset(fre,0,sizeof(fre));
        for(auto &i: s) fre[i-'a']++;
        char c = '#';
        for(int i = 0; i<26; i++) {
            if(fre[i]&1) {
                if(c != '#') return "";
                c = i+'a';
                fre[i]--;
            }
        }
        int h = s.size()/2;
        for(int i = 0; i<h; i++) {
            fre[target[i]-'a'] -= 2;
        }
        if(check(fre)) {
            string f = target.substr(0,h);
            string r = f;
            reverse(r.begin(),r.end());
            if(c != '#') f += c;
            f += r;
            if(f > target) return f;
        }
        for(int i = h-1; i>=0; i--) {
            char t = target[i];
            fre[t-'a'] +=2;
            if(!check(fre)) continue;
            for(int j = t-'a'+1; j<26; j++) {
                if(!fre[j]) continue;
                string f = target.substr(0,i+1);
                f[i] = j+'a';
                fre[j] -= 2;
                for(int k = 0; k<26; k++) {
                    if(!fre[k]) continue;
                    int cnt = fre[k]>>1;
                    f.append(cnt,k+'a');
                }
                string r = f;
                if(c != '#') f += c;
                reverse(r.begin(),r.end());
                f += r;
                return f;
            }
        }
        return "";
    }
};