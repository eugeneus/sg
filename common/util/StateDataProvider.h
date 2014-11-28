#ifndef __SantaGnomes__StateDataProvider__
#define __SantaGnomes__StateDataProvider__

/*
	Purpose of this class is to load/store/safe game state parameters.
	Not sure this class required for this game.
	Depends on how complicated logic will be implemented.
	Also may be used as a persistence bridge for save/load (serialize) all game objects  
*/

#include "cocos2d.h"

class StateDataProvider : public cocos2d::Node {

public:
    StateDataProvider();
    
    ~StateDataProvider();
    
    static StateDataProvider* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__StateDataProvider__) */
