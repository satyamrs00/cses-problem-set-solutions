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
typedef pair<char, ll> pcl;
typedef pair<ll, ll> pll;

#define PB push_back
#define F first 
#define S second
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    ll n;
    cin >> n;
    vl a;
    ll s = 0;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        s += tmp;
        a.PB(tmp);
    }
    sort(a.begin(), a.end());
    ll median = a[n/2];
    ll ans = 0;
    REP(i,0,n){
        ans += abs(a[i]-median);
    }
    cout << ans;
}

// - initial approach 
// iterate over the list and print the sum of absolute diff with the mean
// wa
// - modification
// used median to the same approach
// ac