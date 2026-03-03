#include <iostream>
#include <string>

//Основная функция
int main() {
    std::string name; //переменная для имени пользователя
    std::cout << "Введите свое имя: "; //выводим запрос
    std::cin >> name; //вводим имя
    std::cout << "Hello world from " << name << std:: endl; //выводим приветствие
    return 0;
}
