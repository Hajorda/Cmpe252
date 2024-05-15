#include <stdio.h>
#include <iostream>

using namespace std;

int fun(int a, int b){
cout<<"a="<<a<<endl;
cout<<"b="<<b<<endl;
return a+b;
}
int main() {
int i=5;
int result=fun(i++,i++);
cout<<"i="<<i<<endl;
cout<<5 % 7<<endl;
}