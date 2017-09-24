#include <bits/stdc++.h>
using namespace std;
void checkWords(vector<string> dict,char str[])
{

    int len=strlen(str);
    set<char>hm;
    int flag=0;
    for(int i=0;i<len;i++)
            hm.insert(str[i]);

    for(int i=0;i<dict.size();i++)
    {   flag=0;
        for(int j=0;j<dict[i].size();j++)
        {
            if(hm.find(dict[i][j])==hm.end())
             {
                 flag=1;
                 break;
             }

        }
        if(flag==0)
        {
            for(int j=0;j<dict[i].size();j++)
                cout<<dict[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    vector<string> dict;
    dict.push_back("rat");
    dict.push_back("mat");
    dict.push_back("bat");
    dict.push_back("chat");
    dict.push_back("cat");
    dict.push_back("tab");
    dict.push_back("bat");
    dict.push_back("batt");
  

    char str[]={'a','b','c','t'};
    checkWords(dict,str);
    return 0;
}