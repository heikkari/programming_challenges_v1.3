#include <iostream>

int main()
{
    std::string output;
    std::string input;
    std::cout << "Text: ";
    std::cin >> input;

    for(int i = input.length() - 1; i >= 0; i--)
        output += input[i];

    printf("Result: %s\n", output.c_str());
    return 0;
}