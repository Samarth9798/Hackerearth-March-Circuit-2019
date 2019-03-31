    import java.util.*;
    import java.io.*;
     
    class TestClass {
        public static void main(String args[] ) throws Exception {
            
            Scanner in = new Scanner(System.in);
            
            int n = in.nextInt();
            int m = in.nextInt();
            int g = in.nextInt();
            
            int t[] = new int[n+1];
            
            for(int i = 0; i < n; i++)
                t[i] = in.nextInt();
                
            int map[] = new int[10005];
            
            for(int i = 0; i < m; i++)
            {
                int temp = in.nextInt();
                map[temp]++;
            }
            
            Vector<Integer> diff = new Vector<Integer>();
            
            for(int i = 1; i < n; i++)
            {
                int temp = t[i] - t[i-1];
                diff.add(temp);
            }
            
            Collections.sort(diff);
            
            int ans = 0;
            for(int i = diff.size()-1; i >= 0; i--)
            {
                int f = 0;
                
                for(int j = 1; j <= diff.get(i); j++)
                {
                    if(map[j] > 0)
                    {
                        ans += map[j];
                        f = 1;
                        map[j] = 0;
                    }
                }
                
                if(f == 1)
                    g--;
                if(g == 0)
                    break;
            }
            
            System.out.print(ans);
        }
    }
