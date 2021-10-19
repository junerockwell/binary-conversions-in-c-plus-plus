#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;
const string END_APP = "x"; // End the App Process
const string DECIMAL_TO_BINARY_CHOICE = "b";
const string BINARY_TO_DECIMAL_CHOICE = "d";
const string RESTART_CHOICE = "r";

string concatenation(string _string) {
    string sample = "";
    
    for (int i = 0; i < _string.length(); i++) {
        stringstream ss(", ");
        sample += _string[i] + ss.str();
    }
    return sample;
}

void intToString(int number) {
    stringstream ss;
    int _string;
    ss<<number;
    ss>>_string;
    cout << "It's a string now: " << _string << endl;
}

int binaryToDecimal(string binary) {
    cout << "binaryToDecimal()" << endl;
    int binaryLength = binary.length();
    int index = binaryLength - 1;
    int position = 1;
    int result = 0;
    
    for (; index >= 0; index--) {
        if (binary[index] == '1') {
            result += position;
        }

        position *= 2;
    }
    cout << result << endl;
    return result;
}

std::vector<int> reverseRemainders(std::vector<int> remainders) {
    int remaindersSize = remainders.size();
    cout << "reminder size: " << remaindersSize << endl;
    int index = remaindersSize - 1;
    std::vector<int> reversed;
    for (; index > remaindersSize; index--) {
        cout << remainders.at(index) << endl;
        reversed.push_back(remainders.at(index));
    }
    // for (int i = 0; i < reversed.size(); i++) {
    //     cout << reversed.at(i) << endl;
    // }
    
    return reversed;
}

string concatenateReverseRemainder(std::vector<int> remainders) {
    int remaindersSize = remainders.size();
    int index = remaindersSize - 1;
    string remaindersAsString = "";
    std::stringstream ss;
    for (; index >= 0; index--) {        // cout << remainders.at(index) << endl;
        ss << remainders[index];
    }

    cout << ss.str();

    return remaindersAsString = ss.str();
}

string decimalToBinary(double decimal) {
    std::vector< int > remainders;
    double quotient = decimal;
    int modulus = 0;

    while (quotient > 0) {
        modulus = fmod(quotient, 2);
        quotient = floor(quotient / 2);
        remainders.push_back(modulus);
    }
    return concatenateReverseRemainder(remainders);
    // return remainders;
}

void printDecimal(string decimal) {
    cout << "Decimal: " << decimal << endl;
}

string decimalPrompt() {
    const string prompt = "Enter Decimal [r to restart]: ";
    double response;

    cout << prompt;
    cin >> response;

    string res = decimalToBinary(response);
    printDecimal(res);
    return res;
}

string binaryPrompt() {
    const string prompt = "Enter Binary [r to restart]: ";
    string response;

    cout << prompt;
    cin >> response;

    // Check if the response is between 0 to 9 then call binaryToDecimal()
    // Else if response is r, return r.
    // Else return for initialPrompt()
    binaryToDecimal(response);

    return response;
}

string initialPrompt() {
    const string prompt = "* Binary to Decimal [press d]\n* Decimal to Binary [press b]\n";
    string response;

    cout << prompt;
    cin >> response;

    return response;
}

int main() {
   string userEntry;
    
    do {
        userEntry = initialPrompt();
        if (userEntry == BINARY_TO_DECIMAL_CHOICE) {
            userEntry = binaryPrompt();
        } else if (userEntry == DECIMAL_TO_BINARY_CHOICE) {
            userEntry = decimalPrompt();
        } else if (userEntry == RESTART_CHOICE) {
            initialPrompt();
        }
    } while (userEntry != END_APP);
    
}
