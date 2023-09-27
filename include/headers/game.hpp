#pragma once //Stellt sicher, dass diese Header-Datei nur einmal eingefügt wird.
#include <iostream>

// Inkludiert die Header-Dateien von SDL und SDL_image für die Spieleentwicklung.
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

enum class GameState {PLAY, EXIT}; // Definiert einen Aufzählungstyp (enum class) namens GameState mit den Werten PLAY und EXIT,

class Game {
    public:
        Game(const char* title, int x, int y, int w, int h, Uint32 flags); // Konstruktor der Game-Klasse mit Parametern für die Fensterinitialisierung.
        ~Game();// Destruktor der Game-Klasse.

        void run(); // Öffentliche Methode für die Spielsteuerung.

    private:
        void gameloop(); //Methode für die Spiel-Hauptschleife.

        void handleEvents(); //Methode zur Behandlung von Ereignissen (Events) im Spiel.

        SDL_Window* _window;
        SDL_Renderer* _renderer; // Zeiger auf SDL-Fenster und -Renderer.

        GameState _gameState; // Aktueller Spielzustand.
};
