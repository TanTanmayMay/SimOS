// @author : Tanmay Kokate

#include <bits/stdc++.h>
#define ll long long
#define po push_back

const ll INF = 1e18;
const ll MAX = 1e5 + 5;

using namespace std;

class pageReplacement
{
private:
    vector<ll> seq = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
public:
    void fifo();
    void optimal();
    void lru();
};

void pageReplacement :: fifo()
{
    vector<vector<ll>> frame(4, vector<ll>(21, -1));    // 0-based indexing
    ll ptr = 0, hits = 0, miss = 0;
    string s = "";
    for(ll i=0; i<20; i++)
    {
        ll cur = seq[i], flg = 0;
        if(i > 0)
        {
            for(ll j=0; j<4; j++)
            {
                frame[j][i] = frame[j][i - 1];
            }
        }
        for(ll j=0; j<4; j++)
        {
            if(frame[j][i] == cur)
            {
                flg = 1;
                break;
            }
        }
        if(flg)
        {
            hits++;
            s += 'H';
            continue;
        }
        miss++;
        s += 'M';
        frame[ptr][i] = cur;
        ptr = (ptr + 1) % 4;
    }

    cout << "********* Frame state After FIFO processing **********\n\n";
    ll fcnt = 0;
    for(ll i=0; i<4; i++)
    {
        cout << "Frame" << fcnt << " -> ";
        fcnt++;
        for(ll j=0; j<20; j++)
        {
            (frame[i][j] < 0) ? cout << '$' << " | " : cout << frame[i][j] << " | ";
        }
        cout << '\n';
    }
    cout << "\nStatus -> ";
    for(auto it : s)
    {
        cout << it << " | ";
    }
    cout << '\n';
    cout << "\nTotal Hits -> " << hits << '\n';
    cout << "Total Miss -> " << miss << '\n';
    cout << "Hits Ratio -> " << ((hits * 1.0) / (1.0 * (hits + miss))) * 100.0 << "%\n";
    cout << "Miss Ratio -> " << ((miss * 1.0) / (1.0 * (hits + miss))) * 100.0 << "%\n";

    return;
}

void pageReplacement :: optimal()
{
    vector<vector<ll>> frame(4, vector<ll>(20, -1));
    ll hits = 0, miss = 0;
    string s = "";
    for(ll i=0; i<20; i++)
    {
        ll cur = seq[i], flg = 0;
        if(i > 0)
        {
            for(ll j=0; j<4; j++)
            {
                frame[j][i] = frame[j][i - 1];
            }
        }
        for(ll j=0; j<4; j++)
        {
            if(frame[j][i] == cur)
            {
                flg = 1;
                break;
            }
        }
        if(flg)
        {
            hits++;
            s += 'H';
        }
        else
        {
            miss++;
            s += 'M';
            multiset<ll> ds;
            for(ll j=0; j<4; j++)
            {
                ds.insert(frame[j][i]);
            }
            for(ll k = i; k<20; k++)
            {
                if(ds.count(seq[k]))
                {
                    ds.erase(seq[k]);
                }
                if(ds.size() == 1)
                {
                    break;
                }
            }
            ll toreplace = *ds.begin(), ptrR = 0;
            for(ll ptr = 0; ptr < 4; ptr++)
            {
                if(frame[ptr][i] == toreplace)
                {
                    ptrR = ptr;
                    break;
                }
            }
            frame[ptrR][i] = seq[i];
            ds.clear();
        }
    }

    cout << "********* Frame state After OPTIMAL processing **********\n\n";
    ll fcnt = 0;
    for(ll i=0; i<4; i++)
    {
        cout << "Frame" << fcnt << " -> ";
        fcnt++;
        for(ll j=0; j<20; j++)
        {
            (frame[i][j] < 0) ? cout << '#' << " | " : cout << frame[i][j] << " | ";
        }
        cout << '\n';
    }
    cout << "\nStatus -> ";
    for(auto it : s)
    {
        cout << it << " | ";
    }
    cout << '\n';
    cout << "\nTotal Hits -> " << hits << '\n';
    cout << "Total Miss -> " << miss << '\n';
    cout << "Hits Ratio -> " << ((hits * 1.0) / (1.0 * (hits + miss))) * 100.0 << "%\n";
    cout << "Miss Ratio -> " << ((miss * 1.0) / (1.0 * (hits + miss))) * 100.0 << "%\n";

    return;
}

