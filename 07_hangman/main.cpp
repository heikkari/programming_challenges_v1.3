#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

struct word
{
    public:
        std::string content;
        std::string hint;

        word() {}

        word(const std::string &content, const std::string &hint)
        {
            this->content = content;
            this->hint = hint;
        }
};

class hangman
{
    private:
        std::vector<word> m_words;
        std::vector<char> m_current_guess;
        word m_current_word;
        size_t m_max_attempts;
        size_t m_current_attempt;

    public:
        hangman()
        {
            this->m_words =
            {
                word("Tajikistan", "A country in Central Asia."),
                word("ocean", "A large body of water."),
                word("superior", "Synonym of greater.")
            };
            this->m_current_attempt = 0;
            this->m_max_attempts = 10;
        }

        int random_number(int x, int y)
        {
            std::random_device device;
            std::mt19937 rng(device());
            std::uniform_int_distribution<std::mt19937::result_type> dist(x, y);
            return dist(rng);
        }

        void guess(char guess)
        {
            if(this->m_current_guess.size() == 0)
            {
                printf("this->m_current_guess is not set\n");
                exit(1);
            }

            if(this->m_current_word.content.size() == 0)
            {
                printf("this->m_current_word is not set\n");
                exit(1);
            }

            if(this->m_current_guess.size() != this->m_current_word.content.size())
            {
                printf("this->m_current_guess must have the same length as this->m_current_word.content");
                exit(1);
            }

            if(guess != '\0')
            {
                auto content = this->m_current_word.content;
                int total_guessed = 0;

                for(int i = 0; i < content.size(); i++)
                {
                    int guessed = content[i] == guess;
                    this->m_current_guess[i] = (guess * guessed) + (this->m_current_guess[i] * !guessed);
                    total_guessed += guessed;
                }

                this->m_current_attempt += (int)(total_guessed == 0);
            }

            // ---
            std::cout << "The word is";
            for(const auto& c: this->m_current_guess)
                std::cout << " " << c;
            std::cout << "." << std::endl;

            // display remaining attempts
            printf("You have %zu attempts left.\n", this->m_max_attempts - this->m_current_attempt);
        }

        bool game_over_conditions()
        {
            bool no_unknown = std::find(
                this->m_current_guess.begin(),
                this->m_current_guess.end(),
                '_'
            ) == this->m_current_guess.end();

            if(no_unknown)
            {
                printf("Game over - You won!\n");
                printf("The word was: %s\n", this->m_current_word.content.c_str());
                return true;
            }

            if(this->m_current_attempt == this->m_max_attempts)
            {
                printf("Game over - You reached the maximum attempts allowed.\n");
                printf("The word was: %s\n", this->m_current_word.content.c_str());
                return true;
            }

            return false;
        }

        void play_game()
        {
            // setup game
            int n = this->random_number(0, this->m_words.size());
            this->m_current_word = this->m_words[n];
            for(int i = 0; i < this->m_current_word.content.size(); i++)
                this->m_current_guess.push_back('_');

            printf("Type ? for a hint.\n");
            this->guess('\0');

            while(true)
            {
                if(this->game_over_conditions()) break;

                char current_guess;
                std::cout << "Your guess (a single character): ";
                std::cin >> current_guess;

                if(!isalnum(current_guess)) continue;

                if(current_guess == '?')
                {
                    printf("Hint: %s\n", this->m_current_word.hint.c_str());
                    continue;
                } else this->guess(current_guess);
            }
        }
};

int main()
{
    hangman game;
    game.play_game();
    return 0;
}