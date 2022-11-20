#include <iostream>
using namespace std;
bool traverse(int a[], int L, int R)
    /* algorithm properties:
    *  -Continuously divides the array.
    *  -Uses && to check for conditions recursivley.
    *  -Keeps dividing until all elements are check. 
    *  -Relies on the condition that the average 
    *   index does not equal the next index. 
    */
{
    if (L == R)
        return true;
    // finds the average between the two indices
    int M = (L + R) / 2;
  
    return (traverse(a,L, M) && traverse(a, M + 1, R) && (a[M] != a[M + 1]));
}   // checks to see if there are two subsequent elements that are equal.
int main()
{
    // left and right index
    int L, R;
    // array declaration and initialization
    int a[] = {10, 23, 98,98, 100, 105, 130, 150, 178};
    // finds the size of the array without hardcoding
    int N = sizeof(a) / sizeof(a[0]);
    // initializes indices
    L = 0;
    R = N-1;
    // outputs result from function
    cout << traverse(a, L, R) << endl;
}
/* recurrence relation:
* bool traverse(int a[], int L, int R)    {
    if (L == R)            comparison + 1   
        return true;
    int M = (L + R) / 2;     addition + 1
                             division + 1
    return (traverse(a, L, M) && 
            traverse(a, M + 1, R) && 
                (a[M] != a[M + 1]));
                           comparison + 3
                             addition + 2
}
*  recurrence relation    
*  Notice how we divide the array by two each time. 
*  So we get, recursive case: T(n) = C + 2T(n/2) 
*  2 comes from the recursivly called return
*  C comes from the returned base case
*  Using substitution, we can substitute T(n) for 2T(n) + C. 
*  Then we get...          
*  [1] T(n) = C + 2T(n/2)                       = C + 2T(n/2)
*  [2]      = C + 2(C + 2T(n/4))                = C + 2C + 4T(n/4)            
*                                               = 3C + 4T(n/4) 
*  [3]      = C + 2(C + 2(C + 2T(n/8)))         = C + 2C + 4C + 8T(n/8)       
*                                               = 7C + 8T(n/8)
*  [4]      = C + 2(C + 2(C + 2(C + 2T(n/16)))) = C + 2C + 4C + 8C + 16T(n/16)
*                                               = 15C + 16T(n/16) 
*                                               .
*                                               .
*                                               .
*                                               = (n-1)C + nT(1)
*                                               = (n-1)C + n(C) The second term will eventually become a constant.
*                                               =  nC-C + nC                           
*                                               =  2nC-C
*                                               =  C(2n-1)
*                                               =  O(n) linear time
*/
