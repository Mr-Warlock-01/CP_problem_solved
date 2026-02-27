a, n, M = map(int, input().split())

mp={}

def xxx(n, M):
    if(n==1):
        return a % M
    if(mp.get(n) != None):
        return mp[n]
    ans=0;
    if(n%2==0):
        ans=(xxx(n//2, M) * xxx(n//2, M)) % M
        ans-=2
        if(ans<0):
            ans+=M
            
    else: 
        ans=(xxx((n+1)//2, M) * xxx(n//2, M)) % M
        ans=(ans - a) % M
        if(ans<0):
            ans+=M

    mp[n] = ans
    return ans

if(n==0):
    print(2 % M)
else:
    print(xxx(n, M) % M )