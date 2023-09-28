#include <headers/game.hpp>  // Inkludiere den Header der Game-Klasse.

int main(int argc, char* argv[]) {
    int _screenWidth = 1024;
    int _screenHeight = 600;

    Game game("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);     // Erzeuge ein Game-Objekt mit den gewünschten Fenstereinstellungen.
    SDL_Texture* frog = game.loadTexture("res/cpp.png");     // Lädt eine Textur für das Spiel.

    // Die Hauptschleife des Spiels, die so lange läuft, bis das Spiel beendet wird.
    while (game.gameState != GameState::EXIT) {
        SDL_Event event;
        SDL_PollEvent(&event);

        // Überprüfe auf Ereignisse, z.B. das Schließen des Fensters.
        switch(event.type) {
            case SDL_QUIT:
                game.gameState = GameState::EXIT;
                break;
        }

        // Rendere die Frosch-Textur auf den Bildschirm und aktualisiere den Spielzustand.
        game.render(frog);
        game.run();
    }

    return 0;
}
