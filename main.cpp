#include <iostream>
#include <string>

using namespace std;


double php_to_usd(double amount)
{
    return (amount + 0.0) / 50;
}


double usd_to_php(double amount)
{
    return (amount + 0.0) * 50;
}


bool is_in_string(char character, string characters)
{
    return !(characters.find(character) == string::npos);
}


bool is_valid_digit(string digit)
{
    string valid_digits = "0123456789";

    for (int i = 0; i < digit.length(); i++) 
    {
        if (!is_in_string(digit[i], valid_digits))
        {
            return false;
        }
    }
    return true;
}


int main()
{
    cout << "Welcome to Currency Converter Program!" << "\n\n";

    while (true) 
    {
        cout << "Select what currency you want to convert. ";
        cout << "Make sure to enter the letter only." << endl;
        cout << "a. PHP to USD" << endl;
        cout << "b. USD to PHP" << endl;
        
        string choices[4] = {"a", "b", "A", "B"};
        string task;
        bool is_chosen_task_valid = false;

        cout << "Answer: ";
        cin >> task;

        for (int i = 0; i < 4; i++)
        {
            if (task == choices[i])
            {
                is_chosen_task_valid = true;
                break;
            }
        }

        if (!is_chosen_task_valid)
        {
            cout << "Invalid choice, got \"" << task << "\".\n\n";
            continue;
        }

        cout << "\n";

        while (true) {

            string amount;

            if (task == "a" || task == "A")
            {
                cout << "PHP to USD" << endl;
                cout << "PHP Amount: ";
                cin >> amount;

                if (!is_valid_digit(amount))
                {
                    cout << amount << " is not a valid number." << endl;
                    continue;
                }

                cout << amount << " PHP = " << php_to_usd(stod(amount)) << " USD\n";
            }
            else
            {
                cout << "USD to PHP" << endl;
                cout << "USD Amount: ";
                cin >> amount;

                if (!is_valid_digit(amount))
                {
                    cout << amount << " is not a valid number." << endl;
                    continue;
                }

                cout << amount << " USD = " << usd_to_php(stod(amount)) << " PHP\n";
            }

            cout << "\n";
            break;
        }
    }

    return 0;
}