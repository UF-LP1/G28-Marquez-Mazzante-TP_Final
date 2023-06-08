#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int num = 6 + rand() % (8 - 5);
        cout << num;
    }
    return 0;
}