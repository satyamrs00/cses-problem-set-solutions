#include "iostream"
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<char, ll> mcl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<char, ll> pcl;
typedef pair<ll, ll> pll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define F first 
#define S second
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    fastio();
    ll n;
    cin >> n;
    ll ans = 0;
    ll curr_size = 0;
    mll m;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        if (m.count(tmp)){
            curr_size = min(++curr_size,i-m[tmp]);
            ans = max(curr_size,ans);
        } else {
            curr_size++;
            ans = max(curr_size,ans);
        }
        m[tmp] = i;
    }
    cout << ans;
}

// - initial approach 
// one loop to get input and search for that ele in array before that , maintain current size and max size
// tle
// - second approach
// maintain a map to store the last index for some value . loop -> check if it exists in map, if it does, reduce curr size
// ac