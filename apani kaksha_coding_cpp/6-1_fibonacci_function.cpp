//fibonacci sequence 0,1,1,2....
#include<bits\stdc++.h>
using namespace std;
void fibonacci(int n)
{
    int t1=0;
    int t2=1;
    int nextterm;
    for(int i=1;i<=n;i++)
    {
        cout<<t1<<endl;
        nextterm=t1+t2;
        t1=t2;
        t2=nextterm;
    }
   
}
int main()
{
    int n;
    cin>>n;
    fibonacci(n);
return 0;
}