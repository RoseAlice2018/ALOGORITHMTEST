#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>word_count(26,0);
        for(int i=0;i<ransomNote.size();i++)
        {
            word_count[ransomNote[i]-'a']++;
        }
        for(int i=0;i<magazine.size();i++)
        {
            word_count[magazine[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(word_count[i]>0)
                return false;
        }
        return true;
    }
};