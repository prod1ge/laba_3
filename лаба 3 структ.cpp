#include <iostream>
#include <vector>

using namespace std;

// Функция для переворота каждой S-й монеты
void flipCoins(vector<int>& coins, int S) {
    int n = coins.size();
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % S == 0) {
            coins[i] = 1 - coins[i]; // Переворот монеты
        }
    }
}

// Функция для подсчета количества гербов вверх
int countHeads(const vector<int>& coins) {
    int count = 0;
    for (int coin : coins) {
        if (coin == 1) {
            ++count;
        }
    }
    return count;
}

int main() {
    int N, M, S, K, L;

    cout << "Smusev Vladislav Andreevich" << endl;

    // Ввод данных
    cout << "Enter the number of coins with coats of arms facing up (N): ";//Введите количество монет гербами вверх (N)
    cin >> N;
    cout << "Enter the number of coins with coats of arms down (M): ";//Введите количество монет гербами вниз (M)
    cin >> M;
    cout << "Enter flip interval (S): ";//Введите интервал переворота (S)
    cin >> S;
    cout << "Enter the number of moves (K): ";//Введите количество ходов (K)
    cin >> K;
    cout << "Enter the required number of coins with coats of arms facing up (L): ";//Введите необходимое количество монет гербами вверх (L)
    cin >> L;

    int totalCoins = N + M;
    vector<int> coins(totalCoins, 0);

    // Начальная расстановка монет
    for (int i = 0; i < N; ++i) {
        coins[i] = 1; // Гербами вверх
    }

    // Выполнение K ходов переворота
    for (int i = 0; i < K; ++i) {
        flipCoins(coins, S);
    }

    // Подсчет гербов вверх после K ходов
    int headsCount = countHeads(coins);

    if (headsCount == L) {
        cout << "Coins after " << K << " have moves " << L << " coats of arms up." << endl;
    }
    else {
        cout << "failed to reach " << L << " coats of arms up after. " << K << " moves" << endl;
        cout << "number of coats of arms up: " << headsCount << endl;
    }

    return 0;
}
