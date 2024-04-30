class Solution {
public:
    // long long wonderfulSubstrings(string word) {
    //     int n = word.size();
    //     long long cnt = 0;
    //     for(int i =0; i<n; i++) {
    //         vector<int> fre(26,0);
    //         vector<int> fre2(26,0);
    //         int left = i-1;
    //         int right = i+1;
    //         cnt++;
    //         fre[word[i]-'a']++;
    //         //fre2[word[i]-'a']++;
    //         cout<<cnt<<" "<<i<<endl;
    //         while(left >= 0 && right <n) {
    //             fre[word[left]-'a']++;
    //             fre[word[right]-'a']++;
    //             int odd = 0;
    //             for(int x = word[left]-'a'; x<=word[right]-'a'; x++) {
    //                 if(fre[x]%2 == 1) odd++;
    //                 cout<<fre[x]<<" "<<endl;
    //             }
    //             if(odd == 1) {
    //                 cnt++;
    //                 cout<<"Done"<<endl;
    //             }
    //             left--;
    //             right++;
    //             cout<<cnt<<" "<<i<<endl;
    //         }
    //         left = i;
    //         right = i+1;
    //         while(left>=0 && right<n) {
    //             fre2[word[left]-'a']++;
    //             fre2[word[right]-'a']++;
    //             int odd = 0;
    //             for(int x = word[left]-'a'; x<=word[right]-'a'; x++) {
    //                 if(fre2[x]%2 == 1) odd++;
    //             }
    //             if(odd == 1) {
    //                 cnt++;
    //                 cout<<"Done"<<endl;
    //             }
    //             left--;
    //             right++;
    //             cout<<cnt<<" "<<i<<endl;
    //         }
    //     }
    //     return cnt;
    // }

    long long wonderfulSubstrings(string word) {
        int n = word.size();
        long long cnt = 0;
        vector<int> count(1024,0);
        count[0] = 1;
        int xOR = 0;
        for(char i: word) {
            xOR ^= 1<<(i-'a');
            cnt += count[xOR];
            for(int i =0; i<10; i++) {
                cnt+= count[xOR^(1<<i)];
            }
            count[xOR]++;
        }
        return cnt;
    }
};