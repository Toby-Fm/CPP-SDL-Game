#pragma once //stellt sicher, dass diese Header-Datei nur einmal eingefügt wird.
#include <iostream> // Inkludiert die Header-Datei für die Ein- und Ausgabe über die Konsole.
#include <SDL/SDL.h> // Inkludiert die Header-Dateien von SDL und SDL_image für die Spieleentwicklung
#include <SDL/SDL_image.h> 

enum class GameState {PLAY, EXIT};
// Definiert einen Aufzählungstyp (enum class) namens GameState mit den Werten PLAY und EXIT

class Game {
    public:
        Game();
        ~Game();

        void run();
        // Öffentliche Methoden für die Spielsteuerung.

    private:
        void init(const char* title, int x, int y, int w, int h, Uint32 flags);
        // Methode zur Initialisierung des Spiels.

        void gameloop();
        // Methode für die Spiel-Hauptschleife.

        void handleEvents();
        // Methode zur Behandlung von Ereignissen (Events) im Spiel.

        SDL_Window* _window;
        SDL_Renderer* _renderer;
        // Zeiger auf SDL-Fenster und -Renderer.

        int _screenWidth;
        int _screenHeigth;
        // Breite und Höhe des Bildschirms.

        GameState _gameState;
        // Aktueller Spielzustand.
};
