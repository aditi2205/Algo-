/**
 * @input A : String termination by '\0'
 * @input B : array of strings termination by '\0'
 * @input n2 : number of strings in array B
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* solve(char* A, char** B, int n2, int *len1) {
    int start=0;
    int goodValue[n2]={0};
    int ranking[n2];
    for(int i=0;i<A.length();i++)
    {
        char* s=strtok(A,'_');
        insertInTrie(s);
    }
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<B[i].length();j++)
        {
            char* s=strtok(B[i],'_');
            if(trieContains(s))
            goodValue[i]++;
            
        }
        
    }
}

//
        char* s = strtok(A, '_');
        cout<< strtok(NULL, '_');
        
//#define F first
#define S second


bool cmp(const pair<int, int>& a, const pair<int, int>& b){
        if(a.F == b.F) return a.S < b.S;
	return a.F > b.F;	
}

//Trie node
struct node{
	bool exist;
	node* arr[26];
	node(bool bul=false){
		exist = bul;
		for(int i=0; i<26; i++)	arr[i] = NULL;
	}
};

void add(string s,node* trie){
    //add a node to the trie
	int n = s.size();
	for(int i=0; i<n; i++){
		if(trie->arr[s[i]-'a']==NULL)	trie->arr[s[i]-'a'] = new node();
		trie = trie->arr[s[i]-'a'];
	}
	trie->exist=true;
	return;
}

bool search(string s,node* trie){
    //search for a node in the trie
	for(int i=0; i<s.size(); i++){
		if(trie->arr[s[i]-'a']==NULL)	return false;
		trie = trie->arr[s[i]-'a'];
	}
	return trie->exist;
}

void convert(string &str){
    //Convert _ to spaces
	for(int i=0; i<str.size(); i++)	if(str[i]=='_')	str[i]=' ';
	return;
}

vector<int> Solution::solve(string good, vector<string>& review){
	convert(good);
	node* trie = new node();
	string word;
	stringstream ss;
	ss<<good;
	while(ss>>word)	add(word,trie);
	int n = review.size();
	int k;
	vector<pair<int,int> > rating(n);
	for(int i=0; i<n; i++){
		convert(review[i]);
		ss.clear();
		ss<<review[i];
		k=0;
		while(ss>>word)	if(search(word,trie))	k++;
		rating[i].first = k;	rating[i].second = i;
	}
	sort(rating.begin(),rating.end(),cmp);
	vector<int> ans(n);
	for(int i=0; i<n; i++)	ans[i] = rating[i].second;
	return ans;
}

   