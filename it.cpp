#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char *str) {
    if (strlen(str) < 2)
        return 0;

    int count = 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if ((str[i - 1] == 'n' && str[i] == 'o') || (str[i - 1] == 'o' && str[i] == 'n')) {
            count++;
        }
    }

    return count;
}

char *Change(char *str) {
    size_t len = strlen(str);

    if (len < 2)
        return str;

    char *tmp = new char[len * 3 / 2 + 1];
    char *t = tmp;
    tmp[0] = '\0';

    size_t i = 0;

    while (i < len && str[i + 1] != '\0') {
        if ((str[i] == 'n' && str[i + 1] == 'o')) {
            strcat(t, "***");
            t += 3;
            i += 2;
        } else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    *t++ = str[i++];
    *t = '\0';

    strcpy(str, tmp);
    return tmp;
}

int main() {
    char str[101];

    cout << "Введіть літерний рядок: " << endl;
    cin.getline(str, 100);

    int noOnCount = Count(str);
    char *dest = Change(str);

    cout << "Кількість груп, що містить 'no' або 'on': " << noOnCount << endl;
    cout << "Змінений рядок (param): " << str << endl;
    cout << "Змінений рядок (result): " << dest << endl;

    return 0;
}