void pageReplacement :: lru()
{
    vector<vector<ll>> frame(4, vector<ll>(20, -1));
    ll hits = 0, miss = 0;
    string s = "";
    for(ll i=0; i<20; i++)
    {
        ll cur = seq[i], flg = 0;
        if(i > 0)
        {
            for(ll j=0; j<4; j++)
            {
                frame[j][i] = frame[j][i - 1];
            }
        }
        for(ll j=0; j<4; j++)
        {
            if(frame[j][i] == cur)
            {
                flg = 1;
                break;
            }
        }
        if(flg)
        {
            hits++;
            s += 'H';
        }
        else
        {
            miss++;
            s += 'M';
            multiset<ll> ds;
            for(ll j=0; j<4; j++)
            {
                ds.insert(frame[j][i]);
            }
            for(ll k = i; k>=0; k--)
            {
                if(ds.count(seq[k]))
                {
                    ds.erase(seq[k]);
                }
                if(ds.size() == 1)
                {
                    break;
                }
            }
            ll toreplace = *ds.begin(), ptrR = 0;
            for(ll ptr = 0; ptr < 4; ptr++)
            {
                if(frame[ptr][i] == toreplace)
                {
                    ptrR = ptr;
                    break;
                }
            }
            frame[ptrR][i] = seq[i];
            ds.clear();
        }
    }

    cout << "********* Frame state After LRU processing **********\n\n";
    ll fcnt = 0;
    for(ll i=0; i<4; i++)
    {
        cout << "Frame" << fcnt << " -> ";
        fcnt++;
        for(ll j=0; j<20; j++)
        {
            (frame[i][j] < 0) ? cout << '#' << " | " : cout << frame[i][j] << " | ";
        }
        cout << '\n';
    }
    cout << "\nStatus -> ";
    for(auto it : s)
    {
        cout << it << " | ";
    }
    cout << '\n';
    cout << "\nTotal Hits -> " << hits << '\n';
    cout << "Total Miss -> " << miss << '\n';
    cout << "Hits Ratio -> " << ((hits * 1.0) / (1.0 * (hits + miss))) * 100.0 << "%\n";
    cout << "Miss Ratio -> " << ((miss * 1.0) / (1.0 * (hits + miss))) * 100.0 << "%\n";

    return;
}

int main()
{
    pageReplacement obj;
    obj.fifo();
    cout << "\n\n";
    obj.optimal();
    cout << "\n\n";
    obj.lru();
    return 0;
}

/*
        OUTPUT

    ~/Desktop/Tanmay/Practicals/OSL  cd "/home/severscanor/Desktop/Tanmay/Practicals/OSL/Assign6/" && g++ pageReplacement.cpp
 -o pageReplacement && "/home/severscanor/Desktop/Tanmay/Practicals/OSL/Assign6/"pageReplacement
********* Frame state After FIFO processing **********

Frame0 -> 7 | 7 | 7 | 7 | 7 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 2 | 2 | 2 | 2 | 2 | 2 | 
Frame1 -> $ | 0 | 0 | 0 | 0 | 0 | 0 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 7 | 7 | 7 | 
Frame2 -> $ | $ | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 
Frame3 -> $ | $ | $ | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 

Status -> M | M | M | M | H | M | H | M | H | H | M | H | H | M | M | H | H | M | H | H | 

Total Hits -> 10
Total Miss -> 10
Hits Ratio -> 50%
Miss Ratio -> 50%


********* Frame state After OPTIMAL processing **********

Frame0 -> 7 | 7 | 7 | 7 | 7 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 
Frame1 -> # | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 
Frame2 -> # | # | 1 | 1 | 1 | 1 | 1 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 4 | 
Frame3 -> # | # | # | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 7 | 7 | 7 | 

Status -> M | M | M | M | H | M | H | M | H | H | H | H | H | M | H | H | H | M | H | H | 

Total Hits -> 12
Total Miss -> 8
Hits Ratio -> 60%
Miss Ratio -> 40%


********* Frame state After LRU processing **********

Frame0 -> 7 | 7 | 7 | 7 | 7 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 3 | 7 | 7 | 7 | 
Frame1 -> # | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 
Frame2 -> # | # | 1 | 1 | 1 | 1 | 1 | 4 | 4 | 4 | 4 | 4 | 4 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 
Frame3 -> # | # | # | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 

Status -> M | M | M | M | H | M | H | M | H | H | H | H | H | M | H | H | H | M | H | H | 

Total Hits -> 12
Total Miss -> 8
Hits Ratio -> 60%
Miss Ratio -> 40%

*/