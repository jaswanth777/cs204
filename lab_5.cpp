#include<bits/stdc++.h>
using namespace std;
struct node
{
  string str;
  int value;
  struct node* ptr;
};
string getString(char x)
{
    string s(1, x);
    return s;
}
//The below function for calculating the key value of the input string
int calkeyvalue(string s)
{
  int val=0;
  for(int i=0;i<s.length();i++)
  {
    int tmp=s[i];
    val=val+tmp;
  }
  return val;
}
node* insertnode(node arr[] ,string exp,int num)
{
  node* next=new node;
  node* traverse;
  node * prev;
  traverse=&arr[calkeyvalue(exp)];prev=traverse;
  while(traverse!=NULL)
  {
        prev=traverse;
    traverse=traverse->ptr;
  }
  next=prev;
  next->str=exp;
  next->value=num;
  next->ptr=NULL;
  return next;
}
string search(node arr[],string s)
{
  int kv=calkeyvalue(s),v;
  string str="Not Found";
  node* traverse;
  traverse=&arr[kv];
  while(traverse!=NULL)
  {
      if(traverse->str==s) {v=traverse->value; str=to_string(v);break;}
    traverse=traverse->ptr;
  }
  return str;
}
struct etree
{
    string value;
    etree* left, *right;
};
//This is the function for getting preference order of operators
int pref(string c)
{
	  if(c=="@")
	  return 4;
    if(c == "^")
    return 3;
    else if(c == "*" || c == "/")
    return 2;
    else if(c == "+" || c == "-")
    return 1;
    else
    return -1;
}
//This is the function to convert the given infix to postfix form
vector<string> infixToPostfix(vector<string> s)
{
    std::stack<string> st;
    st.push("N");
    int l = s.size();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if(s[i]!="(" && s[i]!=")" && s[i]!="+" && s[i]!="*" && s[i]!="-" && s[i]!="/" && s[i]!="^" && s[i]!="@") {
        	if(s[i]!="")
        	ns.push_back(s[i]);
    	}

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == "(")

        st.push("(");

        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == ")")
        {
            while(st.top() != "N" && st.top() != "(")
            {
                string c = st.top();
                st.pop();
                ns.push_back(c);
            }
            if(st.top() == "(")
            {
                st.pop();
            }
        }

        //If an operator is scanned
        else{
            while(st.top() != "N" && pref(s[i]) <= pref(st.top()) && pref(s[i])!=3 && pref(st.top())!=3)
            {
                string c = st.top();
                st.pop();
                ns.push_back(c);
            }
            st.push(s[i]);
        }

    }
    //Pop all the remaining elements from the stack
    while(st.top() != "N")
    {
                string c = st.top();
                st.pop();
                ns.push_back(c);
    }

    return ns;

}
//This is the function to check whether the string element is an operator or not operator
bool isOperator(string c)
{
    if (c == "+" || c == "-" ||
            c == "*" || c == "/" ||
            c == "^" || c=="@")
        return true;
    return false;
}

