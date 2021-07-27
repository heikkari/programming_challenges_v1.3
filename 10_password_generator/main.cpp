#include <random>
#include <iostream>

int random_number(int x, int y)
{
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> dist(x, y);
    return dist(rng);
}

int main()
{
    std::string alpha_num = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    // ---
    int n;
    std::cout << "Password length: ";
    std::cin >> n;

    std::string output;
    for(int i = 0; i < n; i++)
        output += alpha_num[random_number(0, alpha_num.length() - 1)];

    printf("Result: %s\n", output.c_str());
}