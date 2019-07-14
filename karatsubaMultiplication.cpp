//O(n^1.585)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll stringToInt(string s)
{
    ll p=1;
    ll sum=0;
    for(int i=s.size()-1;i>=0;i--){
        sum+=(p*(s[i]-'0'));
        p*=10;
    }
    return sum;
}
ll product(string x,string y)
{
    if(x.size()==1 || y.size()==1){
        return stringToInt(x)*stringToInt(y);
    }else{
        string a=x.substr(0,x.size()/2);
        string b=x.substr(x.size()/2,x.size()-1);
        string c=y.substr(0,y.size()/2);
        string d=y.substr(y.size()/2,y.size()-1);
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        return pow(10,y.size())*product(a,c)+product(b,d)+pow(10,y.size()/2)*(product(a,d)+product(b,c));
    }
}
int main()
{
    cout<<product("3245","1243");
}
