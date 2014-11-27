#ifndef __SantaGnomes__GameModel__
#define __SantaGnomes__GameModel__

#include "cocos2d.h"
#include "LevelDataProvider.h"

class GameModel : public cocos2d::Node {

public:
    GameModel();
    
    ~GameModel();
    
    static GameModel* create(cocos2d::Layer aLayer);
    
    bool init(cocos2d::Layer aLayer);
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__GameModel__) */
