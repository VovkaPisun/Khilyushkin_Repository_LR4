#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;

//функция контроля вводимых данных
bool UserInput(string input) {
    //если строка пустая - ввод некорректен
    if (input.empty()) return false;
    for (char c : input){
        if (!std::isdigit(c)){
            return false;
        }
    }
    //попытаться
    try {
        //преобразование введенного значения в тип
        int number = stoi(input);
        if(number < 0){
            return false;
        }
    }
    catch (...) // если возникла ошибка в блоке try
    {
        return false;
    }

    return true;
}

string calculateNewDate(int currentDay,int currentMonth,int currentYear, int daysToAdd) {
    string Actual = "";
    while (daysToAdd > 0) {
        int daysInCurrentMonth = daysInMonth(currentMonth, currentYear);
        int daysRemainingInMonth = daysInCurrentMonth - currentDay + 1;

        if (daysToAdd >= daysRemainingInMonth) {
            daysToAdd -= daysRemainingInMonth;
            currentDay = 1;  // Переходим к первому дню следующего месяца
            currentMonth++;
            if (currentMonth > 12) {
                currentMonth = 1;
                currentYear++;
            }
        } else {
            currentDay += daysToAdd;
            daysToAdd = 0;
        }
    }
    Actual = to_string(currentDay)+' '+to_string(currentMonth)+' '+to_string(currentYear);
    return Actual;
}

int day(){
    cout << "Введите текущий день: ";
    int currentDay;
    cin >> currentDay;
    return currentDay;
}
int mounth(){
    cout << "Введите текущий месяц: ";
    int currentMonth;
    cin >> currentMonth;
    return currentMonth;
}
int year(){
    cout << "Введите текущий год: ";
    int currentYear;
    cin >> currentYear;
    return currentYear;
}
int add_day(){
    cout << "Введите количество дней для прибавления: ";
    int daysToAdd;
    cin >> daysToAdd;
    return daysToAdd;
}


int main() {
    int choice;
            int currentDay = 0;
            // day();
    //             cout << "Введите текущий день: ";
    // int currentDay;
    cin >> currentDay;
        int currentMonth=0;
        int currentYear=0;
        int daysToAdd=0;
        // mounth();
    do {
        // Вывод меню
        cout << "\n--- Меню ---" << endl;
        cout << "1. Введите текущий день" << endl;
        cout << "2. Введите текущий месяц" << endl;
        cout << "3. Введите текущий год" << endl;
        cout << "4. Введите количество дней для прибавления" << endl;
        cout << "5. Вычислить новую дату после прибавления дней" << endl;
        cout << "6. Найти разницу в днях между текущей датой и 1 января следующего года" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;

        // Обработка выбора пользователя
        switch (choice) {
            case 1:
                currentDay=day();
                break;
            case 2:
                currentMonth=mounth();
                break;
            case 3:
                currentYear=year();
                break;
            case 4:
                daysToAdd=add_day();
                break;
            case 5:
                calculateNewDate(currentDay,currentMonth,currentYear, daysToAdd);
                break;
            case 6:
                calculateDaysToNextYear(currentDay,currentMonth,currentYear);
                break;
            case 0:
                return 0;
                break;
            default:
                cout << "Неверный ввод. Пожалуйста, выберите пункт меню от 1 до 6." << endl;
        }
    } while (choice != 0);

    return 0;
}

