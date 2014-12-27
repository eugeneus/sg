#ifndef __SantaGnomes__GameModel__
#define __SantaGnomes__GameModel__

#include "cocos2d.h"
#include "LevelDataProvider.h"

class GameObjectBase;
class WalkingGnome;
class Heap;
class ActorFactory;
class ProductFactory;

class GameModel : public cocos2d::Node {

public:
    GameModel();
    
    ~GameModel();
    
    static GameModel* create(cocos2d::Layer* aLayer);
    
    static GameModel* create(cocos2d::Layer* aLayer, int aLevel);
    
    bool init(cocos2d::Layer* aLayer);
    
	void clearLayer(cocos2d::Layer* aLayer);
	
    void loadLevel(cocos2d::Layer* aLayer, int aLevel);
    
	// calculates base points, sizes and scales, based on current screen size
    void arrange();
    
   // void scaleGameObject(GameObjectBase* aGameObject); // deprecated
	
	void arrangeGameObjectForLayer(GameObjectBase* aGameObject, cocos2d::Size aLayerSize, cocos2d::Point aLayerCenter);
    
    WalkingGnome* getNextIdleCarrier();
    
    bool checkUpdateArrived();
    
    float getNextLaunchInterval();
    
    float getWalkDuration();
    
    cocos2d::Point getWalkLineEnd();
    
protected:
    
    //
    void loadActors();
    
    //
    WalkingGnome* initNewCarrier();
    
    //converts relative coordinates/sizes according to
    //current screen
    void arrangeSceneCoordinates(cocos2d::Size aLayerSize);
    
    // we are going to use centered positioning
    // in order to minimize multiresolution support impact
    // so, positon offset is a ofset of pos relative to center of current screen (visible)
    
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
    
    
    cocos2d::Layer* _gameLayer;
    
    LevelDataProvider* _levelData;
    ActorFactory* _actorFactory;
    ProductFactory* _productFactory;

    
    //cocos2d::Size linePosOffet;
    
    //cocos2d::Size _gnomeStartPosOffset;
    //float _gnomeScaleFactor;
    
    cocos2d::Point _sceneCenter;
    cocos2d::Point _walkingLineStart;
    cocos2d::Point _walkingLineEnd;
    
	// visible game objects
	GameObjectBase* _background;
    
	Heap* _heap;
    //GameObjectBase* _gnome;
    
    // carrier support
    std::vector<WalkingGnome*> _carriers;
    int _lastUsed;
    int _firstUsed;
    //
    std::vector<GameObjectBase*> _walkers;
    
    
    cocos2d::Menu* _btnsHolder;
	
private:
    void addButton(const std::string normalFN, const std::string selectedFN, const cocos2d::ccMenuCallback& callback, cocos2d::Vec2 position, cocos2d::Vec2 anchor);

};

#endif /* defined(__SantaGnomes__GameModel__) */
