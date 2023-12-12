// @ author : Tanmay Kokate

#include <bits/stdc++.h>
#define ll long long
#define po push_back

using namespace std;

class scheduler
{
private:
    vector<pair<ll, ll>> v = {{0, 5}, {1, 4}, {2, 2}, {4, 1}};
public:
    scheduler();
    void roundRobin();
};

scheduler :: scheduler()
{
    sort(v.begin(), v.end());
}

void scheduler :: roundRobin()
{
    queue<ll> readyq;
    vector<pair<ll, ll>> gantt; // {PiD, CurTime}
    ll quant = 2;
    ll time = 0;
    vector<ll> at, bt, atC, btC, et(4), tat, wt;
    for(auto it : v)
    {
        at.po(it.first);
        bt.po(it.second);
    }
    atC = at;
    btC = bt;

    readyq.push(0);

    while(!readyq.empty())
    {
        ll cur = readyq.front();
        readyq.pop();

        gantt.po({cur, time + min(quant, bt[cur])});

        time += min(bt[cur], quant);
        bt[cur] -= min(bt[cur], quant);
        
        multiset<ll> s;
        queue<ll> copy = readyq;
        while(!copy.empty())
        {
            s.insert(copy.front());
            copy.pop();
        }

        for(ll i=0; i<4; i++)
        {
            if((i != cur) && (at[i] <= time && bt[i] > 0) && !s.count(i))
            {
                readyq.push(i);
            }
        }

        if(bt[cur] > 0)
        {
            readyq.push((cur));
        }
        else
        {
            et[cur] = time;
        }
    }

    for(ll i=0; i<4; i++)
    {
        tat.po(et[i] - atC[i]);
        wt.po(tat[i] - btC[i]);
    }

    cout << "=========== GANTT CHART ============\n\n";

    cout << "+----+----+----+----+----+----+----+\n";
    cout << "| ";
    for(auto it : gantt)
    {
        cout << "P" << it.first + 1 << " | ";
    }
    cout << '\n';
    cout << "+----+----+----+----+----+----+----+\n";

    ll n = gantt.size();
    cout << 0 << "    ";
    for(ll i=0; i<n; i++)
    {
        cout << gantt[i].second << "    ";
    }
    cout << '\n';
}

int main()
{
    scheduler obj;
    obj.roundRobin();

    return 0;
}