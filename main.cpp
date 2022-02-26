#include <iostream>
#include <cmath>
using namespace std;
int ten(int y){
    cout << "шестнадатиричная: ";
    cout << std::hex << y << endl;
    cout << "восьмеричная: ";
    cout << std::oct << y << endl;
    std::string buffer; // символы ответа в обратном порядке
        // выделим память заранее по максимуму
        buffer.reserve(std::numeric_limits<unsigned int>::digits);
        do
        {
            buffer += char('0' + y % 2); // добавляем в конец
            y = y / 2;
        } while (y > 0);
        cout << "двоичная: " << std::string(buffer.crbegin(), buffer.crend()) << endl;
    return 0;
}

int two(int y){
    cout << "десятичная: ";
    int t = 0;
    int o = y;
    int w = 10;
    int h = 0;
    while (o != 0) {
        t++;
        o=o/10;
    }
    t--;
    o = y;
    int r = pow(10,t);
    for (int e = t; e>=0; e--) {
        o = o/r;
        if (o>=10){
        o = o%w;
        }
        o = o*pow(2, e);
        h += o;
        r /= 10;
        o = y;
    }
    cout << h << endl;
    cout << "шестнадатиричная: ";
    cout << std::hex << h << endl;
    cout << "восьмеричная: ";
    cout << std::oct << h << endl;

    return 0;
}

int eight(int y){
    cout << "десятичная: ";
    int t = 0;
    int o = y;
    int w = 10;
    int h = 0;
    while (o != 0) {
        t++;
        o=o/10;
    }
    o = y;
    int r = pow(10,t)/10;
    for (int e = t-1; e>=0; e--) {
        o = o/r;
        if (o>10){
        o = o%w;
        }
        o = o*pow(8, e);
        h += o;
        r /= 10;
        o = y;
    }
    cout << h << endl;
    cout << "шестнадатиричная: ";
    cout << std::hex << h << endl;
    std::string buffer; // символы ответа в обратном порядке
        // выделим память заранее по максимуму
        buffer.reserve(std::numeric_limits<unsigned int>::digits);
        do
        {
            buffer += char('0' + h % 2); // добавляем в конец
            h = h / 2;
        } while (h > 0);
        cout << "двоичная: " << std::string(buffer.crbegin(), buffer.crend()) << endl;
    return 0;
}

int sixteen(string y){
    cout << "десятичная: ";
    int h = 0;
    int e = 0;
    char p;
    int o = y.length()-1;
    for (int i = o, u = 0; i>=0; i--, u++){
        p = y[u];
        switch (p) {
            case 'A':
                e = 10;
                break;
            case 'B':
                e = 11;
                break;
            case 'C':
                e = 12;
                break;
            case 'D':
                e = 13;
                break;
            case 'E':
                e = 14;
                break;
            case 'F':
                e = 15;
                break;
            default:
                e = p;
                e -=48;
                break;
        }
        e = e*pow(16, i);
        h += e;
    }
    cout << h << endl;
    cout << "восьмеричная: ";
    cout << std::oct << h << endl;
    std::string buffer; // символы ответа в обратном порядке
        // выделим память заранее по максимуму
        buffer.reserve(std::numeric_limits<unsigned int>::digits);
        do
        {
            buffer += char('0' + h % 2); // добавляем в конец
            h = h / 2;
        } while (h > 0);
        cout << "двоичная: " << std::string(buffer.crbegin(), buffer.crend()) << endl;
    return 0;
}

int main(){
    int a;
    cout << "В какой системе вводите число?: ";
    cin >> a;
    switch (a) {
        default:
            cout << "Неправильна система\n";
            break;
        case 2:
            int u;
            cout << "Введите число: ";
            cin >> u;
            two(u);
            break;
        case 8:
            int t;
            cout << "Введите число: ";
            cin >> t;
            eight(t);
            break;
        case 10:
            int i;
            cout << "Введите число: ";
            cin >> i;
            ten(i);
            break;
        case 16:
            string o;
            cout << "Введите число: ";
            cin >> o;
            sixteen(o);
            break;
    }
}
