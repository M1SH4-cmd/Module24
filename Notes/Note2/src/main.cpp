#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    time_t t = time(nullptr);
    tm local = *localtime(&t);
    cin >> get_time(&local, "%H:%M");
    cout << asctime(&local) << endl;
}