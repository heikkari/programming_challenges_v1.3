#include <cstdio>
#include <string>
#include <random>

int random_number(int x, int y)
{
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> dist(x, y);
    return dist(rng);
}

int main()
{
    if((bool)random_number(0, 1))
        printf("Heads");
    else
        printf("Tails");

    printf("\n");
    return 0;
}