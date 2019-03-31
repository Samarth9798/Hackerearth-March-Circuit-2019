    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
     
    struct line
    {
        ll x1,x2,y1,y2;
    }
    T[100005];
     
    bool comp1(line a, line b)
    {
        return a.x1 < b.x1;
    }
     
    bool comp2(line a, line b)
    {
        return a.y1 < b.y1;
    }
     
    int BinarySearch(vector<ll>& v, int l, int r, int key) 
    { 
        while (r - l > 1) 
        { 
            int m = l + (r - l) / 2; 
            if (v[m] >= key) 
                r = m; 
            else
                l = m; 
        } 
      
        return r; 
    } 
      
    int LIS(vector<ll>& v) 
    { 
        if (v.size() == 0) 
            return 0; 
      
        vector<ll> tail(v.size(), 0); 
        int length = 1;
      
        tail[0] = v[0]; 
        for (size_t i = 1; i < v.size(); i++) { 
     
            if (v[i] < tail[0]) 
                tail[0] = v[i];
            else if (v[i] > tail[length - 1]) 
                tail[length++] = v[i];
            else
                tail[BinarySearch(tail, -1, length - 1, v[i])] = v[i]; 
        } 
      
        return length; 
    } 
     
    int main()
    {
        //code here
        ll n;
        cin >> n;
        
        for(int i = 0; i < n; i++)
        {
            cin >> T[i].x1 >> T[i].y1 >> T[i].x2 >> T[i].y2;
        }
        
        int f = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(T[i-1].x1 != T[i].x1)
            {
                f = 1;
                break;
            }
        }
        
        vector<ll> v;
        
        if(f == 1)
        {
            sort(T,T+n,comp1);
            
            for(int i = 0; i < n; i++)
            {
                v.push_back(T[i].x2);
            }
        }
        else
        {
            sort(T,T+n,comp2);
        
            for(int i = 0; i < n; i++)
            {
                v.push_back(T[i].y2);
            }
        }
        
        cout << LIS(v);
    }
