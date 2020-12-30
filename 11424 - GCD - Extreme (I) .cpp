//بسم الله الرحمن الرحيم

// ----->  Author :    N A Y E M
// ----->           [ CSE-19 , CU ]

#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
typedef unsigned long long ull ;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;
//using u128 = __uint128_t;
#define el << '\n'
#define PI 3.141592653589793238
#define _test_ int _ ; cin >> _ ; while( _-- )
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
ll gcd ( ll  a, ll b ) { return __gcd ( a, b ) ; }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ) ; }
ll big_mod(ll base , ll power , ll mod){ll ret=1;base%=mod;while(power){if(power&1)ret=ret*base%mod;base=base*base%mod;power>>=1;}return ret;}
ll mod_inverse(ll a , ll mod ){ return big_mod(a,mod-2,mod);}
ull POW(ll a , ll b){if(b==0) return 1;ull ret=1;while(b--)ret*=a;return ret;}
int dx[]={0,0,+1,-1,+1,-1,-1,+1} ;
int dy[]={+1,-1,0,0,+1,-1,+1,-1} ;
// ------------------>
const ll infLL = 1e15;
const int inf = 1e9;
const ll mod = 1e9+7;
const ll mx = 200001+123;
// ------------------>
ll ans[mx];
bitset<mx>vis;
vl prime;

void sieve()
{
    prime.push_back(2);
    for(ll i=3;i*i<=mx;i+=2)
        if(!vis[i])
            for(ll j=i*i;j<mx;j+=2*i)
                vis[j]=1;
    for(ll i=3;i<mx;i+=2)
        if(!vis[i])
            prime.push_back(i);
}

ll solve(ll n)
{
    ll ret=1LL;
    for(auto p:prime)
    {
        if(p*p>n) break;
        if(n%p==0)
        {
            int cnt=0;
            while(n%p==0)
            {
                cnt++;
                n/=p;
            }
            ret*=(((cnt+1LL)*POW(p,cnt))-(cnt*POW(p,cnt-1LL)));
        }
    }
    if(n!=1)
    {
        ret*=((2*n)-1);
    }
    return ret;
}


int main( )
{
    optimize() ;
    sieve();
    ll T,n;
    for(int i=1;i<mx;i++)
        ans[i]=solve(i)-i;
    for(int i=1;i<mx;i++)
        ans[i]+=ans[i-1];
    while(cin >> n and n!=0)
    {
        cout << ans[n] el;
    }
    return 0;
}
