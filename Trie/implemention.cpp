//SATYAM SINGH  
// problem link -->  https://leetcode.com/problems/implement-trie-prefix-tree/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define pb                 push_back
#define mod                     1000000007
#define inf                     1e18
#define ump                unordered_map
#define mp                 make_pair
#define all(v)                   v.begin(),v.end()

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' ' 
#define  loop(i,a,b)  for(int i=(a);i<(b);i++)
#define  looprev(i,a,b)  for(int i=(a);i>=0;i--)
#define log(args...)  {string _s = #args ;replace(_s.begin(),_s.end(),',',' ') ; stringstream _ss(_s); istream_iterator<string> _it(_ss) ; err(_it,args);}
void err(istream_iterator<string> it) {}
template<typename T,typename ... Args>
void err(istream_iterator<string> it, T a,Args... args) {
      cout<<*it<<" = "<<a<<endl;
   err(++it,args...);
}

void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

class Trie {
public:
    /** Initialize your data structure here. */

    struct t{
    	t*child[26] ={};
    	bool IsEnd;
    };
    t root;
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        t *temp = &root;
        for(int i=0;i<word.size();i++) {
        	int index = word[i]-'a';
        	if(not temp->child[index]) {
        		temp->child[index] = new t();
        	}
        	temp = temp->child[index];
        }
        temp->IsEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
    	t*temp = &root;
        for(int i=0;i<word.size();i++) {
        	int index = word[i]-'a';
        	if(not temp->child[index]) return false;
        	temp = temp->child[index];
        }
        if(not temp->IsEnd) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        t*temp = &root;
        for(int i=0;i<prefix.size();i++) {
        	int index = prefix[i]-'a';
        	if(not temp->child[index]) return false;
        	temp = temp->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    Trie trie = Trie();
    trie.insert("apple");
	cout<<trie.search("apple")<<endl;  // return True
	cout<<trie.search("app")<<endl;     // return False
	cout<<trie.startsWith("app")<<endl; // return True
	trie.insert("app");
	cout<<trie.search("app")<<endl;
    
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}