#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
struct st
{
    ll proc,arrive,burst;
};
struct stq
{
    ll pr,start,last;
};
bool cmp(st a,st b)
{
    if(a.burst==b.burst)return a.arrive<b.arrive;
    return a.burst<b.burst;
}
bool cmp1(stq a,stq b)
{
    return a.pr<b.pr;
}
int main()
{
    ll process,p,pp,ppp;
    cout<<"Enter The process number"<<endl;
    while(cin>>process)
    {
        cout<<"Enter The process id,Arival time, Burst Time"<<endl;
        vector<st>v,rs;
        st x,y;
        x.proc=-1;
        x.arrive=-1;
        x.burst=-1;
        v.pb(x);
        for(ll i=0; i<process; i++)
        {
            cin>>ppp;
            cin>>p;
            cin>>pp;
            if(p==0)
            {
                y.proc=ppp;
                y.arrive=p;
                y.burst=pp;
                rs.pb(y);
            }
            else
            {	                x.proc=ppp;
                x.arrive=p;
 x.burst=pp;
                v.pb(x);
                rs.pb(x);
            }
        }
        v[0]=y;
        sort(v.begin()+1,v.end(),cmp);
        vector<stq>V;
        stq xx;
        x=v[0];
        xx.pr=x.proc;
        xx.start=0;
        xx.last=x.burst;
        V.pb(xx);
        ll sum=x.burst;
        for(ll i=1;i<process;i++)
        {
            x=v[i];
            xx.start=sum;
            sum+=x.burst;
            xx.pr=x.proc;
            xx.last=sum;
            V.pb(xx);
        }
        sort(V.begin(),V.end(),cmp1);
        double avg_wait=0.0,avg_turn=0.0;
        ll t;
        for(ll i=0;i<process;i++)
        {
            xx=V[i];
            x=rs[i];
            t=xx.start-x.arrive;
            avg_wait+=(double)t;
            printf("Waiting time of %lld is %lld  ",x.proc,t);
            t=xx.last-x.arrive;
            avg_turn+=(double)t;
            printf("Turn around time of %lld is %lld\n",x.proc,t);
        }
        avg_turn/=process;
        avg_wait/=process;
        printf("Average waiting time is = %.2lf\n",avg_wait);
        printf("Average turn around time is = %.2lf\n",avg_turn);
    }
}


