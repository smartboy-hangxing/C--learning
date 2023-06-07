#include <iostream>
using namespace std;

int main() {
 
    for (int i = 0; i < 2; i++ ){
       cout << i;
    }

    int i;
    for (i = 0; i < 2; i++){
        cout << i;
    }
 
    i = 0;
    while (i < 2){
        cout << i++;
    }
   
}