
#ifndef __SantaGnomes__FlachLightsModeFactory__
#define __SantaGnomes__FlachLightsModeFactory__

enum
{
    kModeStepByStep = 0,
    kModeOne  // 1

};

class FlachLightsModeFactory {
    
public:
    static void runAction(int mode,cocos2d::Sprite *target, float delay, const std::string frameMask, int frameCount);
    static cocos2d::Animation *createFrameAnimation(const std::string frameMask, int frameCount, float delay);
    
protected:
    static void runStepByStepAction(cocos2d::Sprite *target, float delay, const std::string frameMask, int frameCount);
};


#endif /* defined(__SantaGnomes__FlachLightsModeFactory__) */
