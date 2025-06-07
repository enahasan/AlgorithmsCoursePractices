#include <iostream>
using namespace std;
// This code implements the Fibonacci sequence using recursion
int Fib(int n){ // Function to calculate the nth Fibonacci number
    if (n <= 1){ // Base case: if n is 0 or 1, return n
        return n; 
    } 
    else {    return Fib(n - 1) + Fib(n - 2); // Recursive case: return the sum of the two preceding Fibonacci numbers
} }
// This code prints the Fibonacci sequence up to n numbers
int main(){ 
    int n;
    cout << "Enter how many Fibonacci numbers you want: ";
    cin >> n;

    cout << "Fibonacci sequence up to " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++){ // Loop from 0 to n-1
        cout << Fib(i) << " ";  // Call the Fib function to get the ith Fibonacci number and print it
    }
    cout << endl;

    return 0;
}