class Solution {
public:

string spaces(int n,int &m,int &len)
{
    if(len==0) return "";
    string temp="";
    while(n--) temp+=" ";
    if(m)
    {
        temp+=" ";
        m--; 
    }
    len-=temp.length();
    return temp;
}
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n=words.size();
    vector<string>ans;
    int i=0;
    while(i<n)
    {
        int len=words[i].length(),j=i+1;
        while(j<n && len+j-i+words[j].length()<=maxWidth)
        {
            len+=words[j++].length();
        }
        int noofspaces=(maxWidth-len);
        int rem=0,temp=noofspaces;
        if(j-i>1) 
        {
            rem=noofspaces%(j-i-1);
            noofspaces/=(j-i-1);
        }
        string cur;
        while(i<j)
        {
            if(j==n)
            {
                noofspaces=1;
                rem=0;
            }
            cur=cur+words[i++]+spaces(noofspaces,rem,temp);
        }
        while(temp--) cur.push_back(' ');
        ans.push_back(cur);
    }
    return ans;
}
};