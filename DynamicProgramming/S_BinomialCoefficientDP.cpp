#include <iostream>
#include <cstring>
using namespace std;

const int NIL=-1;
const int MAX=100;
int lookup[MAX];
/*
C(n, k) = C(n-1, k-1) + C(n-1, k)
C(n, 0) = C(n, n) = 1

5C3 = 4C2 + 4C3

ans = n! / (r!)(n-r)!
It is equal to:
Now notice that nominator and denominator have the same number of elements (k element)

So the calculation of ans will be like the following:
ans = n(n-1)(n-2)..(n-r+1) / r!
ans  = 1 // initially
ans *= n/1
ans *= (n-1)/2
ans *= (n-2)/3
.
.
.
ans *=  (n-r+1)/r

  1]  ans is being multiplied by n at each iteration
  2]  n is reduced by 1 at each iteration (n--)
  3]   ans is divided by j at each iteration


*/
// Iteration same Tabulation (botom Up return last value ) DP
int BioCof_Itr(int n,int r)
{
    int result=1;
    //Since C(n, r) = C(n, n-r)
    if( r > n-r)
        r=n-r;

    for (int i=1; i<=r ; i++)
    {
        result=result * (n- i + 1) / i ;
    }
    return result ;
}

// recursive version not memory efficient because F(1) is called 2 time
int BioCof_Rec(int n , int r)
{
    if(n==r || r==0 )
        return 1;
    return BioCof_Rec(n-1,r-1) + BioCof_Rec(n-1,r);

}

// Dp For memoized

int BioCof_DP(int n,int r)
{
    int lookup[n+1][r+1];
    int i, j;

    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, r); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                lookup[i][j] = 1;

            // Calculate value using previosly stored values
            else
                lookup[i][j] = lookup[i-1][j-1] + lookup[i-1][j];
        }
    }

    return lookup[n][r];

}


int BioCof_DP_Paskal (int n, int r)
{
    int C[r+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;  // nC0 is 1

    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row

        for (int j = min(i, r); j > 0; j--)
        {

            C[j] = C[j] + C[j-1];

        }

    }
    return C[r];
}

void inilize()
{
    int i;
    for (i = 0; i < MAX; i++)
    lookup[i] = NIL;
}

int main()
{
    int n,r;  
    inilize();
    cout<<" Enter Number (n r) =";
    cin>>n;cin>>r;
    cout<<"\n nCr Number Itr="<<BioCof_Itr(n,r)<<endl;
    cout<<"\n nCr Number Rec="<<BioCof_Rec(n,r)<<endl;
   cout<<"\n nCr Number DP="<<BioCof_DP(n,r)<<endl;
   cout<<"\n nCr Number DP Paskal="<<BioCof_DP_Paskal(n,r)<<endl;
    return 0;
}


