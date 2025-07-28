#include <cctype>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class strength
{
private:
    int length = 0;
    string word = "";
    bool fail = false;

public:
    strength(int length, string word = "EMPTY")
    {
        this->word = word;
    }

    string getWord() const
    {
        return word;
    }

    void setWord(string word)
    {
        this->word = word;
    }

    void lengthrequirement(string word)
    {
        if (word.length() < 8)
        {
            cout << "password is too short" << endl;
            fail = true;
        }
    }

    void numbercheck(string word)
    {
        bool num = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (isdigit(word[i]) == true)
            {
                num = true;
            }
        }

        if (!num)
        {
            cout << "password requires a number" << endl;
            fail = true;
        }
    }

    void lettercheck(string word)
    {
        int num = 0;
        for (int i = 0; i < word.length(); i++)
        {
            if (isdigit(word[i]) == false)
            {
                num = num + 1;
            }
        }
        if (num < 3)
        {
            cout << "password requires at least three letters" << endl;
            fail = true;
        }
    }

    void spaceCheck(string word)
    {
        bool isSpace = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == ' ')
            {
                isSpace = true;
                break;
            }
        }
        if (isSpace == true)
        {
            cout << "password cannot have any spaces" << endl;
            fail = true;
        }
    }

    void capitalizationCheck(string word)
    {
        bool caps = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (isupper(word[i]))
            {
                caps = true;
                break;
            }
        }
        if (!caps)
        {
            cout << "password requires at least one uppercase letter" << endl;
            fail = true;
        }
    }

    void commonPasswordCheck(string word)
    {
        ifstream file("common_passwords.txt");
        if (!file.is_open())
        {
            cerr << "Could not open the file." << endl;
            return;
        }

        string fileLine;
        bool match = false;

        while (getline(file, fileLine))
        {
            if (word == fileLine)
            {
                match = true;
                break;
            }
        }

        if (match)
        {
            cout << "weak password" << endl;
            fail = true;
        }
    }
    void allChecks(string word)
    {
        lengthrequirement(word);
        numbercheck(word);
        lettercheck(word);
        spaceCheck(word);
        capitalizationCheck(word);
        commonPasswordCheck(word);
    }
    bool failed(){
        return fail;
    }
};
