#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

std::string perevernyt(const std::string& slovopacana) {
    std::string perevernutoeSlovo = slovopacana;
    std::reverse(perevernutoeSlovo.begin(), perevernutoeSlovo.end());
    return perevernutoeSlovo;
}

std::string udalenieglasnoi(const std::string& slovopacana) {
    std::string itog  = slovopacana;
    std::string glasnii = "aeiouAEIOU";
    itog.erase(std::remove_if(itog .begin(), itog.end(), [&](char c) {
        return glasnii.find(c) != std::string::npos; }), itog.end());
    return itog;
}

std::string udaleniesoglasnix(const std::string& slovopacana) {
    std::string itog = slovopacana;
    std::string soglasnii = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    itog.erase(std::remove_if(itog.begin(), itog.end(), [&](char c) {
        return soglasnii.find(c) != std::string::npos; }), itog.end());
    return itog;
}

std::string shakers(const std::string& slovopacana) {
    std::string shkealovo = slovopacana;
    std::shuffle(shkealovo.begin(), shkealovo.end(), std::default_random_engine(std::time(0)));
    return shkealovo;
}

int main() {
    setlocale(LC_ALL, "Rus");
    std::string slovopacana;
    std::cout << "Введите слово: ";
    std::cin >> slovopacana;

    int usersvibor;

        std::cout << "\nМеню:\n";
        std::cout << "1. Начало сделать концом.\n";
        std::cout << "2. Вывести слово без гласных.\n";
        std::cout << "3. Вывести слово без согласных.\n";
        std::cout << "4. ТУда сюда слово повертеть .\n";
        std::cout << "Выберите действие: ";
        std::cin >> usersvibor;

        switch (usersvibor) {
        case 1:
            std::cout << "Слово задом наперед: " << perevernyt(slovopacana) << std::endl;
            break;
        case 2:
            std::cout << "Слово без гласных: " << udalenieglasnoi(slovopacana) << std::endl;
            break;
        case 3:
            std::cout << "Слово без согласных: " << udaleniesoglasnix(slovopacana) << std::endl;
            break;
        case 4:
            std::cout << "Рандомно раскиданное слово: " << shakers(slovopacana) << std::endl;
            break;
        }
    return 0;
}
