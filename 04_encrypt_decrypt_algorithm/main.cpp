#include <iostream>
#include <string>

class cipher
{
private:
    int m_uppercase;
    int m_lowercase;
    std::string allowed;

public:
    cipher()
    {
        this->m_uppercase = 64;
        this->m_lowercase = 96;
        this->allowed = "`.:;-?! ";
    }

    /* true = encrypt, false = decrypt */
    char crypt_char(char src, int crypt_key, bool crypt_mode)
    {
        bool cond = this->allowed.find(src) != std::string::npos;

        // will add a number if character is lowercase
        int uppercase = this->m_uppercase * ((bool)std::isupper(src));

        // will add a number if character is lowercase
        int lowercase = this->m_lowercase * (!std::isupper(src));

        if (!(isalnum(src) || cond))
        {
            printf("Alphanumeric characters and punctuation only\n");
            exit(1);
        }

        if (cond)
            return src;

        int alphabet_position = src - uppercase - lowercase;
        int key = crypt_key;
        int out = alphabet_position;

        while (key != 0)
        {
            // add 1 if encrypting, subtract 1 otherwise
            out += (1 * crypt_mode) + (-1 * !crypt_mode);

            // if the number goes below 0, set it to 26
            out = 26 * (out < 0) + out * (out > 0);

            // if the number goes above 26, reset it
            out = out * (out < 27);

            // decrement key
            key--;
        }

        return out + uppercase + lowercase;
    }
};

int main()
{
    cipher c;

    // ---
    bool crypt_mode;
    std::cout << "Decrypt (0) or encrypt (1): ";
    std::cin >> crypt_mode;

    // ---
    int key;
    std::cout << "Key (number): ";
    std::cin >> key;

    // ---
    std::cin.ignore();
    std::string input;
    std::cout << "Input: ";
    std::getline(std::cin, input);

    // ---
    std::string crypted;

    for (const char &ch : input)
        crypted += c.crypt_char(ch, key, crypt_mode);

    std::cout << "Result: " << crypted << std::endl;
    return 0;
}