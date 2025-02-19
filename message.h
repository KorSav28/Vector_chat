#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include <vector> 
#include <limits> 
#include "Source.h"
using namespace std;

struct Message // для хранения данных о сообщениях, их отправителях и получателях 
{
    string sender;
    string getter;
    string message;
    Message() { sender = ""; getter = ""; message = ""; }
    Message(string sender, string getter, string message)
    {
        this->sender = sender;
        this->getter = getter;
        this->message = message;
    }
};

class Account
{
public:
    int mes_arr_size;
    std::vector<Message> message_array;
    string current_name;

    Account() // конструктор
    {}

    ~Account() // деструктор 
    {}

    int menu1(User& user) // метод для выбора действия 1.Написать личное сообщение; 2. Написать сообщение всем пользователям; 3.Выход
    {
        bool open = true;
        while (open)
        {
            int num;
            cout << "Выберете действие: 1.Написать личное сообщение; 2. Написать сообщение всем пользователям; 3.Выход: " << endl;
            while (true)
            { 
                cin >> num; 
                if (cin.fail() || num < 1 || num > 3) 
                {
                    cin.clear(); // очистка флага ошибки 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорирование оставшихся символов в буфере 
                    cout << "Ошибка! Введите число от 1 до 3: ";
                }
                else
                {
                    break;
                }
            }

            if (num == 1)
            {
                Person_message(user);
            }
            else if (num == 2)
            {
                All_message(user);
            }
            else if (num == 3)
            {
                current_name = " ";
                open = false;
            }
        }
        return 0;
    }

    void Person_message(User& user) // для ввода сообщения конкретному пользователю
    {
        cout << "Выберете номер аккаунта: " << endl;
        int m;
        string sender, getter, message;
        for (int i = 0; i < user.user_count; ++i)
        {
            cout << i + 1 << ". " << user.user_array[i].login << endl;
        }
        cin >> m;
        if (m > 0 && m <= user.user_count)
        {
            for (const auto & polzov : message_array)
            {
                if ((polzov.sender == current_name && polzov.getter == user.user_array[m - 1].name) || (polzov.sender == user.user_array[m - 1].name && polzov.getter == current_name))
                {
                    cout << polzov.sender << ": " << polzov.message << endl; 
                }
            }
            cout << "Ваше сообщение: ";
            cin.ignore();
            getline(cin, message);

            message_array.push_back (Message(current_name, user.user_array[m - 1].name, message));
        }
        else
        {
            cout << "Ошибка! Неверный номер аккаунта" << endl;
        }
    }

    void All_message(User& user) // для ввода сообщения всем пользователям
    {
        string message;
        string getter = "everyone";
        for (const auto& polzov : message_array)
        {
            if (polzov.getter == "everyone") 
            {
                cout << polzov.sender << ": " << polzov.message << endl; 
            }
        }
        cout << "Ваше сообщение: ";
        cin.ignore();
        getline(cin, message);

        message_array.push_back (Message(current_name, getter, message));
    }
};

#endif // MESSAGE_H﻿