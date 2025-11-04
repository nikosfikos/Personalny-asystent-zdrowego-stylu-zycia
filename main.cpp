#include <iostream>
#include <string>

int main() {
    int weight, height, age, target, balance{0}, activity_level;
    float activity_factor{0};
    char sex;
    do {
        std::cout<<"Enter weight between 30-250kg"<<std::endl;
        if (!(std::cin>>weight)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr<< "Error: invalid input." << std::endl;

            continue;
        }
        if (weight < 30 || weight > 250) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr << "Error: weight must be in range of 30-250kg." << std::endl;
            continue;
        }
        break;
    } while (true);

    do {
        std::cout<<"Enter height between 100-250cm"<<std::endl;
        if (!(std::cin>>height)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr<< "Error: invalid input." << std::endl;
            continue;
        }
        if (height < 30 || height > 250) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr << "Error: height must be in range of 100-250cm." << std::endl;
            continue;
        }
        break;
    }while (true);

    do {
        std::cout<<"Enter age between 15-100 years"<<std::endl;
        if (!(std::cin>>age)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr<< "Error: invalid input." << std::endl;

            continue;
        }
        if (age < 15  || age > 100) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr << "Error: age must be in range of 15-100 years." << std::endl;

            continue;
        }
        break;
    }while (true);

    do{
        std::cout<<"Enter sex M (male), K (female)"<<std::endl;
        if (!(std::cin>>sex)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr<< "Error: invalid input." << std::endl;

            continue;
        }
        if (sex != 'M' && sex != 'K') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr << "Error: number must be character M or K." << std::endl;

            continue;
        }
        break;
    }while (true);
    double height_in_m = static_cast<double>(height) / 100.0;
    std::cout << weight<<std::endl;
    std::cout << height<<std::endl;
    std::cout << age<<std::endl;
    std::cout << sex<<std::endl;

    std::cout << "=== WYBIERZ CEL ===" << std::endl;
    std::cout <<"1. Redukcja wagi (deficyt -500 kcal/dzień)"<<std::endl;
    std::cout <<"2. Utrzymanie wagi (bilans energetyczny)"<<std::endl;
    std::cout <<"3. Przyrost masy (nadwyżka +300 kcal/dzień)"<<std::endl;

    do {
        if (!(std::cin>>target)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr<<"Error: invalid input."<<std::endl;

            continue;
        }
        if (target != 1 && target != 2 && target != 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr<<"Error: Number must be in range from 1-3"<<std::endl;

            continue;
        }
        break;
    } while (true);

    std::cout << "=== POZIOM AKTYWNOŚCI ===" << std::endl;
    std::cout <<"1. Siedzący (praca biurowa, brak ćwiczeń)"<<std::endl;
    std::cout <<"2. Lekko aktywny (1-2 treningi/tydzień)"<<std::endl;
    std::cout <<"3. Umiarkowanie aktywny (3-4 treningi/tydzień)"<<std::endl;
    std::cout <<"4. Bardzo aktywny (5-6 treningów/tydzień)"<<std::endl;

    do {
        if (!(std::cin>>activity_level)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;

        }
        if (activity_level != 1 && activity_level != 2 && activity_level != 3 && activity_level != 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }
        break;
    } while (true);

    switch (target) {
        case 1:
            balance -= 500;
            break;
        case 2:
            balance = 0;
            break;
        case 3:
            balance += 300;
            break;
    }


    switch (activity_level) {
        case 1:
            activity_factor = 1.2;
            break;
        case 2:
            activity_factor = 1.4;
            break;
        case 3:
            activity_factor = 1.6;
            break;
        case 4:
            activity_factor = 1.8;
            break;
    }

    std::cout << target<<std::endl;
    std::cout << activity_level<<std::endl;
    std::cout << balance<<std::endl;
    std::cout << activity_factor<<std::endl;

    // 2.1 Body Mass Index calculator
    double bmi = weight / pow(height_in_m,2);
    std::string bmi_string{""};
    if (bmi >= 30.0) {
        bmi_string = "otyłość";
    }
    else if (bmi < 18.5) {
        bmi_string = "niedowaga";
    }
    else if (bmi >= 18.5 && bmi <= 24.9) {
        bmi_string = "prawidłowa waga";
    }
    else {
        bmi_string = "nadwaga";
    }

    // 2.2 Basal Metabolic Rate
    double bmr{0.0};
    if (sex != 'K') {
        bmr += (66.5 + (13.75 * weight) + (5.003 * height) - (6.75 * age));
    }
    else {
        bmr += (655.1 + (9.563 * weight) + (1.850 * height) - (4.676 * age));
    }
    // 2.3 Total Daily Energy Expenditure
    double tdee = bmr * activity_factor;

    // 2.4 Daily calorie goal
    double goal = tdee + static_cast<double>(balance);

    // 2.5 Perfect weight range
    double perfect_weight = 22.0 * pow(height_in_m, 2);

    std::cout <<"bmi " << bmi<<std::endl;
    std::cout <<"bmr "<< bmr<<std::endl;
    std::cout <<"tdee " << tdee<<std::endl;
    std::cout<<"goal "<< goal<<std::endl;
    std::cout <<"perfect_weight "<< perfect_weight<<std::endl;




}