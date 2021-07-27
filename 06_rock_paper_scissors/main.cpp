#include <iostream>
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
    int player_choice;
    std::cout << "Choose: rock (0), paper (1), or scissors (2): ";
    std::cin >> player_choice;

    int enemy_choice = random_number(0, 2);

    // ---
    bool did_player_win =
        player_choice == 0 && enemy_choice == 2 || // rock > scissors
        player_choice == 1 && enemy_choice == 0 || // paper > rock
        player_choice == 2 && enemy_choice == 1;   // scissors > paper

    if(did_player_win) printf("You won!");
    else if(player_choice == enemy_choice) printf("You tied.");
    else printf("You lost.");

    printf("\n");
}