//
//  game.hpp
//  Incogine
//
//  Created by moritz on 10/17/22.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "../core/core.hpp"

class Game {
public:
    Game();
    ~Game();
    
    void RawEvent(SDL_Event event, int _windowWidth, int _windowHeight);
    void Event(SDL_Event event);
    void Start();
    void Update();
    void Render();
    
private:
    int SceneNow;
};

#endif /* game_hpp */
