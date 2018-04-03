#include <bits/stdc++.h>

using namespace std;

#define mod ((long long)1e9 + 7)

const int N = 1234;

long long p[N], dp[N], n;

int main() {
	memset(dp, 0, sizeof dp);
	
    cin>>n;
    for (int i = 1; i <= n; i++)
    	cin>>p[i];
    
    dp[1] = 2;
    for (int i = 2; i <= n; i++) {
    	dp[i] = 2;
    	for (int j = p[i]; j < i; j++)
    		dp[i] = (dp[i] + dp[j])%mod;
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    	ans = (ans + dp[i])%mod;
    	
    cout<<ans<<endl;
    return 0;
}