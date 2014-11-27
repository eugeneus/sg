#ifndef __SantaGnomes__MainMenu__
#define __SantaGnomes__MainMenu__

#include "cocos2d.h"

class MainMenu : public cocos2d::Menu {

public:
    MainMenu();
    
    ~MainMenu();
    
    static MainMenu* create();
    
    bool init();
    
protected:
    
    void menuCallback(cocos2d::Ref* pSender);

private:
    
};

#endif /* defined(__SantaGnomes__MainMenu__) */

/*

Core Game Logic, classes, workflows


GameController - implements core logic
it uses
GameModel - stores all game objects and its attributes (positions, states, etc)
            low level data manipulstion logic
			all data strucutres are public to light access from GameController
ituses
LevelDataProvider - low level logic to retrieve game level state/info from persistence(network)
                    - file manipulation logic
                    - conversion to c++ data structures
                    - public interface for GameModel  					

					
Game Sprites and coordinates

Snow behind the window
Background (room's walls, floor, may be other static elements which are not patrticipate in collision/movement)

Heap of stuff - the heap behind that gnomes jumping and throw items
                rect and origin


1) Walking Line, position and rect.
  
   Gnomes will walk across this line.
   Need coordinates where gnomes should walk
   Need coordinates where items trajectory may end.
   

Main animated sprites and actors

jumping gnomes (may be set of sprites) + animation 

current point, rect, origin point. vector of gnomes (may be several actors)

walking gnomes (may be a set of sprites + animation)

current position, legs animation 

box  -  set of sprites : front, back + item label sprite  

 
*/