
#include <iostream>
#include <cstring>
using namespace std;

/*
 *Given two sequences, find the length of longest subsequence present in both of them. 
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 

So a string of length n has 2^n different possible subsequences. 

It is a classic computer science problem, the basis of diff 
(a file comparison program that outputs the differences between two files), and has applications in bioinformatics. 

Examples: 
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4. 

*/

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int Lcs_Rec( char *X, char *Y, int m, int n ) 
{ 
   if (m == 0 || n == 0) 
     return 0; 
   if (X[m-1] == Y[n-1]) 
     return 1 + Lcs_Rec(X, Y, m-1, n-1); 
   else 
     return max(Lcs_Rec(X, Y, m, n-1), Lcs_Rec(X, Y, m-1, n)); 
} 

int Lcs_DP( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   int i, j; 
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */ 
   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
  
       else 
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */ 
   return L[m][n]; 
} 

int main(int argc, char **argv)
{
	char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
 
  int m = strlen(X); 
  int n = strlen(Y); 
 
 cout <<" Length of LCS is "<< Lcs_Rec( X,Y , m,n) <<endl;
 cout <<" Length of LCS is "<< Lcs_DP( X,Y , m,n) <<endl;
  
	
	return 0;
}

