#include <iostream>
using namespace std;

const int NIL=-1;
const int MAX=100;
int lookup[MAX];

// Iteration same Tabulation (botom Up return last value ) DP
int Fac_Itr(int n)
{
    int fact=1;
    if( n<=1)
        return 1;
    for( int i=2 ; i<=n;++i)
    {
        fact=fact*i;

    }


    return fact;

}

// recursive version not memory efficient because F(1) is called 2 time
int Fac_Rec(int n)
{
    if(n<=1)
        return 1;
    return n*Fac_Rec(n-1);

}

// Dp For memoized

int Fac_DP(int n)
{
    if(lookup[n]=NIL)
    {
        if (n<=1)
            lookup[n]=1;
        else
            lookup[n]=n*Fac_DP(n-1);

    }

    return lookup[n];

}

void inilize()
{
    int i;
    for (i = 0; i < MAX; i++)
    lookup[i] = NIL;
}

int main()
{
    int num;
    inilize();
    cout<<" Enter Number=";
    cin>>num;
    cout<<"\n Fib Number Itr="<<Fac_Itr(num)<<endl;
    cout<<"\n Fib Number Rec="<<Fac_Rec(num)<<endl;
    cout<<"\n Fib Number DP="<<Fac_DP(num)<<endl;
    return 0;
}

