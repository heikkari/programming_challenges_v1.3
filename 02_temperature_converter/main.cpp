#include <iostream>

int main()
{

    bool choice;
    std::cout << "Celsius to Fahrenheit (0) or Fahrenheit to Celsius (1): ";
    std::cin >> choice;

    // ---
    std::string from;

    if (choice)
        from = "Fahrenheit";
    else
        from = "Celsius";

    float n;
    std::cout << "Enter tempature in " << from.c_str() << ": ";
    std::cin >> n;

    if (choice)
        n = (n * 9 / 5) + 32;
    else
        n = (n - 32) * 5 / 9;

    printf("Result: %.3f\n", n);
}