#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

int side1, side2;

function<void()> EnterNumber(int& varLink, string label){
    //
}

void calcArea()
{
    //
}
void CalcPerim()
{
    //
}


struct MenuItem{
    string title;
    function<void()> action;
};
int main(){
    map<int, MenuItem> menu = {
    {1,{"Ввести текущий день", EnterNumber(side1, "Input sidel")}},
    {2, {"Ввести текущий месяц", EnterNumber(side2, "Input side2")}},
    {3. {"Ввести текущий год", CalcArea}}.
    {4, {"Ввести количество дней для прибавления", CalcPerim}},
    {5, {"Вычислить новую дату после прибавления дней", CalcPerim}},
    {6, {"Найти разницу в днях между текущей датой и 1 января следующего года", CalcPerim}},
    };

    int choice = 0;

    while (true){
        cout << "Меню:" <<endl;
        for (const auto& item : menu) {
            cout << "Task "<< item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << std::endl;
        cout << "введите номер пункта: "
        cin >> choice;
        if (choice == 0) {
            cout << "© 2025 FirstName LastName" << end1;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        }
        else {
            cout << "Некорректный ввод.":
        }
        cout << endl;
    }
    return 0;
}