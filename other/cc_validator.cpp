#include <string>
#include <set>
#include <iostream>

std::string credit_card_type(std::string creditcard) {
    for(char c : creditcard) {
        if(c < '0' || c > '9') {
            return "INVALID";
        }
    }
    if(creditcard.size() > 16 || creditcard.size() < 13) {
        return "INVALID";
    }
    if(creditcard[0] == '3' && (creditcard[1] == '4' || creditcard[1] == '7')) {
        return "AMEX";
    }
    if(creditcard[0] == '5' && std::set({'1', '2', '3', '4', '5'}).count(creditcard[1])) {
        return "MASTERCARD";
    }
    if(creditcard[0] == '4') {
        return "VISA";
    }
    return "INVALID";
}

int char_to_int(char& c) {
    return c - '0';
}

int get_sum_of_digits(int num) {
    int sum = 0;
    while(num != 0) {
        int last = num % 10;
        sum += last;
        num /= 10;
    }
    return sum;
}

bool is_valid(std::string& creditcard) {
    int first_sum = 0;
    int second_sum = 0;
    bool add_to_first = true;
    for(int i = creditcard.size()-1; i >= 0; i--) {
        if(add_to_first) {
            first_sum += char_to_int(creditcard[i]);
        } else {
            second_sum += get_sum_of_digits(char_to_int(creditcard[i])*2);
        }
        add_to_first = !add_to_first;
    }
    return (first_sum + second_sum) % 10 == 0;
}

int main() {
    std::string creditcard;
    std::cout << "Enter your creditcard number: ";
    std::cin >> creditcard;
    std::string type = credit_card_type(creditcard);
    if(!is_valid(creditcard)) {
        type = "INVALID";
    }
    std::cout << type;
    return 0;
}