bool isOperatorc(char c)
{
    if ((c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^'))
        return true;
    return false;
}
bool isunary(string p,int i)
{
	if((i==0)||(p[i+1]==41)||(isOperatorc(p[i-1]))||(p[i-1] == 61)||(p[i-1]==40))
		return true;
	return false;
}
etree* newNode(string node_value)
{
    etree *tmp = new etree;
    tmp->left = tmp->right = NULL;
    tmp->value = node_value;
    return tmp;
};

// Returns root of constructed tree for given
// postfix expression
etree* createTree(vector<string> postfix)
{
    stack<etree *> st;
    etree *t, *t1, *t2;

    // Traverse through every character of
    // input expression
    for (int i=0; i<postfix.size(); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else if(postfix[i] == "@")
        {
          string a = "0";
        	t = newNode(postfix[i]);
        	t1 = st.top();
        	st.pop();
        	t->right = t1;
        	t2  = newNode(a);
        	t->left = t2;
        	st.push(t);
        }
        else // i.e if it is an operator
        {
            t = newNode(postfix[i]);

            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();

            //  make them children
            t->right = t1;
            t->left = t2;

            // Add this subexpression to stack
            st.push(t);
        }
    }

    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();

    return t;
}

int eval(etree* a){
	if(a->left==NULL&&a->right==NULL)
		return stoi(a->value);
	int A = eval(a->left);
	int B = eval(a->right);
	if(a->value == "+")
		return A+B;
	else if(a->value == "-")
		return A-B;
	else if(a->value == "*")
		return A*B;
	else if(a->value == "%")
		return A%B;
	else if(a->value == "/")
		return A/B;
	else if(a->value == "^")
		return pow(A,B);
    else if(a->value == "@")
    	return -1*B;
}
string conversion(node arr[],string s)
{
  int l=s.length();
  string str;
  int i=0,k=0;
  string tmp1;
  while(i<s.length())
  {

      if ((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/')||(s[i]=='^')||(s[i]=='(')||(s[i]==')')
      ||(s[i]=='0')||(s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4')||(s[i]=='5')||(s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9'))
      {i++;}
      else{string tmp=getString(s[i]);
      int j=i+1;
      while(j<l)
      {
        if((s[j]!='+')&&(s[j]!='-')&&(s[j]!='*')&&(s[j]!='/')&&(s[j]!='^')&&(s[i]!='(')&&(s[i]!=')')
      &&(s[j]!='0')&&(s[j]!='1')&&(s[j]!='2')&&(s[j]!='3')&&(s[j]!='4')&&(s[j]!='5')&&(s[j]!='6')&&(s[j]!='7')&&(s[j]!='8')&&(s[j]!='9'))
      {tmp=tmp+getString(s[j]);j++;}
      else{break;}
      }
      if(search(arr,tmp)!="Not Found")
      {
        if(i>0){str=s.substr(0,i)+search(arr,tmp);
        s=s.substr(0,i)+search(arr,tmp)+s.substr(j,s.length());
      }
        if(i==0){str=search(arr,tmp);
        s=search(arr,tmp)+s.substr(j,s.length());
      }
        i=str.length();
      }

    else if((search(arr,tmp)=="Not Found")&&(s[i]!='+')&&(s[i]!='-')&&(s[i]!='*')&&(s[i]!='/')&&(s[i]!='^') &&(s[i]!='(')&&(s[i]!=')')
    &&(s[i]!='0')&&(s[i]!='1')&&(s[i]!='2')&&(s[i]!='3')&&(s[i]!='4')&&(s[i]!='5')&&(s[i]!='6')&&(s[i]!='7')&&(s[i]!='8')&&(s[i]!='9')){s="Cannot be evaluated";break;}
  }
  }
  return s;
}
int expvalue(string exp)
{
vector<string> P;
string temp="";

for(int i=0; i<exp.length();i++)
{
  if(exp[i]>=48 && exp[i]<=57)
  {
        temp+=exp[i];
  }
  else
  {
           P.push_back(temp);
          temp="";
          if(exp[i] == 45 && isunary(exp,i))
            	exp[i] = '@';
           temp+=exp[i];
            P.push_back(temp);
          temp="";
  }

}
  P.push_back(temp);
  vector<string> postexp=infixToPostfix(P);
  etree* a = createTree(postexp);
  int val = eval(a);
  return val;
}
int main()
{ int testcases,z=0;
  cin>>testcases;
  while(testcases--)
  {
  int T;
  cin>>T;
  int e=0;
  node arr[100][98];
  for(int i=0;i<98;i++)
  {
    arr[z][i].ptr=NULL;
  }
  string str;
  while(T--)
  {
    cin>>str;
  int strl=str.length(),count=0;
  string lhs,rhs;
  for(int i=0;i<strl;i++)
  {
    if(str[i]=='=')
    {
      lhs=str.substr(0,i);
      rhs=str.substr(i+1,strl);
      rhs=conversion(arr[z],rhs);
      if(rhs=="Cannot be evaluated"){ e=1;break;}
      count++;
    }
  }
  if(count!=0)
  { if(e==1)cout<<"CANNOT BE EVALUATED"<<endl;
    else {node * test=insertnode(arr[z],lhs,expvalue(rhs));}
  }
  else
  {
    str=conversion(arr[z],str);
    if(str=="Cannot be evaluated"){e=1;}
  if(e==1)cout<<"CANNOT BE EVALUATED"<<endl;
  else{  cout<<expvalue(str)<<endl;}
  }
}z++;}
return 0;}
