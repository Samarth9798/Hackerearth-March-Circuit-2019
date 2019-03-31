    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
     
    int main()
    {
        //code here
        
        int n,m,g;
        
        cin >> n >> m >> g;
        
        int t[n+5];
        
        for(int i = 0; i < n; i++)
            cin >> t[i];
            
        int a[m+5];
        
        for(int i = 0; i < m; i++)
            cin >> a[i];
            
        int c[10005];
        
        memset(c,0,sizeof(c));
        
        for(int i = 0; i < m; i++)
        {
            c[a[i]]++;
        }
        
        int ans = 0;
        int diff;
        
        vector<int> v;
        
        for(int i = 1; i < n; i++)
        {
            diff = t[i] - t[i-1];
            
            v.push_back(diff);
            
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        for(int i = 0; i < v.size(); i++)
        {
            int f = 0;
            
            diff = v[i];
            
            if(diff > 10000)
                diff = 10000;
                
            if(g > 0)
            {
                for(int j = 1; j <= diff; j++)
                {
                    if(c[j] > 0)
                    {
                        ans = ans + c[j];
                        c[j] = 0;
                        f = 1;
                    }
                }
            }
            
            if(f == 1)
                g--;
                
            if(g == 0)
                break;
        }
        
        cout << ans;
    }
