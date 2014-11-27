#ifndef __SantaGnomes__LevelDataProvider__
#define __SantaGnomes__LevelDataProvider__

#include "cocos2d.h"

class LevelDataProvider : public cocos2d::Node {

public:
    LevelDataProvider();
    
    ~LevelDataProvider();
    
    static LevelDataProvider* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__LevelDataProvider__) */
