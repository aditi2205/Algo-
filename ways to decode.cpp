#include <iostream>
#include <numeric>
using namespace std;

int c=0;

void decode(string str, int be)
{
    if(be==str.size())
    {
      c++;
      //return;
    }
    
    int dig1= str[be]-'0';
    decode(str, be+1);

    if(be+1==str.size())
        return;
    int dig2= str[be+1]-'0';
    int ndig= 10*dig1 + dig2;
    if(ndig<=26)
    {
        decode(str, be+2);
    }
    else
        return;
    
}

int main()
{
    string s= "123";
    decode(s,0);
    cout<<c;
}
