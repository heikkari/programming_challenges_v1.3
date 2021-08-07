#include <iostream>
#include <random>
#include <vector>

int random_number(int x, int y)
{
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> dist(x, y);
    return dist(rng);
}

std::vector<std::string> dictionary()
{
    std::vector<std::string> dictionary;

    // ---
    dictionary.push_back("what");
    dictionary.push_back("this");
    dictionary.push_back("is");
    dictionary.push_back("him");
    dictionary.push_back("will");
    dictionary.push_back("he");
    dictionary.push_back("she");
    dictionary.push_back("it");
    dictionary.push_back("or");
    dictionary.push_back("and");
    dictionary.push_back("they");
    dictionary.push_back("there");
    dictionary.push_back("which");
    dictionary.push_back("do");
    dictionary.push_back("not");
    dictionary.push_back("but");
    dictionary.push_back("are");
    dictionary.push_back("be");

    return dictionary;
}

int main()
{
    int n;
    std::cout << "How many words per sentence? ";
    std::cin >> n;

    // ---
    std::vector<std::string> dict = dictionary();
    std::string output;

    for (int i = 0; i < n; i++)
    {
        int random_n = random_number(0, dict.size());
        output += dict[random_n] + " ";
    }

    printf("Result: %s\n", output.c_str());
}