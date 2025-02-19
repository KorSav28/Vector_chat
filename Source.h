#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class UserData // для хранения данных о пользователе
{
public:
    string login;
    string password;
    string name;
    UserData() { login = ""; password = ""; name = ""; }
    UserData(string login, string password, string name)
    {
        this->login = login;
        this->password = password;
        this->name = name;
    }
};

class User
{
public:
    std::vector<UserData> user_array;   
    int user_count;
    int n;
    string current_name;

    User(int n) : user_count(0), n(n) // конструктор 
    {}

    ~User() // деструктор
    {}

    int menu() // для выбора операции: 1.Вход, 2.Регистрация, 3.Выход
    {
        int number;
        cout << "Добро пожаловать" << endl;
        cout << "Выберете номер операции: 1.Вход, 2.Регистрация, 3.Выход" << endl;
        while (true)
        {
            cin >> number; 
            if (cin.fail() || number < 1 || number > 3) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка! Введите число от 1 до 3: "; 
            }
            else
            {
                break;
            }
        }

        if (number == 1)
        {
            Entrance();
        }
        else if (number == 2)
        {
            Registration();
        }
        else if (number == 3)  
        {
            cout << "Выход из системы" << endl;
            return 1;
        }
        return 0;
    }

    void Registration() // для регистрации пользователя 
    {
        string login, password, name;
        bool success = true;
        bool success1 = true;

        while (success1)
        {
            cout << "Введите свой логин: ";
            cin >> login;
            cout << "Введите свой пароль: ";
            cin >> password;
            cout << "Введите свое имя: ";
            cin >> name;

            success = true;
            for (const auto& user : user_array) {
                if (login == user.login || name == user.name) {
                    success = false;
                    break;
                }
            }
            if (success && user_count < n)
            {
                user_array.push_back(UserData(login, password, name));
                user_count++;
                cout << "Вы успешно зарегистрировались!" <<endl;
                success1 = false;
            }
            else
            {
                cout << "Пользователь с таким именем или логином уже существует. Введите данные заново" <<endl;
            }
        }
        Entrance();
    }

    void Entrance() // для входа зарегистрированного пользователя
    {
        string login, password;
        bool success = true;
        int i = 0;

        while (success)
        {
            cout << "Введите свой логин: ";
            cin >> login;
            cout << "Введите свой пароль: ";
            cin >> password;
          
            for (const auto& user : user_array) {
                if (login == user.login && password == user.password) {
                    success = false;
                    cout << "Хорошего общения, " << user.name << "!" << endl;
                    current_name = user.name;
                    break;
                }
            }

            if (success)
            {
                cout << "Ошибка! Неверный логин или пароль" << endl;
            }
        }
    }
};

#endif // SOURCE_H
