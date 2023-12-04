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
   vector<int> arr(n);
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   vector<int> next(x + 1, 0), curr(x + 1, 0);
   next[0] = 1, curr[0] = 1;
   for (int j = n - 1; j >= 0; j--)
   {
      for (int i = 1; i <= x; i++)
      {
         if (arr[j] <= i)
            curr[i] = (curr[i - arr[j]] + next[i]) % mod;
         else
            curr[i] = next[i] % mod;
      }
      next = curr;
   }
   cout << next[x] << "\n";
   return 0;
}                          // TC = O(n.x) SC = O(x)
/*
dp[i][j] = unique number of ways to create sum i when considering array [j....n-1]
Upon closer examination, we can observe that current entry of dp table depends on the current column
and next column. So, at any given point, we just need two column entries of dp table.
*/
