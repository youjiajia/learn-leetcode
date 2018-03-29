#include <stdio.h>
#include <string.h>
#define N 5
#define M 5
int k, Found, Flag[N];
int Stamp[M] = {0, 1, 4, 12, 21};
// 在剩余张数n中组合出面值和Value
int Combine(int n, int Value)
{
if(n >= 0 && Value == 0)
{
   Found = 1;
   int Sum = 0;
   for(int i=0; i<N && Flag[i] != 0; i++)
   {
    Sum += Stamp[Flag[i]];
    printf("%d ", Stamp[Flag[i]]);
   }
   printf("\tSum=%d\n\n", Sum);
}
   for(int i=1; i<M && !Found && n>0; i++)
   if(Value-Stamp[i] >= 0)
   {
    Flag[k++] = i;
    Combine(n-1, Value-Stamp[i]);
    Flag[--k] = 0;
   }
return Found;
}
int main(int argc, char* argv[])
{
   for(int i=1; Combine(N, i); i++, Found=0);
}