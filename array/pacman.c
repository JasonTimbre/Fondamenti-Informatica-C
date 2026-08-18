#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Gestione multipiattaforma per Input e Sleep
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
    #define CLEAR_SCREEN() system("cls")
#else
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)
    #define CLEAR_SCREEN() printf("\033[H\033[J")
    
    int _kbhit(void) {
        struct termios oldt, newt;
        int ch, oldf;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        if(ch != EOF) { ungetc(ch, stdin); return 1; }
        return 0;
    }
    int _getch(void) {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
#endif

// Codici Colore ANSI
#define ANSI_MURO     "\033[22;34m" 
#define ANSI_PACMAN   "\033[01;33m"
#define ANSI_FANTASMA "\033[01;31m"
#define ANSI_PUNTINI  "\033[01;36m"
#define ANSI_RESET    "\033[0m"

#define ALTEZZA 11
#define LARGHEZZA 21
#define NUM_FANTASMI 3

typedef struct {
    int x;
    int y;
} Entita;

// Mappa grafica bella (Unicode)
char mappa[ALTEZZA][LARGHEZZA] = {
    "#####################",
    "#··········#········#",
    "#·##·#####·#·#####·##",
    "#·##·#####·#·#####·##",
    "#···················#",
    "#·##·#·#########·#·##",
    "#····#·····#·····#··#",
    "####·#####·#·#####·##",
    "#·········· ········#",
    "#·########·#·######·#",
    "#####################"
};

Entita pacman = {1, 1};
Entita fantasmi[NUM_FANTASMI] = {
    {19, 1}, {1, 9}, {19, 9}
};

int punteggio = 0;
int pallini_rimasti = 0;

void inizializza_gioco() {
    srand(time(NULL));
    pallini_rimasti = 0;
    for (int i = 0; i < ALTEZZA; i++) {
        for (int j = 0; j < LARGHEZZA; j++) {
            if (mappa[i][j] == '·') pallini_rimasti++;
        }
    }
    printf("\033[?25l"); // nasconde cursore
}

void ripristina_terminale() {
    printf("\033[?25h" ANSI_RESET "\n");
}

void disegna() {
    CLEAR_SCREEN();
    
    printf(ANSI_PACMAN " --- PAC-MAN IN C --- \n" ANSI_RESET);
    
    for (int i = 0; i < ALTEZZA; i++) {
        for (int j = 0; j < LARGHEZZA; j++) {

            if (i == pacman.y && j == pacman.x) {
                printf(ANSI_PACMAN "C" ANSI_RESET);
                continue;
            }

            bool ce_fantasma = false;
            for(int f = 0; f < NUM_FANTASMI; f++) {
                if (i == fantasmi[f].y && j == fantasmi[f].x) {
                    printf(ANSI_FANTASMA "G" ANSI_RESET);
                    ce_fantasma = true;
                    break;
                }
            }
            if (ce_fantasma) continue;

            if (mappa[i][j] == '#') {
                printf(ANSI_MURO "█" ANSI_RESET);
            } else if (mappa[i][j] == '·') {
                printf(ANSI_PUNTINI "·" ANSI_RESET);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n" ANSI_PACMAN "Punteggio: %d" ANSI_RESET "  |  Pallini: %d\n", 
           punteggio, pallini_rimasti);
    printf("Controlli: [W A S D] | Premi X per uscire\n");
}

void muovi_pacman(char direzione) {
    int nx = pacman.x;
    int ny = pacman.y;

    if (direzione == 'w' || direzione == 'W') ny--;
    if (direzione == 's' || direzione == 'S') ny++;
    if (direzione == 'a' || direzione == 'A') nx--;
    if (direzione == 'd' || direzione == 'D') nx++;

    if (mappa[ny][nx] != '#') {
        pacman.x = nx;
        pacman.y = ny;

        if (mappa[ny][nx] == '·') {
            mappa[ny][nx] = ' ';
            punteggio += 10;
            pallini_rimasti--;
        }
    }
}

void muovi_fantasmi() {
    for (int f = 0; f < NUM_FANTASMI; f++) {
        int nx = fantasmi[f].x;
        int ny = fantasmi[f].y;

        if (rand() % 10 < 6) {
            if (nx < pacman.x) nx++;
            else if (nx > pacman.x) nx--;
            if (ny < pacman.y) ny++;
            else if (ny > pacman.y) ny--;
        } else {
            int dir = rand() % 4;
            if (dir == 0) ny--;
            if (dir == 1) ny++;
            if (dir == 2) nx--;
            if (dir == 3) nx++;
        }

        if (mappa[ny][nx] != '#') {
            fantasmi[f].x = nx;
            fantasmi[f].y = ny;
        }
    }
}

bool controlla_collisione() {
    for (int f = 0; f < NUM_FANTASMI; f++) {
        if (pacman.x == fantasmi[f].x && pacman.y == fantasmi[f].y)
            return true;
    }
    return false;
}

int main() {
    char tasto = 'd';
    inizializza_gioco();

    while (true) {

        if (_kbhit()) {
            char input = _getch();
            if (input == 'x' || input == 'X') break;
            if (input=='w'||input=='a'||input=='s'||input=='d'||
                input=='W'||input=='A'||input=='S'||input=='D')
                tasto = input;
        }

        muovi_pacman(tasto);

        if (controlla_collisione()) {
            disegna();
            printf("\n" ANSI_FANTASMA "GAME OVER! Un fantasma ti ha catturato!" ANSI_RESET "\n");
            break;
        }

        muovi_fantasmi();

        if (controlla_collisione()) {
            disegna();
            printf("\n" ANSI_FANTASMA "GAME OVER! Un fantasma ti ha catturato!" ANSI_RESET "\n");
            break;
        }

        disegna();

        if (pallini_rimasti == 0) {
            printf("\n" ANSI_PACMAN "VITTORIA! Hai ripulito la mappa!" ANSI_RESET "\n");
            break;
        }

        SLEEP_MS(200);
    }

    ripristina_terminale();
    return 0;
}
