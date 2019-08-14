#include <iostream> 
#include <stack> 
using namespace std;
int main()
       {int t;
        cin>>t;
        stack <char> s;
        char temp;
        cin.get(temp);
        for(int i=0;i<t;i++)
           {
            cin.get(temp);
            while(temp!='\n')
                {
		 if(temp=='{'||temp=='['||temp=='('||temp=='<')
                   s.push(temp);
                 else if(temp=='|'&&((s.empty()==1)||(s.top()!='|')))
                        s.push(temp);
                 else if(temp=='|'&&s.top()=='|')
                        s.pop();
                 else if((temp==')'||temp=='}'||temp==']'||temp=='>')&&(s.empty()==1))
			break;
		 else if(temp==')'&&s.top()!='(')
                        break;
		 else if(temp=='}'&&s.top()!='{')
			break;
		 else if(temp==']'&&s.top()!='[')
			break;
		 else if(temp=='>'&&s.top()!='<')
			break;
                 else s.pop();
                 cin.get(temp);
                  }
            if(temp!='\n'||s.empty()!=1)
                   {
                    cout<<"NO"<<endl;
                    if(temp!='\n')
                      {
                       while(temp!='\n')
                            {cin.get(temp);}
                       }
                    while(s.empty()!=1)
                        {
                         s.pop();
                         }
                    }
            else cout<<"YES"<<endl;    
            }
        return 0;
       } 
