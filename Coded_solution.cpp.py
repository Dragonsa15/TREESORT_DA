t=int(input())
for i in range (t):
    n=int(input())
    b={}
    mn=[10000000]*n
    mx=[0]*n
    ans=0
    for j in range (n):
        y,z=map(int,input().split())
        if(y==-1):
            mn[j]=z
            mx[j]=z
        else:
            b[j+1]=[y,z]

print(b)
print(mn)
print(mx)