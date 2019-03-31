    #include<stdio.h>
    typedef long long int ll;
     
    const ll mod = 1e9+7;
    ll a[100005];
    ll n,l,r;
    ll c[100005];
    ll dp[100005];
     
    ll solve(int id)
    {
        if(id >= n)
        {
            dp[id] = 1;
            return 1;
        }
        
        ll cc = 0;
        ll temp = 0;
        for(int i = id; i <= n; i++)
        {
            temp = temp + a[i];
            
            if(temp >= l && temp <= r && (c[i+1] >= l || c[i+1] == 0))
            {
                if(dp[i+1] == -1)
                {
                    cc = (cc + solve(i+1))%mod;
                }
                else
                {
                    cc = (cc + dp[i+1])%mod;
                }
            }
            else if(temp > r)
                break;
        }
        
        dp[id] = cc;
        return cc;
    }
     
    int main()
    {
        //input n,l,r
        scanf("%lld%lld%lld",&n,&l,&r);
     
        //input a[i]
        for(ll i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
        }
        
        //find prefix sum
        ll sum = 0;
        memset(c,0,sizeof(c));
        for(int i = n; i >= 1; i--)
        {
            sum += a[i];
            c[i] = sum;
        }
        
        //initialize the intial value with -1
        memset(dp,-1,sizeof(dp));
        
        //output ans
        printf("%lld",solve(1)%mod);
    }
