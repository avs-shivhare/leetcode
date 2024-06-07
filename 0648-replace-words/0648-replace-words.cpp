// Tries class or structure for solving this problem
class Tries {
    public:
    char val;
    vector<Tries*> point;
    bool isEnd;
    Tries(char x) {
        val = x;
        point.resize(26,NULL);
        isEnd = false;
    }
};
class Solution {
public:
    // initialize root and add any character 
    Tries* root = new Tries('A');
    
    // add function add give word into tries and at the end mark isEnd to true that was helpfull for finding the shortest length prefix
    void add(string word) {
        Tries* temp = root;
        int n = word.size();
        for(int i =0; i<n; i++) {
            if(temp->point[word[i]-'a'] == NULL) {
                temp->point[word[i]-'a'] = new Tries(word[i]);
            }
            temp = temp->point[word[i]-'a'];
        }
        temp->isEnd = true;
    }
    
    // this search function efficiently find prefix of give word and return it
    string search(string word) {
        Tries* temp = root;
        int n = word.size();
        string ans = "";
        for(int i =0; i<n; i++) {
            if(temp->isEnd) return ans;
            else if(temp->point[word[i]-'a'] == NULL) return "";
            ans += word[i];
            temp = temp->point[word[i]-'a'];
        }
        if(temp->isEnd) return ans;
        return "";
    }
    
    
    
    // approach to solve this question -> using tries 
    // why tries -> because tries is a data structure that provide efficent adding any word on it and search this word efficently
    // problem is to pick a word in sentence and find if any word that are prefix of picked word if more than word find in dictionary than choose shortest length word and replace it with original 
    // so we can use tries to add dictionary word into tries that take O(n) time for travel in dictionary vector and O(length of word) time for adding word in dictionary
    // if search if no prefix is present so search function return empty string otherwise it search shortest length string that are possible using isEnd boolean variable if it true than return ans string
    string replaceWords(vector<string>& dict, string sent) {
        int n = dict.size();
        for(int i =0; i<n; i++) {
            add(dict[i]);
        }
        stringstream s(sent);
        string temp;
        string ans = "";
        while(getline(s,temp,' ')) {
            string check = search(temp);
            if(check != "") {
                ans+= check+" ";
            }
            else ans+=temp + " ";
        }
        ans.erase(ans.size()-1,1);
        return ans;
    }
};