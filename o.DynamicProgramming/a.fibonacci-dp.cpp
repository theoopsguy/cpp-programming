// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/fibonacci-dp-official/ojquestion

#include <iostream>
using namespace std;

int fib(int n, int *qb){
    if (n == 0 || n == 1) {
        return n;
    }
    
    if (qb[n])
        return qb[n];
    
    int fib1 = fib(n-1, qb);
    int fib2 = fib(n-2, qb);
    
    qb[n] = fib1+fib2;
    
    return qb[n];
}

int main(){
    int n;
    cin>>n;
    int *arr = new int [n+1];
    cout<<fib(n, arr)<<endl;
    return 0;
}