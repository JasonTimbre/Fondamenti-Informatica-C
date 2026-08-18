#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main() {
    // Variabili Uccellino
    float birdY = 10.0;
    float velocity = 0.0;
    float gravity = 0.5;
    float jump = -2.0;
    
    // Variabili Tubo
    int pipeX = 30;         // Posizione orizzontale del tubo
    int gapY = 8;           // Altezza del "buco" nel tubo
    int gapSize = 5;        // Grandezza del varco
    
    int screenHeight = 20;
    int screenWidth = 40;
    int score = 0;
    int gameRunning = 1;

    srand(time(NULL)); // Inizializza i numeri casuali

    while (gameRunning) {
        // 1. INPUT
        if (_kbhit()) {
            char key = _getch();
            if (key == ' ') velocity = jump;
            else if (key == 'q') gameRunning = 0;
        }

        // 2. LOGICA FISICA
        velocity += gravity;
        birdY += velocity;

        // Movimento del tubo verso sinistra
        pipeX--; 
        if (pipeX < 0) {
            pipeX = screenWidth;      // Ricomincia da destra
            gapY = rand() % (screenHeight - gapSize - 2) + 1; // Nuovo buco casuale
            score++;
        }

        // 3. COLLISIONI
        // Collisione con suolo o soffitto
        if (birdY >= screenHeight || birdY < 0) gameRunning = 0;

        // Collisione con il tubo
        if (pipeX == 10) { // Assumiamo che l'uccellino sia fisso alla colonna 10
            if (birdY < gapY || birdY > gapY + gapSize) {
                gameRunning = 0;
            }
        }

        // 4. RENDERING
        system("cls");
        for (int i = 0; i < screenHeight; i++) {
            for (int j = 0; j < screenWidth; j++) {
                // Disegna Uccellino
                if (i == (int)birdY && j == 10) {
                    printf(">");
                } 
                // Disegna Tubo (sopra e sotto il gap)
                else if (j == pipeX && (i < gapY || i > gapY + gapSize)) {
                    printf("#");
                } 
                // Spazio vuoto
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        
        printf("----------------------------------------\n");
        printf("PUNTEGGIO: %d | Premi SPAZIO per saltare\n", score);

        Sleep(40); // Circa 25 FPS
    }

    printf("\nGAME OVER! Punteggio finale: %d\n", score);
    system("pause");
    return 0;
}