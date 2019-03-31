import math
 
def isPrime(n):
    if n == 2:
        return True
    for i in range(2,int(math.sqrt(n)+1)):
        if n%i == 0:
            return False
    return True
    
t = int(input())
 
while t:
    
    n = int(input())
    
    if isPrime(n+1) and n != 1:
        print("NO")
    else:
        print("YES")
        
    t-=1
