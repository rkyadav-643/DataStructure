#include <iostream>
using namespace std;

const int NIL=-1;
const int MAX=100;
int lookup[MAX];

// Iteration same Tabulation (botom Up return last value ) DP
int Fib_Itr(int n)
{
    int a=0,b=1,c;
    if( n<=1)
        return n;
    for( int i=2 ; i<n;++i)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;

}

// recursive version not memory efficient because F(1) is called 2 time
int Fib_Rec(int n)
{
    if(n<=1)
        return n;
    return (Fib_Rec(n-1) + Fib_Rec(n-2));

}

// Dp For memoized

int Fib_DP(int n)
{
    if(lookup[n]=NIL)
    {
        if (n<=1)
            lookup[n]=n;
        else
            lookup[n]=Fib_DP(n-1) + Fib_DP(n-2);


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
    cout<<"\n Fib Number Itr="<<Fib_Itr(num)<<endl;
    cout<<"\n Fib Number Rec="<<Fib_Rec(num)<<endl;
    cout<<"\n Fib Number DP="<<Fib_DP(num)<<endl;
    return 0;
}
