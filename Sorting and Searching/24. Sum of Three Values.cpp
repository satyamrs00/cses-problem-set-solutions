#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<string, ll> msl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define F first 
#define S second
#define I iterator
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()

int main() {
    fastio();
    ll n,x;
    cin >> n >> x;
    map<ll,set<pll>> m;
    vl v;
    REP(i,0,n){
        ll t;
        cin >> t;
        v.PB(t);
    }
    REP(i,0,n){
        REP(j,0,n){
            ll s = v[i]+v[j];
            if (i!=j && s < x){
                if(m.count(s)){
                    m[s].insert(make_pair(i,j));
                } else {
                    set<pll> se{make_pair(i,j)};
                    m[s] = se;
                }
            }
        }
    }
    REP(i,0,n){
        if (m.count(x-v[i])){
            for (auto item: m[x-v[i]]){
                if (i != item.F && i != item.S){
                    cout <<i+1<<" "<<item.F+1<<' '<<item.S+1;
                    return 0;
                }
            }
            
        }
    }
    cout << "IMPOSSIBLE\n";
}

// TODO - incomplete

// - initial approach
// one nested loop to save the sum of every pair of element in a map then one loop to find the req pair
// tle