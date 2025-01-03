#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#if defined( _WIN32 )
typedef __int64 az_int64_t;
typedef unsigned __int64 az_uint64_t;
#define I64(x) x ## I64
#define F64 "I64"
#else
typedef long long az_int64_t;
typedef unsigned long long az_uint64_t;
#define I64(x) x ## ll
#define F64 "ll"
#endif

#define LIMIT 100000000
#define HAS(_n) (pbits[(_n)>>5] & (1u << ((_n) & 0x1f)))
#define SET(_n) (pbits[(_n)>>5] |= (1u << ((_n) & 0x1f)))
unsigned int pbits[LIMIT/32+1];
int pc, pr[LIMIT/10];

void sieve( void )
{
  int i, j;
  pc = 0;
  for( i = 2; i <= LIMIT; ++i)
  {
    if( !HAS( i ) ) pr[pc++] = i;
    for( j = 0; j < pc && i * pr[j] <= LIMIT; ++j)
    {
      int num = i * pr[j];
      SET( num );
      if( i % pr[j] == 0 ) break;
    }
  }
}

az_int64_t solution( az_int64_t n )
{
  az_int64_t o = n, ans = 1;
  int i;
  for( i = 0; i < pc && (az_int64_t) pr[i] * pr[i] <= n; ++i)
  {
    int count = 0;
    az_int64_t sum = 1, pw = 1;
    while( n % pr[i] == 0 )
    {
      pw *= pr[i];
      sum += pw;
      count++;
      n /= pr[i];
    }
    if( count > 0 ) ans *= sum;
  }
  if( n > 1 ) ans *= n + 1;
  return ans - o;
}

int main( void )
{
  int t;
  sieve();
  scanf( "%d", &t);
  while( t-- > 0 )
  {
    az_int64_t n;
    scanf( "%" F64 "d", &n);
    printf( "%" F64 "d\n", solution( n ));
  }
  return 0;
}