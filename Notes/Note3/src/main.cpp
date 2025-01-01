#include <iostream>
#include <ctime>
#include <iomanip>
int main()
{
    std::time_t a = std::time(nullptr);
    int foo;
    std::cin >> foo;
    std::time_t b = std::time(nullptr);

    double d = std::difftime(a, b);
    std::time_t s = b + (std::time_t)d;
    
    std::tm* local_future = std::localtime(&s);
    std::cout << asctime(local_future) << std::endl; 
}