#include <iostream>

using namespace std;

bool CheckWinner(string arr[], char symbol)
{
    // Проверка строк
    for (int i = 0; i < 9; i += 3)
    {
        if (arr[i] == string(1, symbol) && arr[i + 1] == string(1, symbol) && arr[i + 2] == string(1, symbol))
        {
            return true;
        }
    }

    // Проверка столбцов
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i] == string(1, symbol) && arr[i + 3] == string(1, symbol) && arr[i + 6] == string(1, symbol))
        {
            return true;
        }
    }

    // Проверка диагоналей
    if (arr[0] == string(1, symbol) && arr[4] == string(1, symbol) && arr[8] == string(1, symbol))
    {
        return true;
    }
    if (arr[2] == string(1, symbol) && arr[4] == string(1, symbol) && arr[6] == string(1, symbol))
    {
        return true;
    }

    return false;
}

int main() 
{
	setlocale(LC_ALL, "ru");
	int PlayerName1, PlayerName2;
	string arr[9] = { "  " ,"  " ,"  " ,"  " , "  " ,"  " , "  " ,"  " , "  " };
	int arr1[9] = { 0,0,0,0,0,0,0,0,0, };
	cout << "\t1\t|\t2\t|\t3\t" << endl
		<< "------------------------------------------------" << endl
		<< "\t4\t|\t5\t|\t6\t" << endl
		<< "------------------------------------------------" << endl
		<< "\t7\t|\t8\t|\t9\t" << endl
		<< "------------------------------------------------" << endl;
	
    for (int i = 0; i < 9; ++i) {
        cout << "Введите номер клетки: ";
        cin >> PlayerName1;

        // Проверяем корректность введенного номера клетки
        if (PlayerName1 < 1 || PlayerName1 > 9) {
            cout << "Ошибка: введите число от 1 до 9." << endl;
            i--; // Чтобы повторить текущую итерацию цикла
            continue;
        }

        // Проверяем, не занята ли уже клетка
        if (arr[PlayerName1 - 1] != "  ") {
            cout << "Ошибка: ячейка уже занята!" << endl;
            i--; // Чтобы повторить текущую итерацию цикла
        }
        else {
            arr[PlayerName1 - 1] = "X";
            arr1[PlayerName1 - 1] = 1;
        }

        // Выводим текущее состояние игрового поля
        cout << "\t" << arr[0] << "\t|\t" << arr[1] << "\t|\t" << arr[2] << "\t" << endl
            << "------------------------------------------------" << endl
            << "\t" << arr[3] << "\t|\t" << arr[4] << "\t|\t" << arr[5] << "\t" << endl
            << "------------------------------------------------" << endl
            << "\t" << arr[6] << "\t|\t" << arr[7] << "\t|\t" << arr[8] << "\t" << endl;

        if (CheckWinner(arr, 'X')) {
            cout << "Игрок X выиграл!" << endl;
            break;
        }

        for (int i = 0; i < 9; ++i) {
            cout << "Введите номер клетки: ";
            cin >> PlayerName2;

            // Проверяем корректность введенного номера клетки
            if (PlayerName2 < 1 || PlayerName2 > 9) {
                cout << "Ошибка: введите число от 1 до 9." << endl;
                i--; // Чтобы повторить текущую итерацию цикла
                continue;
            }

            // Проверяем, не занята ли уже клетка
            if (arr[PlayerName2 - 1] != "  ") {
                cout << "Ошибка: ячейка уже занята!" << endl;
                i--; // Чтобы повторить текущую итерацию цикла
            }
            else {
                arr[PlayerName2 - 1] = "O";
                arr1[PlayerName2 - 1] = 1;
            }

            // Выводим текущее состояние игрового поля
            cout << "\t" << arr[0] << "\t|\t" << arr[1] << "\t|\t" << arr[2] << "\t" << endl
                << "------------------------------------------------" << endl
                << "\t" << arr[3] << "\t|\t" << arr[4] << "\t|\t" << arr[5] << "\t" << endl
                << "------------------------------------------------" << endl
                << "\t" << arr[6] << "\t|\t" << arr[7] << "\t|\t" << arr[8] << "\t" << endl;
            if (CheckWinner(arr, 'O')) {
                cout << "Игрок O выиграл!" << endl;
            }
                break;
            
        } 
    }
}
