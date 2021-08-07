#include <iostream>
#include <algorithm>

void strip(std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');

    if (first == std::string::npos)
        return;

    str = str.substr(first, (last - first + 1));
}

void remove_repeating_spaces(std::string &s)
{
    auto iter = std::unique(s.begin(), s.end(), [](char l, char r) {
        return l == r && std::isspace(l);
    });
    s.erase(iter, s.end());
}

int main()
{
    // ---
    std::string input;
    std::cout << "Your string: ";
    std::getline(std::cin, input);

    // ---
    strip(input);
    remove_repeating_spaces(input);
    size_t n = std::count(input.begin(), input.end(), (char)0x20);

    printf("Result: Found %zu words.\n", n + 1);
    return 0;
}