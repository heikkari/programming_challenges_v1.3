#include <iostream>

int main()
{
    std::string your_name;
    std::cout << "Your name: ";
    std::getline(std::cin, your_name);

    std::string crush_name;
    std::cout << "Your crush's name: ";
    std::getline(std::cin, crush_name);

    float love_formula = ((float)your_name.length() * 0.623 / (float)crush_name.length());
    printf("Result: %.1f%\n", love_formula * 100);
}