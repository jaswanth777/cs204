#include<bits/stdc++.h>
using namespace std;
int main()
       {
        int n;
        cin>>n;
        vector<int> ui;
        vector<int> ua;
        int t;
        cin>>t;
        int max=0;
        int flag;
        int s[t][3];
        for(int i=0;i<t;i++)
            {
             cin>>s[i][0];
               if(s[i][0]==1)
                {
                 cin>>s[i][1];
                 cin>>s[i][2];
                 }
             }
        for(int i=0;i<t;i++)
            {
             if(s[i][0]==2)
               {
                if(ui.size()==0)
                   {
                    cout<<"No data available"<<endl;
                    }
                else{
                     cout<<ui[max]<<endl;
                     }
                }
             else if(s[i][0]==1)
                {
                 flag=0;
                 for (int j =0;j<ui.size(); j++)  
                    {
                     if(ui[j]==s[i][1])
                        {
                         ua[j]=ua[j]+s[i][2];
                         if(ua[max]<ua[j])
                           {
                            max=j;
                            }
                         flag=1;
                         }
                     }
                 if(flag==0)
                   {
                    ui.push_back(s[i][1]);
                    ua.push_back(s[i][2]);
                    if(ua[max]<s[i][2])
                      {
                       max=ua.size()-1;
                       }
                    }
                 }
             }
        return 0;
        }
