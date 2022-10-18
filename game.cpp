//
//  game.cpp
//  Incogine
//
//  Created by moritz on 10/17/22.
//

#include "game.hpp"

Game::Game() {
    // Initialize Game
    Console console;
    console.Println("Game initialized successfully");
}

Game::~Game() {
    // Purge Game
    Console console;
    console.Println("Game purged successfully");
}

float playerx = 0, playery = 0, speed = 5;
bool XInvert = false;
bool YInvert = false;
const Uint8 *_Pkeyboard = SDL_GetKeyboardState(0);


void Game::RawEvent(SDL_Event event, int _windowWidth, int _windowHeight) {
    // Events (Keyboard, Mouse, etc.)
    Console console;
}

void Game::Event(SDL_Event event) {
    Console console;
    
    // Quit
    if(event.type == SDL_QUIT) {
        Core::corerunning = false;
    }
}

void Game::Start() {
    // Executes as game launches
    Console console;
}

void Game::Update() {
    // Executes every frame at game
    
    // X = 1175 as end of X
    // Y = 615 as end of Y
    
    if (!XInvert) {
        playerx += speed;
    } else {
        playerx -= speed;
    }
    
    if (!YInvert) {
        playery += speed - 2;
    } else {
        playery -= speed - 2;
    }
    
    if (playerx >= 1175) {
        XInvert = true;
    } else if (playerx <= 0) {
        XInvert = false;
    }
    
    if (playery >= 615) {
        YInvert = true;
    } else if (playery <= 0) {
        YInvert = false;
    }
}

void Game::Render() {
    // Render Game
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslated(playerx, playery, 0);
    glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(0, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 100);
        glVertex2f(0, 100);
    glEnd();
    glPopMatrix();
}
