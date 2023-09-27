#include <headers/game.h> // Inkludiert die Header-Datei "game.h", die die Deklaration der Game-Klasse enthält.

Game::Game() { // Konstruktor der Game-Klasse. Initialisiert die Member-Variablen.
    _window = nullptr;
    _renderer = nullptr;
    _screenWidth = 1024;
    _screenHeigth = 600;
    _gameState = GameState::PLAY;
};

Game::~Game() {}; // Destruktor der Game-Klasse.

void Game::run() {
    init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeigth, SDL_WINDOW_SHOWN);
    // Ruft die "init"-Methode auf, um das Spiel zu initialisieren, und startet dann die Hauptschleife.
    gameloop();
}

void Game::init(const char* title, int x, int y, int w, int h, Uint32 flags) {
    SDL_Init(SDL_INIT_EVERYTHING);     // Initialisiert die SDL-Bibliothek für alle verfügbaren Subsysteme.

    _window = SDL_CreateWindow(title, x, y, w, h, flags);     // Erstellt ein SDL-Fenster mit den übergebenen Parametern.

    _renderer = SDL_CreateRenderer(_window, -1, 0);     // Erstellt einen SDL-Renderer, der für die Darstellung verwendet wird.
}

void Game::gameloop() {
    while (_gameState != GameState::EXIT){     // Die Hauptschleife des Spiels, die so lange läuft, bis der Spielzustand auf EXIT gesetzt wird.
        handleEvents();
    }
}

void Game::handleEvents() {
    SDL_Event evnt;
    SDL_PollEvent(&evnt);     // Behandelt SDL-Ereignisse, indem sie aus der Ereignisschlange geholt werden.

    switch (evnt.type) {
        case SDL_QUIT:
            _gameState = GameState::EXIT;   // Wenn das SDL-QUIT-Ereignis auftritt (z.B. Fenster schließen), wird der Spielzustand auf EXIT gesetzt.
            break;
        
    default:
        break;
    }
}
