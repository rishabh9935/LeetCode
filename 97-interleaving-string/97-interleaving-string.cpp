class Solution {
public:
    bool check(string s1, string s2, string s3, int p1, int p2, int p3, vector<vector<int>> &v){
        if(v[p1][p2]!=-1){
            return v[p1][p2];
        }
        bool x = false;
        bool y = false;
        if(p1==s1.length() && p2==s2.length() && p3==s3.length()) return true;
        if(p1!=s1.length()){
            if(s1[p1]==s3[p3])
                x = check(s1,s2,s3,p1+1,p2,p3+1,v);
        }
        if(p2!=s2.length()){
            if(s2[p2]==s3[p3])
                y = check(s1,s2,s3,p1,p2+1,p3+1,v);
        }
        return v[p1][p2] = x||y;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(); int b=s2.size();
        vector<vector<int>> v(a+1,vector<int>(b+1,-1));
        return check(s1,s2,s3,0,0,0,v);
    }
};