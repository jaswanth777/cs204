#include<bits/stdc++.h>
using namespace std;
string addition_of_strings(string n1,string n2)
        {
         int l1=n1.length();
         int l2=n2.length();
         int carry=0;
         int l;
	 char n[l];
         stack<int> h;
	 string s;
         if(l1<=l2)
           {
             l=l2+1;
             for(int i=0;i<l1;i++)
                {
                 n[l2-i]=(((n1[l1-i-1]-'0')+(n2[l2-i-1]-'0')+carry)%10)+'0';
                 carry=((n1[l1-i-1]-'0')+(n2[l2-i-1]-'0')+carry)/10;
                 }
             for(int i=l1;i<l2;i++)
                {
                 n[l2-i]=(((n2[l2-i-1]-'0')+carry)%10)+'0';
                 carry=((n2[l2-i-1]-'0')+carry)/10;
                 }
             n[0]=(carry)+'0';
            }
         else{
              l=l1+1;
              for(int i=0;i<l2;i++)
                 {
                  n[l1-i]=(((n1[l1-i-1]-'0')+(n2[l2-i-1]-'0')+carry)%10)+'0';
                  carry=((n1[l1-i-1]-'0')+(n2[l2-i-1]-'0')+carry)/10;
                  }
              for(int i=l2;i<l1;i++)
                 {
                  n[l1-i]=(((n1[l1-i-1]-'0')+carry)%10)+'0';
                  carry=((n1[l1-i-1]-'0')+carry)/10;
                  }
             n[0]=(carry)+'0';
              }
            for(int i=l-1;i>=0;i--)
		{
		h.push(n[i]-'0');		
		}
		s="";
		if(h.top()==0){h.pop();}		
		while(h.size()!=0)
		{
		string u(1,'0'+h.top());
		s.append(u);		
		h.pop();
		}
	return s;
         }
int main()
        {
	 int t;
         cout<<"enter the number of test cases : ";
         cin>>t;
         cout<<endl;
         cout<<"enter the integers"<<endl;
         string s[2*t];
         for(int i=0;i<2*t;i++)
            {
            cin>>s[i];
            cout<<endl;
            }
         string n[t];
         for(int i=0;i<t;i++)
             {
              n[i]=addition_of_strings(s[2*i],s[2*i+1]);
              }
         cout<<"the sum of numbers in given test cases\n";
         for(int i=0;i<t;i++)
             {
              cout<<n[i]<<endl;
              cout<<endl;
              }
         return 0;
         }
