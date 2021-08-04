#include <iostream>

int main()
{
    int x;
    int steps = 0;
    std::string output;
    std::cout << "x=";
    std::cin >> x;

    while(x != 1)
    {
        output += std::to_string(x);
        output += ", ";

        if(x % 2 == 0)
            x /= 2;
        else
            x = 3 * x + 1;

        steps += 1;
    }

    output += "0.";

    printf("Numbers: %s\n", output.c_str());
    printf("Steps: %d\n", steps);
}