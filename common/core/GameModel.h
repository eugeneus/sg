#ifndef __SantaGnomes__GameModel__
#define __SantaGnomes__GameModel__

#include "cocos2d.h"
#include "LevelDataProvider.h"

class GameObjectBase;

class GameModel : public cocos2d::Node {

public:
    GameModel();
    
    ~GameModel();
    
    static GameModel* create(cocos2d::Layer* aLayer);
    
    static GameModel* create(cocos2d::Layer* aLayer, int aLevel);
    
    bool init(cocos2d::Layer* aLayer);
    
    void loadLevel(cocos2d::Layer* aLayer, int aLevel);
    
	// calculates base points, sizes and scales, based on current screen size
    void arrange();
    
    void scaleGameObject(GameObjectBase* aGameObject);
    
protected:
    
    // we are going to use centered positioning
    // in order to minimize multiresolution support impact
    // so, positon offset is a ofset of pos relative to center of current screen (visible)
    cocos2d::Size _heapPosOffset;
    
    // in order to minimize multiresolution support
    // we are going to leverage special scale factor.
    // this percent of full visible current screen which should be used
    // for given sprite to arrange actual content size.
    // mostly this factor is defined (hardcoded) on design stage
    // usage:
    // get actual screen size
    // load sprite as is
    // curretnSF = max(sprite->getContentSize()) / max(director::screen::size())
    // actual scale factor = 1 + (currentSF - desidnedSF);
    float _heapScaleFactor;//
    
    cocos2d::Size linePosOffet;
    
    cocos2d::Size _gnomeStartPosOffset;
    float _gnomeScaleFactor;
    
    cocos2d::Point _sceneCenter;

private:
    
};

#endif /* defined(__SantaGnomes__GameModel__) */
