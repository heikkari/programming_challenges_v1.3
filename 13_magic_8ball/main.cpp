#include <iostream>
#include <string>
#include <random>

int condense(int n)
{
    int copy_n = n;
    int remainder = 0;
    int result = 0;

    while(copy_n != 0)
    {
        remainder = copy_n % 10;
        result += remainder;
        copy_n /= 10;
    }

    return result;
}

int main()
{
    std::string input;
    std::cout << "What's your question? ";
    std::cin >> input;
    int magic_number = 1;

    if(input.length() > 9)
        input = input.substr(0, 4);

    for(const auto& c: input)
        magic_number *= (c * 0.333);

    while(magic_number > 9)
        magic_number = condense(magic_number);

    printf("Result: ");

    switch(magic_number)
    {
        case 0:
        case 1:
        case 2:
            printf("Maybe");
            break;
        case 3:
        case 4:
        case 5:
            printf("No");
            break;
        case 6:
        case 7:
            printf("Probably");
            break;
        case 8:
        case 9:
            printf("Yes");
            break;
    }

    printf(".\n");
    return 0;
}