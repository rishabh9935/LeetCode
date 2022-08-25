class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> ransom;
        map<char, int> mag;
        for(int i=0;i<ransomNote.size();i++){
            ransom[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            mag[magazine[i]]++;
        }
        for(auto it : ransom){
            if(mag.find(it.first) != mag.end()){
                if(mag[it.first] < it.second)
                    return false;
                else continue;
            }
            else return false;
        }
        return true;
    }
};