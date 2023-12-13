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
   vector<int> dp(10, INT_MAX);
   dp[0] = 0;
   for (int i = 1; i <= n; i++)
   {
      string str = to_string(i);
      for (char &ch : str)
      {
         int digit = ch - '0';
         if (digit != 0)
         {
            if (i > 9)
               dp[9] = min(dp[9], 1 + dp[9 - digit]);
            else
               dp[i] = min(dp[i], 1 + dp[ i - digit]);
         }
      }
      if (i > 9)
         for (int j = 0; j < 9; j++)
            dp[j] = dp[j + 1];
      dp[9] = INT_MAX;
   }
   cout << (n <= 9 ? dp[n] : dp[8]) << "\n";
   return 0;
}                          // TC = O(n.logn) SC = O(1)
/*
dp[i] denotes the minimum number of steps required to convert i to 0.
Upon closer examination, we can observe that since a digit n can have 0 to 9 digits in base 10,
hence, an entry n depends only on entries n-1 to n-9. Thus, we need only past 9 entries.
Hence, we just need a constant space of 10 array entries in each iteration.
*/

