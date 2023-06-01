#include <iostream>
using namespace std;

int main() {
    enum days { one, two, three }day;
    day = two;
    switch (day) {
    case one:
        cout << "one" << endl;
        break;
    case two:
        cout << "two" << endl;
        break;
    default:
        cout << "three" << endl;
        break;
    }
    return 0;
    system("pause");
}





#include <iostream>
#include <string>

using namespace std;


enum DAY { monday = 1, Tuesday, Wednesday, cThursday, Thursday };

int main(int argc, char** argv) {
    string x;
    cout << "Day: " << endl;
    cin >> x;
    DAY neww;
    neww = x;
    cout << neww << endl;
    return 0;
}