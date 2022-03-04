#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Menu {
    string name;
    double price;
};
void Menu1() {
    cout << "MacDonald's" << endl;
    vector<Menu> parr = { {"Big Mac", 3.99},{"French Fries", 2.95},{"Hamburger", 1.79},{"Double Cheeseburger", 4.29},{"Cheeseburger", 2.29},{"Quarter Pounder with Cheese", 4.99},{"Filet-O-Fish", 3.33},{"McRib", 4.97} };
    for (const auto& arr : parr) {
        cout << setw(50) << left << arr.name << setw(2) << "$" << arr.price << endl;

    }
}
void Menu2() {
    cout << "Chipotle" << endl;
    vector<Menu> parr2 = { {"Veggie taco", 5.99},{"Veggie burrito", 7.99},{"Steak taco", 3.99},{"Steak burrito", 8.99},{"Chicken taco", 4.99},{"Chicken burrito", 6.99} };
    for (const auto& arr2 : parr2) {
        cout << setw(50) << left << arr2.name << setw(2) << "$" << arr2.price << endl;

    }
}
void Menu3() {
    cout << "Domino's Pizza" << endl;
    vector<Menu> parr3 = { {"Veggie pizza", 9.99},{"Pepperoni pizza", 8.99},{"All meat pizza", 12.99},{"Cheese pizza", 5.99},{"Mushroom and pepperoni pizza", 7.99} };
    for (const auto& arr3 : parr3) {
        cout << setw(50) << left << arr3.name << setw(2) << "$" << arr3.price << endl;

    }
}
void Menu4() {
    cout << "KFC" << endl;
    vector<Menu> parr4 = { {"Three piece original fried chicken", 6.99},{"Bucket of crispy fried chicken", 13.99},{"Mashed potatoes", 5.99},{"Cole slaw", 5.99} };
    for (const auto& arr4 : parr4) {
        cout << setw(50) << left << arr4.name << setw(2) << "$" << arr4.price << endl;

    }
}
void Menu5() {
    cout << "Subway" << endl;
    vector<Menu> parr5 = { {"Veggie sandwich", 2.99},{"Tuna sandwich", 6.99},{"Italian sandwich", 7.99},{"Turkey sandwich", 5.99} };
    for (const auto& arr5 : parr5) {
        cout << setw(50) << left << arr5.name << setw(2) << "$" << arr5.price << endl;

    }
}
void Menu6() {
    cout << "In-n-Out" << endl;
    vector<Menu> parr6 = { {"Hamburger", 2.99},{"Cheeseburger", 3.29},{"Milk shake", 2.99},{"French fries", 1.79},{"Medium coke", 2.35} };
    for (const auto& arr6 : parr6) {
        cout << setw(50) << left << arr6.name << setw(2) << "$" << arr6.price << endl;

    }
}
void Menu7() {
    cout << "Wendy's" << endl;
    vector<Menu> parr7 = { {"Hamburger", 3.99},{"Cheeseburger", 4.29},{"Small classic chocolate Frosty", 2.99},{"French fries", 1.79},{"Chicken wrap", 4.39} };
    for (const auto& arr7 : parr7) {
        cout << setw(50) << left << arr7.name << setw(2) << "$" << arr7.price << endl;

    }
}
void Menu8() {
    cout << "Jack in the Box" << endl;
    vector<Menu> parr8 = { {"Chicken club salad", 6.99},{"Southwest chicken salad", 7.29},{"Grilled chicken salad", 5.99},{"Side salad", 1.79} };
    for (const auto& arr8 : parr8) {
        cout << setw(50) << left << arr8.name << setw(2) << "$" << arr8.price << endl;

    }
}
void Menu9() {
    cout << "El Pollo Loco" << endl;
    vector<Menu> parr9 = { {"Monterrey pollo salad", 6.99},{"Steamed vegetables", 3.29},{"Chicken tortilla soup", 5.29} };
    for (const auto& arr9 : parr9) {
        cout << setw(50) << left << arr9.name << setw(2) << "$" << arr9.price << endl;

    }
}
void Menu10() {
    cout << "Papa John's Pizza" << endl;
    vector<Menu> parr10 = { {"Veggie pizza", 4.09},{"Pepperoni pizza ", 8.99},{"All meat pizza", 12.99},{"Cheese pizza", 5.99},{"Mushroom and pepperoni pizza", 14.99} };
    for (const auto& arr10 : parr10) {
        cout << setw(50) << left << arr10.name << setw(2) << "$" << arr10.price << endl;

    }
}
int main()
{
    Menu1();
    cout << endl;
    Menu2();
    cout << endl;
    Menu3();
    cout << endl;
    Menu4();
    cout << endl;
    Menu5();
    cout << endl;
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
