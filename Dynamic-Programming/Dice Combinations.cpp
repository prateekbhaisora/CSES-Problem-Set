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
   int dp[n + 1] = {0};
   dp[0] = 1;
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= 6 ; j++)
         if (j <= i)
            dp[i] = (dp[i] + dp[i - j]) % mod;
   cout << dp[n] << "\n";
   return 0;
}                          // TC = O(n) SC = O(n)

/*
dp[i] denotes number of ways to create sum i
*/
