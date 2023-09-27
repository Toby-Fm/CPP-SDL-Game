#include <headers/game.hpp> // Inkludiert die Header-Datei "game.hpp", die die Deklaration der Game-Klasse enthält.

int main(int argc, char* argv[]) {
    int _screenWidth = 1024;
    int _screenHeight = 600;
    // Definiert die Breite und Höhe des Bildschirms.

    Game game("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN); // Erzeugt eine Instanz der Game-Klasse und initialisiert das Spiel mit den angegebenen Parametern.

    game.run(); // Startet die Hauptfunktion des Spiels, die die Spiel-Initialisierung und die Hauptschleife enthält.

    return 0; // Gibt eine Erfolgsmeldung (0) zurück, um anzuzeigen, dass das Spiel ohne Fehler beendet wurde.
}
