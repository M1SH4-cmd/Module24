#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    time_t t = time(nullptr);
    tm* local = localtime(&t);
    cout << "Current date and time: " << put_time(local, "%d/%m/%Y : %H:%M:%S") << endl;
}