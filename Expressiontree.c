#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <ctype.h>
#include<string.h>
int precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}
int applyOp(int a, int b, char op){

	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int stack1[100];
char stack2[100];
int top1=-1;
int top2=-1;
void push1(int num)
{
   // cout<<num<<endl;
    if(top1==99)
        printf("stack is full");
    else
    {
        top1++;
        stack1[top1] = num;
       // cout<<stack1[top1]<<endl;
    }
}
int pop1()
{
    if(top1==-1)
        printf("stack is empty");
    else{
            int n = stack1[top1--];
           // cout<<n<<endl;
            return n;
}}

void push2(char num)
{
    //cout<<num<<endl;
    if(top2==99)
        printf("stack is full");
    else
    {
        top2++;
        stack2[top2] = num;
        //cout<<stack2[top2]<<endl;
    }
}

char pop2()
{
    if(top2==-1)
        printf("stack is empty");
    else
       {

        char c = stack2[top2--];
        //cout<<c<<endl;
        return c;}
}


int evaluate(char* tokens,int n){
	int i;
        for(i = 0; i < n; i++){
		//cout<<tokens[i]<<endl;
		if(tokens[i] == ' ')
			continue;
		else if(tokens[i] == '('){
			push2(tokens[i]);
		}
		else if(isdigit(tokens[i])){
			int val = 0;
			while(i < n &&
						isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}

			push1(val);
			i--;
		}
		else if(tokens[i] == ')')
		{
			while(top2!=-1 && stack2[top2] != '(')
			{
				int val2 = stack1[top1];
				//cout<<val2<<endl;
				pop1();

				int val1 = stack1[top1];
				//cout<<val2<<endl;
				pop1();

				char op = stack2[top2];
				pop2();
                //cout<<applyOp(val1, val2, op)<<endl;
				push1(applyOp(val1, val2, op));
			}
			if(top2!=-1)
			pop2();
		}
		else
		{
			while(top2!=-1 && precedence(stack2[top2])
								>= precedence(tokens[i])){
				int val2 = stack1[top1];
				pop1();

				int val1 = stack1[top1];
				pop1();

				char op = stack2[top2];
				pop2();

				push1(applyOp(val1, val2, op));
			}
			push2(tokens[i]);
			//cout<<tokens[i]<<endl;
		}
	}
	while(top2!=-1){
		int val2 = stack1[top1];
		pop1();

		int val1 = stack1[top1];
		pop1();

		char op = stack2[top2];
		pop2();

		push1(applyOp(val1, val2, op));
	}
	return stack1[top1];
}



int main() {

    char a[100];
    scanf("%s",a);
    //gets(a);
    int n = strlen(a);
    int i;
    for(i=n-1;i>=0;i--){
      a[i+1] = a[i];
    }
    a[0] = '(';
    a[n+1] = ')';
    int j;
    for( j=0;j<n+2;j++){
        if(a[j]=='#')
        {
            printf("Invalid");
            break;
        }
    }

    if(j==n+2)
	printf("%d",evaluate(a,n+2));

	return 0;
}



