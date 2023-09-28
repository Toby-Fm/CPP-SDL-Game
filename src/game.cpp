#include <headers/game.hpp>  // Inkludiere den Header der Game-Klasse.

// Konstruktor der Game-Klasse.
Game::Game(const char* title, int x, int y, int w, int h, Uint32 flags) {
    SDL_Init(SDL_INIT_EVERYTHING);     // Initialisiere die SDL-Bibliothek.

    window = SDL_CreateWindow(title, x, y, w, h, flags);     // Erzeuge ein SDL-Fenster mit den angegebenen Parametern.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);     // Erzeuge einen SDL-Renderer für das Fenster.
};

// Die run-Funktion, die den Spiel-Loop steuert.
void Game::run() {
    display();     // Zeige das gerenderte Bild an.
    clear();
}

// Funktion zum Laden einer Textur aus einer Bilddatei.
SDL_Texture* Game::loadTexture(const char* filePath) {
    SDL_Texture* tex = NULL;

    tex = IMG_LoadTexture(renderer, filePath);     // Lade die Textur aus der angegebenen Datei.

    // Überprüfe, ob die Textur erfolgreich geladen wurde.
    if(tex == NULL) {
        std::cout << "Bild konnte nicht aus Dateipfad geladen werden: " << filePath << SDL_GetError() << std::endl; 
    }

    return tex;     // Gib die geladene Textur zurück.
};

// Funktion zum Rendern einer Textur auf dem Bildschirm.
void Game::render(SDL_Texture* tex) {
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 800;
    src.h = 800;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 800;
    dst.h = 700;

    // Kopiere die Textur auf den Renderer und positioniere sie.
    SDL_RenderCopy(renderer, tex, &src, &dst);
}

// Funktion zum Anzeigen des gerenderten Bildes.
void Game::display() {
    SDL_RenderPresent(renderer);     // Präsentiere den Renderer, um das gerenderte Bild auf dem Bildschirm anzuzeigen.
};

// Funktion zum Löschen des Bildschirms.
void Game::clear() {
    SDL_RenderClear(renderer);     // Lösche den aktuellen Inhalt des Renderers.
};

// Funktion zum Aufräumen und Freigeben von Ressourcen.
void Game::cleanUp() {
    SDL_DestroyWindow(window);     // Zerstöre das SDL-Fenster und den Renderer.
};
