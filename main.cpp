#include <iostream>
#include <string>
#include <vector>
#include "Source.h"
#include "message.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int n = 50;

    User user(n);
    Account account;

    while (true)
    {
        if (user.menu() == 1)
        {
            break;
        }
        account.current_name = user.current_name;
        account.menu1(user);
    }
    return 0;
}
