#include<bits/stdc++.h>

#define int int64_t
#define pb emplace_back
#define mp make_pair
#define acc accumulate
#define f(n) for(int i=0;i<n;i++) 
#define f1(n) for(int i=1;i<n;i++) 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef vector<int> vi;

int dp[1002][1002];

int solve(vector<int> &v, int sum, int n){

    if(n == 0 && sum == 0){
        return 1;
    }

    if(n == 0){
        return 0;
    }

    if(sum == 0){
        return 1;
    }

    if(dp[n][sum] != 0){
        return dp[n][sum];
    }

    if(v[n-1] <= sum){
        return dp[n][sum] = solve(v, sum-v[n-1], n-1) + solve(v, sum, n-1);
    }else{
        return dp[n][sum] = solve(v, sum, n-1);
    }

    
}

int solve_top(vector<int> &v, int sum, int n){


    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(v[i-1] <= j){
                dp[i][j] = dp[i-1][j-v[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}


int32_t main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    
    int n; cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int sum; cin>>sum;

    // memset(dp, -1, sizeof(dp));
    // cout<<solve(v,sum,n)<<endl;

    cout<<solve_top(v, sum, n)<<endl;
    

    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

	return 0;
}