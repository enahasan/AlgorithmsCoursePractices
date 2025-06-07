#include <iostream>
using namespace std;
// This code implements the Fibonacci sequence using recursion
// The Fibonacci sequence is defined as follows:
int Fib(int n){
    if (n <= 1){
        return n;
    } 
    else {    return Fib(n - 1) + Fib(n - 2);
} }

int main(){
    int n;
    cout << "Enter how many Fibonacci numbers you want: ";
    cin >> n;

    cout << "Fibonacci sequence up to " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++){
        cout << Fib(i) << " "; 
    }
    cout << endl;

    return 0;
}