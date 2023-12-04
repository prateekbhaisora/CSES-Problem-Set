#include<bits/stdc++.h>
#define pr pair<int, int>
#define triplet pair<ll,pair<ll,ll>>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
 
void init_code()
{
   fast_io;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
 
int main()
{
   init_code();
   read(n);
   read(x);
   int arr[n];
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   vector<ll> dp(x + 1, 0);
   dp[0] = 1;
   for (int i = 1; i <= x; i++)
      for (int j = 0; j < n; j++)
         if (arr[j] <= i)
            dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
   cout << dp[x] << "\n";
   return 0;
}                          // TC = O(n.x) SC = O(x)
