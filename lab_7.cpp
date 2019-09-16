#include <bits/stdc++.h>
using namespace std;
int mycompare(string X,string Y)
{
	string A=X.append(Y);
	string B=Y.append(X);
	if(A.compare(B)>0) return 1;
	else return 0;
}
int main()
{
int T;
vector<string> out;
cin>>T;
while(T--)
 {
  int c;
  cin>>c;
  string s;
  while(c--)
{	
	cin>>s;
	out.push_back(s);
}
sort(out.begin(),out.end(),mycompare);
for(int i=0;i<out.size();i++)
{
	cout<<out[i];
}
      out.clear();
 		}
}
