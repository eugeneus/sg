#ifndef __SantaGnomes__LevelDataProvider__
#define __SantaGnomes__LevelDataProvider__

/*
	This class is for loading level configuration data from persistence.
	Persistence is deemed to be plist file, but may be any king.
	
	Loads, converts data.
*/

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
