
                                             // 𝕀ℕ 𝕋ℍ𝔼 ℕ𝔸𝕄𝔼 𝕆𝔽 𝔸𝕃𝕃𝔸ℍ //
 
 
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
// --------------------------------------------------------------------------------------------------------------->
 
#define sa(v) sort(v.begin(),v.end())
#define sd(v) sort(v.begin(),v.end(),greater<>()) 
#define el << '\n'
#define pb push_back
#define PI 3.141592653589793238
#define _test_ int _ ; cin >> _ ; while( _-- )
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 
// --------------------------------------------------------------------------------------------------------------->
 
int dx[]={0,0,+1,-1,+1,-1,-1,+1};
int dy[]={+1,-1,0,0,+1,-1,+1,-1};
const ll infLL = 1e18;
const ll inf = 1e16+7;
const int mod = 1e9+7;
const int mx = 1e5+123;
 
// --------------------------------------------------------------------------------------------------------------->

int arr[mx],seg[3*mx],cnt[mx],start[mx];
map<int,int>mp;

void build(int ind,int low , int high)
{

            if(low==high) 
            {
                        seg[ind]=cnt[low];
                        return;
            }
            int mid=(low+high)/2;
            int leftind=2*ind;
            int rightind=2*ind+1;
            build(leftind,low,mid);
            build(rightind,mid+1,high);
            seg[ind]=max(seg[leftind],seg[rightind]);

}

int query(int ind,int low,int high,int l,int r)
{

            if(low>=l and high<=r)
            {
                        return seg[ind];
            }
            if(high<l or low>r) return INT_MIN;
            int leftind=2*ind;
            int rightind=2*ind+1;
            int mid=(low+high)/2;
            int left=query(leftind,low,mid,l,r);
            int right=query(rightind,mid+1,high,l,r);
            return max(left,right);

}



void _case_()
{
        int n,q;
        while(cin >> n)
        {
                if(n==0) break;
                mp.clear();
                cin >> q;
                for(int i=1;i<=n;i++)
                {
                        cin >> arr[i];
                        mp[arr[i]]++;
                }
                arr[0]=arr[1]-1;
                for(int i=1;i<=n;i++)
                {
                        cnt[i]=mp[arr[i]];
                        if(arr[i]==arr[i-1]) start[i]=start[i-1];
                        else start[i]=i;
                }
                build(1,1,n);
                while(q--)
                {
                        int l,r;
                        cin >> l >> r;
                        if(arr[l]!=arr[r])
                        {
                                int k=start[l]+cnt[l];
                                int cnt1=k-l;
                                int cnt2=r-start[r]+1;
                                int cnt3=query(1,1,n,k,start[r]-1);
                                cout << max(cnt1,max(cnt2,cnt3)) << endl;
                        }
                        else cout << r-l+1 << endl;
                }
        }
}
 
int main()
{
        optimize();
        //file()
        //_test_
                _case_();
        return 0;
}
                                                   // 𝖓𝖔𝖔𝖇𝖒𝖆𝖘𝖙𝖊𝖗 //
