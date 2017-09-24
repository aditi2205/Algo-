#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void findwindow(string text, string patt)
{
    cout<<"func enter";
    if(patt.size()>text.size()) 
    {
        cout<<-1;
        return;
    }
    map<int, int> hash;
    for(int i=0; i<patt.size(); i++)
    {
        if(hash.find(patt[i])!=hash.end())
         hash[patt[i]]++;
        else
         hash.insert(make_pair(patt[i],1));
    }
    int c=0;
    int start=0, end;
    int minlen= 99999;
    int head=0;

    for(end=0; end<text.size(); end++)
    {
        if(hash.find(text[end])==hash.end()) continue;
        
        hash[text[end]]--;
        if(hash[text[end]]>=0) c++;
        
        if(c==patt.size())
        {
            //minimize window
            //removes extra characters and useless characters
            while(hash.find(text[head])==hash.end() || hash[text[head]]<0 )
            {
                if(hash.find(text[head])!=hash.end())
                hash[text[head]]++;
                head++;
                
            }
            cout<<"head value is"<<head;
            if(minlen > end-head+1)
            {
                minlen= end-head+1;
                start= head;
            }
            
        }
    }
    cout<< text.substr(start, minlen);
}
string minWindow(string S, string T) {
        if (S.length() < T.length()) return "";
        map<char, int> counts;
        for (int i = 0; i < T.length(); i++) {
            if (counts.find(T[i]) == counts.end()) {
                counts[T[i]] = 1;
            } else {
                counts[T[i]]++;
            }
        }
        int start = 0;
        int length = 0;
        int total = 0;
        for (int head = 0, tail = 0; tail < S.length(); tail++) {
            
            if (counts.find(S[tail]) == counts.end()) {
                // If this character is not present in T at all, 
                // we don't care about this character. 
                continue;
            }
            counts[S[tail]]--;
            // We check if the current character represented by tail caused
            // a character to be included which is relevant to T and is still
            // in deficit. 
            // For example, if T has 3 As, then the first 3 A are relevant to us
            // but the 4th one is not. 
            if (counts[S[tail]] >= 0) {
                total++;
            }
            // check if we have all characters in T covered. 
            if (total == T.size()) {
                // Now move the head pointer till popping out those characters 
                // still makes sure that all characters in T are covered. 
                while (counts.find(S[head]) == counts.end() || counts[S[head]] < 0) {
                    if (counts.find(S[head]) != counts.end()) counts[S[head]]++;
                    head++;
                }
                // Now [head - 1, tail] is a valid substring. Update the answer. 
                if (length == 0 || tail - head + 1 < length) {
                    length = tail - head + 1;
                    start = head;
                }
            }
        }
        return S.substr(start, length);
    }

int main() {
	
	int t;
	cout<<"enter testcase";
	cin>>t;
	while(t--)
	{cout<<"enter string and patten";
	    string text, pattern;
	    cin>>text;
	    cin>>pattern;
	    findwindow(text, pattern);
       // cout<<minWindow(text, pattern)<<endl;
	}
	return 0;
}