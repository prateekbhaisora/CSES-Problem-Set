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
   int arr[n][n];
   for (int i = 0; i < n; i++)
   {
      int j = 0;
      string str;
      cin >> str;
      for (char &ch : str)
         arr[i][j++] = ch == '.' ? 1 : 0;
   }
   if (arr[0][0] == 0 || arr[n - 1][n - 1] == 0)
   {
      cout << 0 << "\n";
      return 0;
   }
   vector<vector<int>> dp(2, vector<int>(n, 0));
   dp[1][n - 1] = dp[0][n - 1] = 1;
   for (int i = n - 1; i >= 0; i--)
   {
      for (int j = n - 1; j >= 0; j--)
      {
         if ((i == n - 1 && j == n - 1) || arr[i][j] == 0)
            continue;
         if (i + 1 < n)
            dp[0][j] = (dp[0][j] + dp[1][j]) % mod;
         if (j + 1 < n)
            dp[0][j] = (dp[0][j] + dp[0][j + 1]) % mod;
      }
      for (int k = 0; k < n; k++)
      {
         dp[1][k] = dp[0][k];
         dp[0][k] = 0;
      }
   }
   cout << dp[1][0] << "\n";
   return 0;
}                          // TC = O(n^2) SC = O(n)
/*
dp[i][j] denotes the number of paths to reach arr[n-1][n-1] from arr[i][j].
Upon closer examination, we can observe that each entry depends on the current row next column entry
and/or the next row current column entry. This basically means that current rows entries depend only on
the next rows entries. So, we can simply use a 2*n grid and solve it in O(n) space.
*/

