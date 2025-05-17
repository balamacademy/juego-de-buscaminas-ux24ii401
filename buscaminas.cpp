#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int MAX = 100; 
const int MINA = -1;

int tablero[MAX][MAX];         
bool descubierto[MAX][MAX];    
int filas, columnas;
int minas;

void generar_minas() {
    int colocadas = 0;
    while (colocadas < minas) {
        int f = rand() % filas;
        int c = rand() % columnas;
        if (tablero[f][c] != MINA) {
            tablero[f][c] = MINA;
            colocadas++;
        }
    }
}

int contar_minas_adyacentes(int f, int c) {
    int conteo = 0;
    for (int i = f - 1; i <= f + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i >= 0 && i < filas && j >= 0 && j < columnas) {
                if (tablero[i][j] == MINA)
                    conteo++;
            }
        }
    }
    return conteo;
}

void generar_tablero() {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            tablero[i][j] = 0;

    generar_minas();

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (tablero[i][j] != MINA)
                tablero[i][j] = contar_minas_adyacentes(i, j);
        }
    }

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            descubierto[i][j] = false;
}

void mostrar_tablero(bool mostrarTodo = false) {
    cout << "    ";
    for (int j = 0; j < columnas; j++)
        cout << setw(2) << j << " ";
    cout << endl;

    for (int i = 0; i < filas; i++) {
        cout << setw(2) << i << " | ";
        for (int j = 0; j < columnas; j++) {
            if (mostrarTodo || descubierto[i][j]) {
                if (tablero[i][j] == MINA)
                    cout << " M ";
                else
                    cout << " " << tablero[i][j] << " ";
            } else {
                cout << " - ";
            }
        }
        cout << endl;
    }
}

void destapar(int f, int c) {
    if (f < 0 || f >= filas || c < 0 || c >= columnas || descubierto[f][c])
        return;

    descubierto[f][c] = true;

    if (tablero[f][c] == 0) {
        for (int i = f - 1; i <= f + 1; i++) {
            for (int j = c - 1; j <= c + 1; j++) {
                if (!(i == f && j == c))
                    destapar(i, j);
            }
        }
    }
}

bool verificar_ganador() {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            if (tablero[i][j] != MINA && !descubierto[i][j])
                return false;
    return true;
}

int main() {
    srand(time(NULL));

    cout << "Ingrese las dimensiones del tablero (filas columnas): ";
    cin >> filas >> columnas;
    minas = columnas + 1;

    generar_tablero();

    cout << "\nTablero generado internamente:\n";
    mostrar_tablero(true);

    system("pause");
    system("cls");

    bool gameOver = false;

    while (!gameOver) {
        mostrar_tablero();

        int f, c;
        cout << "Ingrese fila y columna: ";
        cin >> f >> c;

        if (f < 0 || f >= filas || c < 0 || c >= columnas) {
            cout << "Coordenadas fuera de rango. Intenta de nuevo.\n";
            continue;
        }

        if (tablero[f][c] == MINA) {
            cout << "\n Pisaste una mina! GAME OVER.\n";
            mostrar_tablero(true);
            gameOver = true;
        } else {
            destapar(f, c);
            if (verificar_ganador()) {
                cout << "\n Felicidades! Has ganado.\n";
                mostrar_tablero(true);
                gameOver = true;
            }
        }
    }

    return 0;
}
