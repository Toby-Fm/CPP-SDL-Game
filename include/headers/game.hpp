#pragma once  // Verhindert, dass dieser Header mehrfach eingebunden wird.

#include <iostream>
#include <SDL/SDL.h>  // SDL-Bibliothek für die Spieleentwicklung.
#include <SDL/SDL_image.h>  // SDL-Image für das Laden von Bilddateien.

enum class GameState { PLAY, EXIT }; // Enum zur Darstellung des Spielzustands.

class Game {
    public:
        Game(const char* title, int x, int y, int w, int h, Uint32 flags);    // Konstruktor für die Game-Klasse.
        
        GameState gameState;    // Enum-Instanz für den aktuellen Spielzustand.
        SDL_Texture* loadTexture(const char* filePath);    // Funktion zum Laden einer Textur aus einer Bilddatei.

        void render(SDL_Texture* tex);    // Funktion zum Rendern einer Textur auf dem Bildschirm.
        void run();    // Funktion zum Starten des Spiel-Loops.

    private:
        void clear();    // Hilfsfunktion zum Löschen des Bildschirms.
        void display();    // Hilfsfunktion zum Anzeigen des gerenderten Bildes.
        void cleanUp();    // Hilfsfunktion zum Aufräumen und Freigeben von Ressourcen.
        
        SDL_Window* window;    // Zeiger auf das SDL-Fenster.
        SDL_Renderer* renderer;    // Zeiger auf den SDL-Renderer, der das Rendern von Texturen ermöglicht.
};
