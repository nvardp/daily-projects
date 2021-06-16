#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<string>
#include <numeric>
#include<map>

using std::cout;
using std::endl;

std::string password()
{
    std::string result;
    srand(time(NULL));
    int x = rand() % 10;
    result += std::to_string(x);   //number

    char ch3 = (rand() % ('!' - '\'') + '!'); //symbol
     result += ch3;

    for (int i = 0; i < x+1; i++) // letter
    {
        char ch = (rand() % ('z' - 'a') + 'a');
        result += ch;
        char ch4 = (rand() % ('Z' - 'A') + 'A');
        result += ch4;
    }
    char ch2 = (rand() % ('!' - '\'') + '!'); //symbol2
    result += ch2;

    int x2 = rand() % 100; //number
    result += std::to_string(x2);
    if (result.size() > 24)
        result.erase(result.begin() + 24, result.end());
    else if (result.size() < 8)
    {
        for (int i = 0; i < 9 - result.size(); i++) // letter
        {
            char ch = (rand() % ('z' - 'a') + 'a');
            result += ch;
            char ch4 = (rand() % ('Z' - 'A') + 'A');
            result += ch4;
        }
    }
    return result;

}


bool check_pass(const std::string& str)
{
    std::map<std::string, int> mp;
    int int_counter = 0;
    int upper_counter = 0;
    int low_counter = 0;
    int sym_counter = 0;
    mp.insert({ "int", int_counter });
    mp.insert({ "upper", upper_counter });
    mp.insert({ "low", low_counter });
    mp.insert({ "symbol", sym_counter });
    if (str.size() > 24 || str.size() < 8)
    {
        cout << "size is not valid\n";
        return false;
    }
    for (const auto& s : str)
    {
        if (s <= ('9' - '0' + '0') && s > '0')
            mp["int"] = ++int_counter;
        if (s <= ('Z' - 'A' + 'A') && s > 'A')
            mp["upper"] = ++upper_counter;
        if (s <= ('z' - 'a' + 'a') && s > 'a')
            mp["low"] = ++low_counter;
        if (s <= ('\'') && s > '!')
            mp["symbol"] = ++sym_counter;
       
        if (s == '(' || s == ')' || s == '*')
        {
            cout << "password contains either ) or ( or *\n";
            return false;
        }
    }
    cout << "password contains \n";
    for (auto it = mp.cbegin(); it != mp.cend(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    return true;
}
int main()
{
    std::string pass = password();
    cout << pass<<endl;
    check_pass(pass);
}

