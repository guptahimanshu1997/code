#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define loop(a,b,c)     for(int a=b;a<c;a++) 
//#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)      substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)        cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int priority(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else return -1;
}
string postfix(string s)
{   
	int n = s.length();
    stack<char> stk;
    stk.push('$');
    string ans = "";
    loop(i,0,n)
    {
       if(s[i]==' ')
    		continue;
       else if(isalpha(s[i]) || isdigit(s[i]))	
       	{
       		if(isalpha(s[i]))
       	      ans+=s[i];
          else{
          	while(isdigit(s[i]))
          		{ans+=s[i]; i++;}
          	i--;
          }

       	ans+=' ';
       }
       else if(s[i]=='(')
       	stk.push('(');
       else if(s[i]==')')
       {
           while(stk.top()!='(')
           {
           	   ans+=stk.top();
           	   ans+=' ';
           	   stk.pop();
           }
           stk.pop();
       }
       else{
              while(stk.top()!='$' && priority(s[i])<=priority(stk.top()))
                {
                     ans+=stk.top();
                     ans+=' ';
                     stk.pop();
                }
                stk.push(s[i]);
       }
    }  

    while(stk.top()!='$') 
    {
    	ans+=stk.top();
    	ans+=' ';
    	stk.pop();
    }   

   return ans;
}

int eval(string str)
{
	int n = str.length();
	stack<int> s;
	loop(i,0,n)
	{
		if(str[i]==' ')
			continue;
		else if(isdigit(str[i]))
		{
			int temp =0;
			while(isdigit(str[i]))
			{
				temp = temp*10 + str[i]-'0';
				i++;
			}
			s.push(temp);
			i--;

		}
		else
		{
			int val1 = s.top(); s.pop();
			int val2 = s.top(); s.pop();
			switch(str[i])
          {
                  
            case '+': s.push( val2 + val1); break;  
            case '-': s.push( val2 - val1); break;  
            case '*': s.push( val2 * val1); break;  
            case '/': s.push( val2/val1); break;  
             
               
		}
	}
}
	return s.top(); 

}


int32_t main()
{
    FIO;
    string s;
    getline(cin,s);
    string ans = postfix(s);
    cout<<ans<<endl;
    cout<<eval(ans)<<endl;

    return 0;
}
