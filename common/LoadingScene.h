
#ifndef __SantaGnomes__LoadingScene__
#define __SantaGnomes__LoadingScene__

#include "cocos2d.h"

class LoadingScene : public cocos2d::Layer {
    
public:
    LoadingScene();
    
    ~LoadingScene();
    
    static cocos2d::Scene* createScene();
    
    static LoadingScene* create();
    
    bool init();
    
protected:
    
    void preloadData();
    
    void loadingCallBack(cocos2d::Texture2D *texture);
    
private:
    cocos2d::Sprite *spin;
    int numberOfLoadedRes;
    
};

#endif /* defined(__SantaGnomes__LoadingScene__) */
