#include <iostream>
using namespace std;

void (*pFun)(int);


typedef void (*func)(void);

void myfunc(void) { cout << "asda" << endl; }

void glFun(int a) { cout << a << endl; }
int main() {
  func pfun = myfunc; //赋值
  pfun();             //调用
  pFun = glFun;
  (*pFun)(2);
}