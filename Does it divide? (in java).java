    import java.util.*;
    import java.io.*;
     
    class TestClass {
        
        static boolean prime(long n)
        {
            if(n == 2)
                return true;
            
            for(int i = 2; i <= Math.sqrt(n); i++)
            {
                if(n%i == 0)
                    return false;
            }
        
            return  true;
        }
        
        public static void main(String args[] ) throws Exception {
            
            Scanner in = new Scanner(System.in);
            
            int t = in.nextInt();
            
            while(t-- > 0)
            {
                long n = in.nextLong();
                
                if(!prime(n+1) || n == 1)
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
        }
    }
