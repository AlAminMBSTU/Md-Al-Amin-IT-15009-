#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
struct st
{
    ll proc,arrive,burst;
};
vector<st>v;
vector<ll>wait,turn;
ll process;
void findwait()
{
    vector<ll>rt;
    for(ll i=0; i<process; i++)
        rt.pb(v[i].burst);
    ll x,complete=0,t=0,mn=LONG_LONG_MAX,shortest=0,finish_time;
    bool check=false;
    st a;
    while(complete<process)
    {
        for(ll i=0; i<process; i++)
        {
            a=v[i];
            if(a.arrive<=t&&(rt[i]<mn&&rt[i]>0))
            {
                mn=rt[i];
                shortest=i;
                check=true;
            }
        }
        if(check==false)
        {
            t++;
            continue;
        }
        rt[shortest]--;
        mn=rt[shortest];
        if(mn==0)
            mn=LONG_LONG_MAX;
        if(rt[shortest]==0)
        {
            complete++;
            finish_time=t+1;
            wait[shortest]=finish_time-v[shortest].burst-v[shortest].arrive;
            if(wait[shortest]<0)
                wait[shortest]=0;
        }
        t++;

    }
}
	void findturnaround()
{
    st a;
    for(ll i=0; i<process; i++)
    {
        a=v[i];
        turn[i]+=a.burst+wait[i];
    }
}
int main()
{
    cout<<"Enter The process number"<<endl;
    while(cin>>process)
    {
        cout<<"Enter The process id,Arival time, Burst Time"<<endl;
        v.clear();
        wait.clear();
        turn.clear();
        for(ll i=0; i<=process; i++)
        {
            wait.pb(0);
            turn.pb(0);
        }
        st a;
        ll x;
        for(ll i=0; i<process; i++)
        {
            cin>>x;
            a.proc=x;
            cin>>x;
            a.arrive=x;
            cin>>x;
            a.burst=x;
            v.pb(a);
        }
        findwait();
        findturnaround();
        double avg_wait=0.0,avg_turn=0.0;
        for(ll i=0; i<process; i++)
        {
            a=v[i];
            cout<<"Process "<<a.proc<<" Waiting time = "<<wait[i]<<" Turn around time = "<<turn[i]<<endl;
            avg_wait+=(double)wait[i];
            avg_turn+=(double)turn[i];
        }
        printf("Average waiting time = %.2lf\n",avg_wait/process);
        printf("Average turn around time = %.2lf\n",avg_turn/process);
    }
}

