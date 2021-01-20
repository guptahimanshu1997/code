#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define loop(a,b,c)     for(int a=b;a<c;a++) 
#define int             long long
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
 

typedef struct node 
{
	string data;
	struct node *left, *right;
} * Node;
Node newNode(string c)
{
	Node n = new node;
	n->data = c;
	n->left = n->right = nullptr;
	return n;
}
Node build(string& s)
{
	stack<Node> stN;
	stack<char> stC;
	Node t, t1, t2;
	int p[123] = { 0 };
	p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
	p[')'] = 0;

	for (int i = 0; i < s.length(); i++) 
	{
		if (s[i] == '(') {
			stC.push(s[i]);
		}
		else if (isdigit(s[i])) 
		{
			 int temp=0;
		       while(isdigit(s[i])){
               temp = temp*10 + s[i]-'0';
                 i++;}
            string s3 = to_string(temp);
			
			t = newNode(s3);
			stN.push(t);
			i--;
		}
		else if (p[s[i]] > 0) 
		{
			
			while (
				!stC.empty() && stC.top() != '('
				&& ((s[i] != '^' && p[stC.top()] >= p[s[i]])
					|| (s[i] == '^'
						&& p[stC.top()] > p[s[i]]))) 
			{
				char x = stC.top();
				string str(1,x);
				t = newNode(str);
				stC.pop();
				t1 = stN.top();
				stN.pop();
				t2 = stN.top();
				stN.pop();
				t->left = t2;
				t->right = t1;
				stN.push(t);
			}
			stC.push(s[i]);
		}
		else if (s[i] == ')') {
			while (!stC.empty() && stC.top() != '(') 
			{
				char x = stC.top();
				string str(1,x);
				t = newNode(str);
				stC.pop();
				t1 = stN.top();
				stN.pop();
				t2 = stN.top();
				stN.pop();
				t->left = t2;
				t->right = t1;
				stN.push(t);
			}
			stC.pop();
		}
	}
	t = stN.top();
	return t;
}
int evalTree(Node root) {
    if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return stoi(root->data);

	int left = evalTree(root->left);
	int right = evalTree(root->right);

	if(root->data=="+")
		return left+right;
	if(root->data=="-")
		return left-right;
	if(root->data=="*")
		return left*right;
	return left/right;
}



int32_t main()
{
    FIO;
    string s;
	getline(cin,s);
	s = "(" + s;
	s += ")";
	Node root = build(s);	
	cout<<evalTree(root)<<endl;
    return 0;
}
