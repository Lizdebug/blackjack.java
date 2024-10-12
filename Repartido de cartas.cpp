#include <iostream>
#include <random>
#include <string>

using namespace std;

int player = 0;
int dealer = 0;

string playermensaje = "Las cartas del jugador son: ";
string dealermensaje = "Las cartas del dealer son: ";
int cards[52];


void createDeck() {
    int cartValue = 2;
    int cartCount = 0;
    for (int figure = 1; figure <= 4; figure++) {
        for (int card = 1; card <= 13; card++) {
            switch (card) {
                case 10:
                case 11:
                case 12:
                    cartValue = 10;
                    break;
                case 13:
                    cartValue = 11;
                    break;
                default:
                    break;
            }
            cards[cartCount] = cartValue;
            cartCount++;
            cartValue++;
        }
        cartValue = 2;
    }
}


int drawCard() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 52); // Rango de cartas: 1-52
    int card = dist(gen);
    return cards[card];
}

// Función para iniciar el juego y repartir las cartas al jugador y dealer
void initGame() {
    player = drawCard() + drawCard(); // Dos cartas para el jugador
    dealer = drawCard() + drawCard(); // Dos cartas para el dealer

    // Mostrar las cartas y las puntuaciones iniciales
    cout << playermensaje << player << " puntos." << endl;
    cout << dealermensaje << dealer << " puntos." << endl;
}

// Función para validar el resultado del juego
void validateGame() {
    // Verificar si el jugador tiene 21 puntos
    if (player == 21) {
        cout << "Ganaste, tienes 21 puntos exactos!" << endl;
    }
    // Verificar si el jugador tiene más puntos que el dealer
    else if (player > dealer && player <= 21) {
        cout << "Ganaste, tienes más puntos que el dealer!" << endl;
    }
    // Verificar si es un empate
    else if (player == dealer) {
        cout << "Empate!" << endl;
    }
    // Si el dealer tiene más puntos o el jugador se pasó de 21
    else {
        cout << "Perdiste, el dealer tiene más puntos o te pasaste de 21!" << endl;
    }
}

int main() {
    createDeck();   // Crear el mazo
    initGame();     // Iniciar el juego y repartir las cartas
    validateGame(); // Validar quién ganó
    return 0;
}