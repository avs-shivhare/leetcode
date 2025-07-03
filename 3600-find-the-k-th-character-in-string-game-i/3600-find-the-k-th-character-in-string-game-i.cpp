class Solution {
public:
    char kthCharacter(int k) {
        k--;
        int last = 0;
        for(int i = 31; i>=0; i--) {
            if(k&(1<<i)) {
                last = 1<<(i+1);
                break;
            }
        }  
        int cnt = 0;
        while(k) {
            int temp = last/2;
            cnt +=k/temp;
            k %= temp;
            last = temp;
        }
        return (cnt%26)+'a';
    }
};