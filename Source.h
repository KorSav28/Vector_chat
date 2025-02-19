#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class UserData // ��� �������� ������ � ������������
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

    User(int n) : user_count(0), n(n) // ����������� 
    {}

    ~User() // ����������
    {}

    int menu() // ��� ������ ��������: 1.����, 2.�����������, 3.�����
    {
        int number;
        cout << "����� ����������" << endl;
        cout << "�������� ����� ��������: 1.����, 2.�����������, 3.�����" << endl;
        while (true)
        {
            cin >> number; 
            if (cin.fail() || number < 1 || number > 3) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������! ������� ����� �� 1 �� 3: "; 
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
            cout << "����� �� �������" << endl;
            return 1;
        }
        return 0;
    }

    void Registration() // ��� ����������� ������������ 
    {
        string login, password, name;
        bool success = true;
        bool success1 = true;

        while (success1)
        {
            cout << "������� ���� �����: ";
            cin >> login;
            cout << "������� ���� ������: ";
            cin >> password;
            cout << "������� ���� ���: ";
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
                cout << "�� ������� ������������������!" <<endl;
                success1 = false;
            }
            else
            {
                cout << "������������ � ����� ������ ��� ������� ��� ����������. ������� ������ ������" <<endl;
            }
        }
        Entrance();
    }

    void Entrance() // ��� ����� ������������������� ������������
    {
        string login, password;
        bool success = true;
        int i = 0;

        while (success)
        {
            cout << "������� ���� �����: ";
            cin >> login;
            cout << "������� ���� ������: ";
            cin >> password;
          
            for (const auto& user : user_array) {
                if (login == user.login && password == user.password) {
                    success = false;
                    cout << "�������� �������, " << user.name << "!" << endl;
                    current_name = user.name;
                    break;
                }
            }

            if (success)
            {
                cout << "������! �������� ����� ��� ������" << endl;
            }
        }
    }
};

#endif // SOURCE_H
