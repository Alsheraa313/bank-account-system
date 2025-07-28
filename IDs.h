#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class newUser
{

private:
    int id;
    string newUsername = "";

public:

    newUser(string newUsername = "") {
        this->newUsername = newUsername;
        id = (rand() % (9999999 - 1000000 + 1) ) + 1000000;
    }

    void setID(int id){
        this->id = id;
    } 
    
    int getID(){
    return id;
    }

    string getNewUsername(){
        return newUsername;
    }

    void setNewUser(string newUsername){
        this->newUsername = newUsername;
    }
  
};
