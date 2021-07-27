#include <iostream>

int main()
{
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "Your age in seconds is " << age * 31557600 << std::endl;
}