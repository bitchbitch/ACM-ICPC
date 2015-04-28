[n,m,a]=map(int,raw_input().split())
sum = 0 
if n % a == 0 :
    sum += n/a;
else:
    sum += n/a + 1;
if m % a == 0 :
    sum *= m/a;
else:
    sum *= m/a + 1;
print sum
