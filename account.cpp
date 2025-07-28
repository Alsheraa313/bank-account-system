#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include "passwords.h"
#include "IDs.h"

/*
To Add:
1) possible web implamentation via html/css
2) password and account encrytion via hashmaps before storage into maps

*/
using namespace std;

class account
{
private:
    int &mapBalance;
    string option;
    int depositNum = 0;
    int withdrawlNum = 0;

public:
    account(int &balanceRef) : mapBalance(balanceRef) {}

    void setOption(string option)
    {
        this->option = option;
    }

    void operations()
    {

        if (option == "balance")
        {

            cout << mapBalance << endl;
        }

        if (option == "deposit")
        {
            while (true)
            {
                string depositInput;
                cout << "Enter the amount you'd like to deposit: ";

                cin >> depositInput;
                bool isNum = true;

                for (int i = 0; i < depositInput.length(); i++)
                {

                    if (isdigit(depositInput[i]) == false)
                    {
                        isNum = false;
                        break;
                    }
                }
                if (isNum == false)
                {
                    cout << "Invalid option, please enter a number" << endl;
                    continue;
                }
                else
                {
                    depositNum = stoi(depositInput);
                    mapBalance += depositNum;

                    break;
                }
            }
        }

        if (option == "withdraw")
        {
            while (true)
            {
                string withdrawlInput;
                cout << "Enter the amount you'd like to withdraw: ";

                cin >> withdrawlInput;
                bool isNum = true;

                for (int i = 0; i < withdrawlInput.length(); i++)
                {

                    if (isdigit(withdrawlInput[i]) == false)
                    {
                        isNum = false;
                        break;
                    }
                }
                if (isNum == false)
                {
                    cout << "Invalid option, please enter a number" << endl;
                    continue;
                }
                else
                {

                    withdrawlNum = stoi(withdrawlInput);

                    if (withdrawlNum > mapBalance)
                    {

                        cout << "Invalid option, withdrawl amount exceedes balance." << endl;
                        continue;
                    }

                    else
                    {
                        mapBalance -= withdrawlNum;
                        break;
                    }
                }
            }
        }
        if (option == "log out")
        {
            cout << "Goodbye" << endl;
        }
    }
};

struct accData
{

    string accessName;
    string accessPass;
    int balance;
};

int main()
{
    unordered_map<int, accData> firstData;

    unordered_map<string, int> secondData;

    srand(time(0));

    newUser newAcc("");

    while (true)
    {

        string existingUser;
        int existigUserID;
        int accountID;
        string newAccount;
        string newPass;
        string password;
        string option;
        string input;
        bool valid = false;

        cout << "Enter your username or type c to create an account: ";
        cin >> existingUser;

        if (existingUser == "c")
        {
            cout << "Create a username: ";
            cin >> newAccount;

            newUser newAcc(newAccount);

            cout << newAcc.getID() << endl;

            while (!valid)
            {
                cout << "create a password: ";
                cin >> newPass;

                strength pass(newPass.length(), newPass);
                pass.allChecks(newPass);

                if (!pass.failed())
                {
                    valid = true;
                }
            }

            accountID = newAcc.getID();

            firstData[accountID] = {newAccount, newPass, 0};

            secondData[newAccount] = accountID;
        }
        else
        {
            if (!secondData[existingUser])
            {
                cout << "User not found" << endl;
                continue;
            }

            accountID = secondData[existingUser];

            while (true)
            {
                cout << "Enter your password: ";
                cin >> password;

                if (password != firstData[accountID].accessPass)
                {
                    cout << "Incorrect password, try again" << endl;
                }
                else
                {
                    break;
                }
            }
        }

        accData &acc1 = firstData[accountID];

        account acc(acc1.balance);

        option = "";

        while (option != "log out")
        {
            cout << "Check balance [1], Deposit[2], Withdraw[3], log out[4]" << endl;
            cin >> input;

            if (input == "1")
            {
                option = "balance";
            }
            else if (input == "2")
            {
                option = "deposit";
            }
            else if (input == "3")
            {
                option = "withdraw";
            }
            else if (input == "4")
            {
                option = "log out";
            }

            else
            {
                cout << "invalid input, please enter 1, 2, 3, or 4" << endl;
            }

            acc.setOption(option);
            acc.operations();
        }
    };
}