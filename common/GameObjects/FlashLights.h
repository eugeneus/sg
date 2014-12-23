
#ifndef __SantaGnomes__FlashLights__
#define __SantaGnomes__FlashLights__

#include "cocos2d.h"
#include "GameObjectBase.h"

class FlashLights : public GameObjectBase {
    
public:
    FlashLights();
    
    ~FlashLights();
    
    static FlashLights* create(const std::string aFileMask, int spritesCount, float delay, cocos2d::Point aRelativePos, float aRelativeSizeFactor);
    
protected:
    bool init(const std::string aFileMask, int spritesCount, float delay, cocos2d::Point aRelativePos, float aRelativeSizeFactor);
private:
    
};



#endif /* defined(__SantaGnomes__FlashLights__) */
