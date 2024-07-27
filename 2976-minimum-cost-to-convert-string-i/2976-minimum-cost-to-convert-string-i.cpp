class Solution {
public:
    long long minimumCost(string sr, string tr, vector<char>& org, vector<char>& ch, vector<int>& cost) {
        vector<vector<long long>> dist(26,vector<long long>(26,1e12));
        long long ans =0;
        int n = org.size();
        for(int i =0; i<n; i++) {
            dist[org[i]-'a'][ch[i]-'a'] = min(dist[org[i]-'a'][ch[i]-'a'],(long long)cost[i]);
        }
        for(int i =0; i<26; i++) dist[i][i] =0;
        for(int k =0; k<26; k++) {
            for(int i =0; i<26; i++) {
                for(int j =0; j<26; j++) {
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        n = sr.size();
        for(int i =0; i<n; i++) {
            if(dist[sr[i]-'a'][tr[i]-'a'] >= 1e12) return -1;
            ans += dist[sr[i]-'a'][tr[i]-'a'];
        }
        return ans;
    }
};