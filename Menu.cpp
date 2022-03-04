#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Menu {
    string name;
    double price;
};
void Menu6() {
    cout << "In-n-Out" << endl;
    vector<Menu> parr1 = { {"Hamburger", 2.99},{"Cheeseburger", 3.29},{"Milk shake", 2.99},{"French fries", 1.79},{"Medium coke", 2.35} };
    for (const auto& arr : parr1) {
        cout << setw(50) << left << arr.name << setw(2) << "$" << arr.price << endl;
            
    }
}
void Menu7() {
    cout << "Wendy's" << endl;
    vector<Menu> parr2 = { {"Hamburger", 3.99},{"Cheeseburger", 4.29},{"Small classic chocolate Frosty", 2.99},{"French fries", 1.79},{"Chicken wrap", 4.39} };
    for (const auto& arr2 : parr2) {
        cout << setw(50) << left << arr2.name << setw(2) << "$" << arr2.price << endl;

    }
}
void Menu8() {
    cout << "Jack in the Box" << endl;
    vector<Menu> parr3 = { {"Chicken club salad", 6.99},{"Southwest chicken salad", 7.29},{"Grilled chicken salad", 5.99},{"Side salad", 1.79} };
    for (const auto& arr3 : parr3) {
        cout << setw(50) << left << arr3.name << setw(2) << "$" << arr3.price << endl;

    }
}
void Menu9() {
    cout << "El Pollo Loco" << endl;
    vector<Menu> parr4 = { {"Monterrey pollo salad", 6.99},{"Steamed vegetables", 3.29},{"Chicken tortilla soup", 5.29} };
    for (const auto& arr4 : parr4) {
        cout << setw(50) << left << arr4.name << setw(2) << "$" << arr4.price << endl;

    }
}
void Menu10() {
    cout << "Papa John’s Pizza" << endl;
    vector<Menu> parr5 = { {"Veggie pizza", 4.09},{"Pepperoni pizza ", 8.99},{"All meat pizza", 12.99},{"Cheese pizza", 5.99},{"Mushroom and pepperoni pizza", 14.99} };
    for (const auto& arr5 : parr5) {
        cout << setw(50) << left << arr5.name << setw(2) << "$" << arr5.price << endl;

    }
}
int main()
{
    Menu6();
    cout << endl;
    Menu7(); 
    cout << endl;
    Menu8();
    cout << endl;
    Menu9();
    cout << endl;
    Menu10();
    
    system("pause");
    return 0;

}
