#include <iostream>
#include <string>
using namespace std;


int main()
{
    int x = 0, o = 0;
    int kolumna = 0, wiersz = 0, liczbao = 0, liczbax = 0;
    int i, j, i2, j2, i3, j3, zbicie;
    char gra = 't';

    char plansza[9][9] = {
            '*','1','2','3','4','5','6','7','8',
            '1','o',' ','o',' ','o',' ','o',' ',
            '2',' ','o',' ',' ',' ','o',' ','o',
            '3','o',' ','o',' ','o',' ','o',' ',
            '4',' ',' ',' ',' ',' ',' ',' ',' ',
            '5',' ',' ',' ',' ',' ',' ',' ',' ',
            '6',' ','x',' ','X',' ','x',' ','x',
            '7','x',' ','x',' ','x',' ','x',' ',
            '8',' ','x',' ','x',' ','x',' ','x',
    };

    do {

        for (i = 0; i < 9; i++) {
            cout << endl << "___________________" << endl;
            cout << "|";
            for (j = 0; j < 9; j++)
            {
                cout << plansza[i][j] << "|";

            }
        }
        cout << endl << "___________________" << endl << endl;

        do {
            x1:
            liczbax = 0;
            for (int wiersz = 0; wiersz < 9; wiersz++) {
                if (plansza[wiersz][kolumna] == 'x' || plansza[wiersz][kolumna] == 'X') { goto x2; liczbax += 1; }

                for (int kolumna = 0; kolumna < 9; kolumna++) {
                    if (plansza[wiersz][kolumna] == 'x' || plansza[wiersz][kolumna] == 'X') { goto x2; liczbax += 1; }

                }

            }
            if (liczbax < 1) { goto konieco; }
            x2:
            zbicie = 0;
            cout << "Gracz x:" << endl << endl;
            x = 0;
            cout << "Podaj wiersz pionka:";
            cin >> i;
            cout << "Podaj kolumne pionka:";
            cin >> j;
            if (plansza[i][j] == 'o' || plansza[i][j] == ' ' || plansza[i][j] == 'O') {

                cout << "Nie ma takiego pionka" << endl;
                system("pause");
            }
            if (plansza[i][j] == 'x') {

                cout << "Podaj wiersz pola:";
                cin >> i2;
                if (i2 == i - 2 || i2 == i - 1) {
                    if (i2 == i - 2) {
                        cout << "Podaj kolumne pola:";
                        cin >> j2;
                        if (j2 == j - 2 || j2 == j + 2 && plansza[i - 1][j - 1] == 'o' || plansza[i - 1][j + 1] == 'o' || plansza[i - 1][j - 1] == 'O' || plansza[i - 1][j + 1] == 'O') {
                            if (plansza[i2][j2] != ' ') {
                                cout << "To pole jest zajęte" << endl << endl;;
                                system("pause");

                            }
                            else {



                                if (j2 == j - 2 && plansza[i2][j2] == ' ') {
                                    plansza[i - 1][j - 1] = ' ';
                                    plansza[i][j] = ' ';
                                    if (i2 == 1)plansza[i2][j2] = 'X';
                                    if (i2 != 1)plansza[i2][j2] = 'x';
                                    if (plansza[i2 - 1][j2 - 1] == 'o' && plansza[i2 - 2][j2 - 2] == ' ' || plansza[i2 - 1][j2 - 1] == 'O' && plansza[i2 - 2][j2 - 2] == ' ' ||
                                        plansza[i2 - 1][j2 + 1] == 'o' && plansza[i2 - 2][j2 + 2] == ' ' || plansza[i2 - 1][j2 + 1] == 'O' && plansza[i2 - 2][j2 + 2] == ' ') {
                                        i3 = i2;
                                        j3 = j2;
                                        goto x;
                                    }
                                    else {
                                        x += 1;
                                    }
                                }
                                else {
                                    if (plansza[i2][j2] == ' '&&j2 == j + 2) {
                                        plansza[i - 1][j + 1] = ' ';
                                        plansza[i][j] = ' ';
                                        if (i2 == 1)plansza[i2][j2] = 'X';
                                        if (i2 != 1)plansza[i2][j2] = 'x';
                                        if (plansza[i2 - 1][j2 - 1] == 'o' && plansza[i2 - 2][j2 - 2] == ' ' || plansza[i2 - 1][j2 - 1] == 'O' && plansza[i2 - 2][j2 - 2] == ' ' ||
                                            plansza[i2 - 1][j2 + 1] == 'o' && plansza[i2 - 2][j2 + 2] == ' ' || plansza[i2 - 1][j2 + 1] == 'O' && plansza[i2 - 2][j2 + 2] == ' ') {
                                            i3 = i2;
                                            j3 = j2;
                                            goto x;
                                        }
                                        else {
                                            x += 1;
                                        }
                                    }
                                }
                            }
                        }
                        else {
                            cout << "Niedozwolony ruch" << endl << endl;

                            system("pause");
                        }
                    }
                    else {
                        if (i2 == i - 1) {
                            cout << "Podaj kolumne pola:";
                            cin >> j2;
                            if (j2 == j - 1 || j2 == j + 1) {
                                if (plansza[i2][j2] != ' ') {
                                    cout << "To pole jest zajete" << endl << endl;;
                                    system("pause");

                                }
                                else if (plansza[i2][j2] == ' ') {
                                    plansza[i][j] = ' ';
                                    if (i2 == 1)plansza[i2][j2] = 'X';
                                    if (i2 != 1)plansza[i2][j2] = 'x';
                                    x += 1;
                                }
                            }
                            else {
                                cout << "Niedozwolony ruch" << endl << endl;

                                system("pause");
                            }
                        }
                        else {
                            cout << "Niedozwolony ruch" << endl << endl;

                            system("pause");
                        }
                    }
                }
            }
            else if (plansza[i][j] == 'X') {

                cout << "Podaj wiersz pola:";
                cin >> i2;
                if (i2 != i) {
                    cout << "Podaj kolumne pola:";
                    cin >> j2;
                    if (j2 - j == i2 - i || j2 - j == i - i2 || j - j2 == i2 - i || j - j2 == i - i2) {

                        if (plansza[i2][j2] == ' ') {
                            plansza[i2][j2] = 'X';
                            plansza[i][j] = ' ';
                            if (i2 > i&&j2 > j || i2 < i&&j2 > j || i2 > i&&j2 < j || i2 < i&&j2 < j) {
                                if (i2 > i&&j2 > j) {
                                    if (plansza[i2 - 1][j2 - 1] == 'o' || plansza[i2 - 1][j2 - 1] == 'O') {
                                        plansza[i2 - 1][j2 - 1] = ' ';
                                        zbicie += 1;
                                    }
                                }
                                if (i2 < i&&j2 > j) {
                                    if (plansza[i2 + 1][j2 - 1] == 'o' || plansza[i2 + 1][j2 - 1] == 'O') {
                                        plansza[i2 + 1][j2 - 1] = ' ';
                                        zbicie += 1;
                                    }
                                }
                                if (i2 > i&&j2 < j) {
                                    if (plansza[i2 - 1][j2 + 1] == 'o' || plansza[i2 - 1][j2 + 1] == 'O') {
                                        plansza[i2 - 1][j2 + 1] = ' ';
                                        zbicie += 1;
                                    }
                                }
                                if (i2 < i&&j2 < j) {
                                    if (plansza[i2 + 1][j2 + 1] == 'o' || plansza[i2 + 1][j2 + 1] == 'O') {
                                        plansza[i2 + 1][j2 + 1] = ' ';
                                        zbicie += 1;
                                    }
                                }
                                if (zbicie == 1) {
                                    if (plansza[i2 - 1][j2 - 1] == 'o' && plansza[i2 - 2][j2 - 2] == ' ' || plansza[i2 - 1][j2 - 1] == 'O' && plansza[i2 - 2][j2 - 2] == ' ' ||
                                        plansza[i2 - 1][j2 + 1] == 'o' && plansza[i2 - 2][j2 + 2] == ' ' || plansza[i2 - 1][j2 + 1] == 'O' && plansza[i2 - 2][j2 + 2] == ' ' ||
                                        plansza[i2 + 1][j2 - 1] == 'o' && plansza[i2 + 2][j2 - 2] == ' ' || plansza[i2 + 1][j2 - 1] == 'O' && plansza[i2 + 2][j2 - 2] == ' ' ||
                                        plansza[i2 + 1][j2 + 1] == 'o' && plansza[i2 + 2][j2 + 2] == ' ' || plansza[i2 + 1][j2 + 1] == 'O' && plansza[i2 + 2][j2 + 2] == ' ') {
                                        i3 = i2;
                                        j3 = j2;
                                        goto x;
                                    }
                                    else {
                                        x += 1;
                                    }
                                }
                                else {
                                    x += 1;
                                }
                            }
                        }
                        else {
                            cout << "Niedozwolony ruch" << endl << endl;
                            system("pause");
                        }
                    }
                    else {
                        cout << "Niedozwolony ruch" << endl << endl;
                        system("pause");
                    }
                }



            }
            else {
                cout << "Niedozwolony ruch" << endl << endl;
                system("pause");
            }

            system("cls");

            for (i = 0; i < 9; i++) {
                cout << endl << "___________________" << endl;
                cout << "|";
                for (j = 0; j < 9; j++)
                {
                    cout << plansza[i][j] << "|";

                }
            }
            cout << endl << "___________________" << endl << endl;
        } while (x != 1);
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        do {
            o1:
            liczbao = 0;
            for (int wiersz = 0; wiersz < 9; wiersz++) {
                if (plansza[wiersz][kolumna] == 'o' || plansza[wiersz][kolumna] == 'O') { goto o2;  liczbao += 1; }

                for (int kolumna = 0; kolumna < 9; kolumna++) {
                    if (plansza[wiersz][kolumna] == 'o' || plansza[wiersz][kolumna] == 'O') { goto o2; liczbao += 1; }

                }

            }
            if (liczbao < 1) { goto koniecx; }
            o2:
            zbicie = 0;
            cout << "Gracz o:" << endl << endl;
            o = 0;
            cout << "Podaj wiersz pionka:";
            cin >> i;
            cout << "Podaj kolumne pionka:";
            cin >> j;

            if (plansza[i][j] == 'x' || plansza[i][j] == 'X' || plansza[i][j] == ' ') {

                cout << "Nie ma takiego pionka" << endl;
                system("pause");
            }
            if (plansza[i][j] == 'o') {

                cout << "Podaj wiersz pola:";
                cin >> i2;
                if (i2 == i + 2 || i2 == i + 1) {
                    if (i2 == i + 2) {
                        cout << "Podaj kolumne pola:";
                        cin >> j2;
                        if (j2 == j - 2 || j2 == j + 2 && plansza[i + 1][j - 1] == 'x' || plansza[i + 1][j + 1] == 'x' ||
                            plansza[i + 1][j - 1] == 'X' || plansza[i + 1][j + 1] == 'X') {
                            if (plansza[i2][j2] != ' ') {
                                cout << "To pole jest zajete" << endl << endl;;
                                system("pause");

                            }
                            else {



                                if (j2 == j - 2 && plansza[i2][j2] == ' ') {
                                    plansza[i + 1][j - 1] = ' ';
                                    plansza[i][j] = ' ';
                                    if (i2 == 8)plansza[i2][j2] = 'O';
                                    if (i2 != 8)plansza[i2][j2] = 'o';
                                    if (plansza[i2 + 1][j2 - 1] == 'x' && plansza[i2 + 2][j2 - 2] == ' ' || plansza[i2 + 1][j2 - 1] == 'X' && plansza[i2 + 2][j2 - 2] == ' ' ||
                                        plansza[i2 + 1][j2 + 1] == 'x' && plansza[i2 + 2][j2 + 2] == ' ' || plansza[i2 + 1][j2 + 1] == 'X' && plansza[i2 + 2][j2 + 2] == ' ') {
                                        i3 = i2;
                                        j3 = j2;
                                        goto o;
                                    }
                                    else {
                                        o += 1;
                                    }
                                }


                                if (j2 == j + 2 && plansza[i2][j2] == ' ') {


                                    plansza[i + 1][j + 1] = ' ';
                                    plansza[i][j] = ' ';
                                    if (i2 == 8)plansza[i2][j2] = 'O';
                                    if (i2 != 8)plansza[i2][j2] = 'o';
                                    if (plansza[i2 + 1][j2 - 1] == 'x' && plansza[i2 + 2][j2 - 2] == ' ' || plansza[i2 + 1][j2 - 1] == 'X' && plansza[i2 + 2][j2 - 2] == ' ' ||
                                        plansza[i2 + 1][j2 + 1] == 'x' && plansza[i2 + 2][j2 + 2] == ' ' || plansza[i2 + 1][j2 + 1] == 'X' && plansza[i2 + 2][j2 + 2] == ' ') {
                                        i3 = i2;
                                        j3 = j2;
                                        goto o;
                                    }
                                    else {
                                        o += 1;
                                    }

                                }

                            }
                        }
                        else {
                            cout << "Niedozwolony ruch" << endl << endl;

                            system("pause");
                        }
                    }
                    else {
                        if (i2 == i + 1) {
                            cout << "Podaj kolumne pola:";
                            cin >> j2;
                            if (j2 == j - 1 || j2 == j + 1) {
                                if (plansza[i2][j2] != ' ') {
                                    cout << "To pole jest zajete" << endl << endl;;
                                    system("pause");

                                }
                                else if (plansza[i2][j2] == ' ') {
                                    plansza[i][j] = ' ';
                                    if (i2 == 8)plansza[i2][j2] = 'O';
                                    if (i2 != 8)plansza[i2][j2] = 'o';
                                    o += 1;
                                }
                            }
                            else {
                                cout << "Niedozwolony ruch" << endl << endl;

                                system("pause");
                            }
                        }
                        else {
                            cout << "Niedozwolony ruch" << endl << endl;

                            system("pause");
                        }
                    }
                }
            }
            else if (plansza[i][j] == 'O') {

                cout << "Podaj wiersz pola:";
                cin >> i2;
                if (i2 != i) {
                    cout << "Podaj kolumne pola:";
                    cin >> j2;
                    if (j2 - j == i2 - i || j2 - j == i - i2 || j - j2 == i2 - i || j - j2 == i - i2) {

                        if (plansza[i2][j2] == ' ') {
                            plansza[i2][j2] = 'O';
                            plansza[i][j] = ' ';
                            if (i2 > i&&j2 > j || i2 < i&&j2 > j || i2 > i&&j2 < j || i2 < i&&j2 < j) {
                                if (i2 > i&&j2 > j) {
                                    if (plansza[i2 - 1][j2 - 1] == 'x' || plansza[i2 - 1][j2 - 1] == 'X') {
                                        plansza[i2 - 1][j2 - 1] = ' ';
                                        zbicie += 1;
                                    }
                                }
                                if (i2 < i&&j2 > j) {
                                    if (plansza[i2 + 1][j2 - 1] == 'x' || plansza[i2 + 1][j2 - 1] == 'X') {
                                        plansza[i2 + 1][j2 - 1] = ' ';
                                        zbicie += 1;
                                    }
                                }
                                if (i2 > i&&j2 < j) {
                                    if (plansza[i2 - 1][j2 + 1] == 'x' || plansza[i2 - 1][j2 + 1] == 'X') {
                                        plansza[i2 - 1][j2 + 1] = ' ';
                                        zbicie += 1;
                                    }
                                }
                                if (i2 < i&&j2 < j) {
                                    if (plansza[i2 + 1][j2 + 1] == 'x' || plansza[i2 + 1][j2 + 1] == 'X') {
                                        plansza[i2 + 1][j2 + 1] = ' ';
                                        zbicie += 1;
                                    }
                                }
                                if (zbicie == 1) {
                                    if (plansza[i2 - 1][j2 - 1] == 'x' && plansza[i2 - 2][j2 - 2] == ' ' || plansza[i2 - 1][j2 - 1] == 'X' && plansza[i2 - 2][j2 - 2] == ' ' ||
                                        plansza[i2 - 1][j2 + 1] == 'x' && plansza[i2 - 2][j2 + 2] == ' ' || plansza[i2 - 1][j2 + 1] == 'X' && plansza[i2 - 2][j2 + 2] == ' ' ||
                                        plansza[i2 + 1][j2 - 1] == 'x' && plansza[i2 + 2][j2 - 2] == ' ' || plansza[i2 + 1][j2 - 1] == 'X' && plansza[i2 + 2][j2 - 2] == ' ' ||
                                        plansza[i2 + 1][j2 + 1] == 'x' && plansza[i2 + 2][j2 + 2] == ' ' || plansza[i2 + 1][j2 + 1] == 'X' && plansza[i2 + 2][j2 + 2] == ' ') {
                                        i3 = i2;
                                        j3 = j2;
                                        goto o;
                                    }
                                    else {
                                        o += 1;
                                    }
                                }
                                else o += 1;
                            }
                        }
                        else {
                            cout << "Niedozwolony ruch" << endl << endl;
                            system("pause");
                        }

                    }
                }
                else {
                    cout << "Niedozwolony ruch" << endl << endl;
                    system("pause");
                }
            }

            system("cls");

            for (i = 0; i < 9; i++) {
                cout << endl << "___________________" << endl;
                cout << "|";
                for (j = 0; j < 9; j++)
                {
                    cout << plansza[i][j] << "|";

                }
            }
            cout << endl << "___________________" << endl << endl;
        } while (o != 1);
        if (liczbax > 0) {
            cout << "Czy chcecie grac dalej?(t/n):";
            cin >> gra;
        }
        system("cls");


    } while (gra != 'n');
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    return 0;

    do {
        x:
        system("cls");

        for (i = 0; i < 9; i++) {
            cout << endl << "___________________" << endl;
            cout << "|";
            for (j = 0; j < 9; j++)
            {
                cout << plansza[i][j] << "|";

            }
        }
        cout << endl << "___________________" << endl << endl;
        cout << "Gracz x:" << endl << endl;
        zbicie = 0;
        x = 0;
        i = i3;
        j = j3;

        if (plansza[i][j] == 'x') {

            cout << "Podaj wiersz pola:";
            cin >> i2;
            if (i2 == i - 2 || i2 == i - 1) {
                if (i2 == i - 2) {
                    cout << "Podaj kolumne pola:";
                    cin >> j2;
                    if (j2 == j - 2 || j2 == j + 2 && plansza[i - 1][j - 1] == 'o' || plansza[i - 1][j + 1] == 'o' || plansza[i - 1][j - 1] == 'O' || plansza[i - 1][j + 1] == 'O') {
                        if (plansza[i2][j2] != ' ') {
                            cout << "To pole jest zajęte" << endl << endl;;
                            system("pause");

                        }
                        else {



                            if (j2 == j - 2 && plansza[i2][j2] == ' ') {
                                plansza[i - 1][j - 1] = ' ';
                                plansza[i][j] = ' ';
                                if (i2 == 1)plansza[i2][j2] = 'X';
                                if (i2 != 1)plansza[i2][j2] = 'x';
                                if (plansza[i2 - 1][j2 - 1] == 'o' && plansza[i2 - 2][j2 - 2] == ' ' || plansza[i2 - 1][j2 - 1] == 'O' && plansza[i2 - 2][j2 - 2] == ' ' ||
                                    plansza[i2 - 1][j2 + 1] == 'o' && plansza[i2 - 2][j2 + 2] == ' ' || plansza[i2 - 1][j2 + 1] == 'O' && plansza[i2 - 2][j2 + 2] == ' ') {
                                    i3 = i2;
                                    j3 = j2;
                                    goto x;
                                }
                                else {
                                    x += 1;
                                }
                            }
                            else {
                                if (plansza[i2][j2] == ' '&&j2 == j + 2) {
                                    plansza[i - 1][j + 1] = ' ';
                                    plansza[i][j] = ' ';
                                    if (i2 == 1)plansza[i2][j2] = 'X';
                                    if (i2 != 1)plansza[i2][j2] = 'x';
                                    if (plansza[i2 - 1][j2 - 1] == 'o' && plansza[i2 - 2][j2 - 2] == ' ' || plansza[i2 - 1][j2 - 1] == 'O' && plansza[i2 - 2][j2 - 2] == ' ' ||
                                        plansza[i2 - 1][j2 + 1] == 'o' && plansza[i2 - 2][j2 + 2] == ' ' || plansza[i2 - 1][j2 + 1] == 'O' && plansza[i2 - 2][j2 + 2] == ' ') {
                                        i3 = i2;
                                        j3 = j2;
                                        goto x;
                                    }
                                    else {
                                        x += 1;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        cout << "Niedozwolony ruch" << endl << endl;

                        system("pause");
                    }
                }
                else {
                    if (i2 == i - 1) {
                        cout << "Podaj kolumne pola:";
                        cin >> j2;
                        if (j2 == j - 1 || j2 == j + 1) {
                            if (plansza[i2][j2] != ' ') {
                                cout << "To pole jest zajęte" << endl << endl;;
                                system("pause");

                            }
                            else if (plansza[i2][j2] == ' ') {
                                plansza[i][j] = ' ';
                                if (i2 == 1)plansza[i2][j2] = 'X';
                                if (i2 != 1)plansza[i2][j2] = 'x';
                                x += 1;
                            }
                        }
                        else {
                            cout << "Niedozwolony ruch" << endl << endl;

                            system("pause");
                        }
                    }
                    else {
                        cout << "Niedozwolony ruch" << endl << endl;

                        system("pause");
                    }
                }
            }
        }
        else if (plansza[i][j] == 'X') {

            cout << "Podaj wiersz pola:";
            cin >> i2;
            if (i2 != 0) {
                cout << "Podaj kolumne pola:";
                cin >> j2;
                if (j2 - j == i2 - i || j2 - j == i - i2 || j - j2 == i2 - i || j - j2 == i - i2) {

                    if (plansza[i2][j2] == ' ') {
                        plansza[i2][j2] = 'X';
                        plansza[i][j] = ' ';
                        if (i2 > i&&j2 > j || i2 < i&&j2 > j || i2 > i&&j2 < j || i2 < i&&j2 < j) {
                            if (i2 > i&&j2 > j) {
                                if (plansza[i2 - 1][j2 - 1] == 'o' || plansza[i2 - 1][j2 - 1] == 'O') {
                                    plansza[i2 - 1][j2 - 1] = ' ';
                                    zbicie = 1;
                                }
                            }
                            if (i2 < i&&j2 > j) {
                                if (plansza[i2 + 1][j2 - 1] == 'o' || plansza[i2 + 1][j2 - 1] == 'O') {
                                    plansza[i2 + 1][j2 - 1] = ' ';
                                    zbicie += 1;
                                }
                            }
                            if (i2 > i&&j2 < j) {
                                if (plansza[i2 - 1][j2 + 1] == 'o' || plansza[i2 - 1][j2 + 1] == 'O') {
                                    plansza[i2 - 1][j2 + 1] = ' ';
                                    zbicie += 1;
                                }
                            }
                            if (i2 < i&&j2 < j) {
                                if (plansza[i2 + 1][j2 + 1] == 'o' || plansza[i2 + 1][j2 + 1] == 'O') {
                                    plansza[i2 + 1][j2 + 1] = ' ';
                                    zbicie += 1;
                                }
                            }
                            if (zbicie == 1) {
                                if (plansza[i2 - 1][j2 - 1] == 'o' && plansza[i2 - 2][j2 - 2] == ' ' || plansza[i2 - 1][j2 - 1] == 'O' && plansza[i2 - 2][j2 - 2] == ' ' ||
                                    plansza[i2 - 1][j2 + 1] == 'o' && plansza[i2 - 2][j2 + 2] == ' ' || plansza[i2 - 1][j2 + 1] == 'O' && plansza[i2 - 2][j2 + 2] == ' ' ||
                                    plansza[i2 + 1][j2 - 1] == 'o' && plansza[i2 + 2][j2 - 2] == ' ' || plansza[i2 + 1][j2 - 1] == 'O' && plansza[i2 + 2][j2 - 2] == ' ' ||
                                    plansza[i2 + 1][j2 + 1] == 'o' && plansza[i2 + 2][j2 + 2] == ' ' || plansza[i2 + 1][j2 + 1] == 'O' && plansza[i2 + 2][j2 + 2] == ' ') {
                                    i3 = i2;
                                    j3 = j2;
                                    goto x;
                                }
                                else {
                                    x += 1;
                                }
                            }
                            else x += 1;
                        }
                    }
                    else {
                        cout << "Niedozwolony ruch" << endl << endl;
                        system("pause");
                    }
                }
                else {
                    cout << "Niedozwolony ruch" << endl << endl;
                    system("pause");
                }
            }



        }
        else {
            cout << "Niedozwolony ruch" << endl << endl;
            system("pause");
        }

        system("cls");

        for (i = 0; i < 9; i++) {
            cout << endl << "___________________" << endl;
            cout << "|";
            for (j = 0; j < 9; j++)
            {
                cout << plansza[i][j] << "|";

            }
        }
        cout << endl << "___________________" << endl << endl;
    } while (x != 1);
    goto o1;
    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    do {
        o:
        system("cls");

        for (i = 0; i < 9; i++) {
            cout << endl << "___________________" << endl;
            cout << "|";
            for (j = 0; j < 9; j++)
            {
                cout << plansza[i][j] << "|";

            }
        }
        cout << endl << "___________________" << endl << endl;
        cout << "Gracz o:" << endl << endl;
        zbicie = 0;
        o = 0;
        i = i3;
        j = j3;


        if (plansza[i][j] == 'o') {

            cout << "Podaj wiersz pola:";
            cin >> i2;
            if (i2 == i + 2 || i2 == i + 1) {
                if (i2 == i + 2) {
                    cout << "Podaj kolumne pola:";
                    cin >> j2;
                    if (j2 == j - 2 || j2 == j + 2 && plansza[i + 1][j - 1] == 'x' || plansza[i + 1][j + 1] == 'x' ||
                        plansza[i + 1][j - 1] == 'X' || plansza[i + 1][j + 1] == 'X') {
                        if (plansza[i2][j2] != ' ') {
                            cout << "To pole jest zajete" << endl << endl;;
                            system("pause");

                        }
                        else {



                            if (j2 == j - 2 && plansza[i2][j2] == ' ') {
                                plansza[i + 1][j - 1] = ' ';
                                plansza[i][j] = ' ';
                                if (i2 == 8)plansza[i2][j2] = 'O';
                                if (i2 != 8)plansza[i2][j2] = 'o';
                                if (plansza[i2 + 1][j2 - 1] == 'x' && plansza[i2 + 2][j2 - 2] == ' ' || plansza[i2 + 1][j2 - 1] == 'X' && plansza[i2 + 2][j2 - 2] == ' ' ||
                                    plansza[i2 + 1][j2 + 1] == 'x' && plansza[i2 + 2][j2 + 2] == ' ' || plansza[i2 + 1][j2 + 1] == 'X' && plansza[i2 + 2][j2 + 2] == ' ') {
                                    i3 = i2;
                                    j3 = j2;
                                    goto o;
                                }
                                else {
                                    o += 1;
                                }
                            }


                            if (j2 == j + 2 && plansza[i2][j2] == ' ') {


                                plansza[i + 1][j + 1] = ' ';
                                plansza[i][j] = ' ';
                                if (i2 == 8)plansza[i2][j2] = 'O';
                                if (i2 != 8)plansza[i2][j2] = 'o';
                                if (plansza[i2 + 1][j2 - 1] == 'x' && plansza[i2 + 2][j2 - 2] == ' ' || plansza[i2 + 1][j2 - 1] == 'X' && plansza[i2 + 2][j2 - 2] == ' ' ||
                                    plansza[i2 + 1][j2 + 1] == 'x' && plansza[i2 + 2][j2 + 2] == ' ' || plansza[i2 + 1][j2 + 1] == 'X' && plansza[i2 + 2][j2 + 2] == ' ') {
                                    i3 = i2;
                                    j3 = j2;
                                    goto o;
                                }
                                else {
                                    o += 1;
                                }

                            }

                        }
                    }
                    else {
                        cout << "Niedozwolony ruch" << endl << endl;

                        system("pause");
                    }
                }
                else {
                    if (i2 == i + 1) {
                        cout << "Podaj kolumne pola:";
                        cin >> j2;
                        if (j2 == j - 1 || j2 == j + 1) {
                            if (plansza[i2][j2] != ' ') {
                                cout << "To pole jest zajęte" << endl << endl;;
                                system("pause");

                            }
                            else if (plansza[i2][j2] == ' ') {
                                plansza[i][j] = ' ';
                                if (i2 == 8)plansza[i2][j2] = 'O';
                                if (i2 != 8)plansza[i2][j2] = 'o';
                                o += 1;
                            }
                        }
                        else {
                            cout << "Niedozwolony ruch" << endl << endl;

                            system("pause");
                        }
                    }
                    else {
                        cout << "Niedozwolony ruch" << endl << endl;

                        system("pause");
                    }
                }
            }
        }
        else if (plansza[i][j] == 'O') {

            cout << "Podaj wiersz pola:";
            cin >> i2;
            if (i2 != 0) {
                cout << "Podaj kolumne pola:";
                cin >> j2;
                if (j2 - j == i2 - i || j2 - j == i - i2 || j - j2 == i2 - i || j - j2 == i - i2) {

                    if (plansza[i2][j2] == ' ') {
                        plansza[i2][j2] = 'O';
                        plansza[i][j] = ' ';
                        if (i2 > i&&j2 > j || i2 < i&&j2 > j || i2 > i&&j2 < j || i2 < i&&j2 < j) {
                            if (i2 > i&&j2 > j) {
                                if (plansza[i2 - 1][j2 - 1] == 'x' || plansza[i2 - 1][j2 - 1] == 'X') {
                                    plansza[i2 - 1][j2 - 1] = ' ';
                                    zbicie += 1;
                                }
                            }
                            if (i2 < i&&j2 > j) {
                                if (plansza[i2 + 1][j2 - 1] == 'x' || plansza[i2 + 1][j2 - 1] == 'X') {
                                    plansza[i2 + 1][j2 - 1] = ' ';
                                    zbicie += 1;
                                }
                            }
                            if (i2 > i&&j2 < j) {
                                if (plansza[i2 - 1][j2 + 1] == 'x' || plansza[i2 - 1][j2 + 1] == 'X') {
                                    plansza[i2 - 1][j2 + 1] = ' ';
                                    zbicie += 1;
                                }
                            }
                            if (i2 < i&&j2 < j) {
                                if (plansza[i2 + 1][j2 + 1] == 'x' || plansza[i2 + 1][j2 + 1] == 'X') {
                                    plansza[i2 + 1][j2 + 1] = ' ';
                                    zbicie += 1;
                                }
                            }
                            if (zbicie == 1) {
                                if (plansza[i2 - 1][j2 - 1] == 'x' && plansza[i2 - 2][j2 - 2] == ' ' || plansza[i2 - 1][j2 - 1] == 'X' && plansza[i2 - 2][j2 - 2] == ' ' ||
                                    plansza[i2 - 1][j2 + 1] == 'x' && plansza[i2 - 2][j2 + 2] == ' ' || plansza[i2 - 1][j2 + 1] == 'X' && plansza[i2 - 2][j2 + 2] == ' ' ||
                                    plansza[i2 + 1][j2 - 1] == 'x' && plansza[i2 + 2][j2 - 2] == ' ' || plansza[i2 + 1][j2 - 1] == 'X' && plansza[i2 + 2][j2 - 2] == ' ' ||
                                    plansza[i2 + 1][j2 + 1] == 'x' && plansza[i2 + 2][j2 + 2] == ' ' || plansza[i2 + 1][j2 + 1] == 'X' && plansza[i2 + 2][j2 + 2] == ' ') {
                                    i3 = i2;
                                    j3 = j2;
                                    goto o;
                                }
                                else {
                                    o += 1;
                                }
                            }
                            else o += 1;
                        }
                    }
                    else {
                        cout << "Niedozwolony ruch" << endl << endl;
                        system("pause");
                    }

                }
            }
            else {
                cout << "Niedozwolony ruch" << endl << endl;
                system("pause");
            }
        }

        system("cls");

        for (i = 0; i < 9; i++) {
            cout << endl << "___________________" << endl;
            cout << "|";
            for (j = 0; j < 9; j++)
            {
                cout << plansza[i][j] << "|";

            }
        }
        cout << endl << "___________________" << endl << endl;
    } while (o != 1);
    goto x1;
    koniecx:
    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                              Gracz X wygrywa!!!" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    system("pause");
    return 0;
    konieco:
    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                              Gracz O wygrywa!!!" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    system("pause");
    return 0;
}

