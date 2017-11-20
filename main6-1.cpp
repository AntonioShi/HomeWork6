#include <iostream>
#include <iomanip>
/*
 * 6-1
 */
using namespace std ;

int factorial(int n){
    if (n == 1)
        return 1 ;
    else
        return n * factorial(n-1) ;
}

int main6_1() {
    std::cout << "Hello, World!" << std::endl;
    int n, sum = 1;
    cin >> n ;
    for (int i = 2; i <= n; ++i) {
        sum += factorial(i) ;
    }
    cout << setw(4) << sum <<endl;
    return 0;
}