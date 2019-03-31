    #include<stdio.h>
    #include<math.h>
    typedef long long int ll;
     
    int isPrime(ll x)
    {
        if(x == 2 || x == 3)
            return 1;
        for(int i = 2; i <= sqrt(x); i++)
            if(x%i == 0)
                return 0;
        return 1;
    }
     
    int main()
    {
        int t;
        ll n;
        
        scanf("%d",&t);
     
        while(t--)
        {
            scanf("%lld",&n);
            
            !isPrime(n+1) || n == 1 ? printf("YES\n") : printf("NO\n");
        }
    }
