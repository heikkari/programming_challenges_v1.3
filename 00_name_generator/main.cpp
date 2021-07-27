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
    int length = 4;

    std::string first_names[] = { "John", "Francis", "Tom", "Brad", "Ludwig" };
    std::string last_names[] = { "Smith", "Williams", "Brown", "Jones", "Davis" };

    int first_n = random_number(0, length);
    int second_n = random_number(0, length);

    printf("%s %s\n", first_names[first_n].c_str(), last_names[second_n].c_str());
    return 0;
}