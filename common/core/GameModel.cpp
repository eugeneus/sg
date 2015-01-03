
#include "GameModel.h"
#include "GameScene.h"

#include "PlayerData.h"
#include "LevelDataProvider.h"
#include "ActorFactory.h"
#include "ProductFactory.h"

#include "GameObjectBase.h"
#include "TossingGnome.h"
#include "WalkingGnome.h"
#include "Heap.h"
#include "FlashLights.h"
#include "UIConstants.h"

USING_NS_CC;

GameModel::GameModel():
_levelData(nullptr),
_actorFactory(nullptr),
_productFactory(nullptr)
{}

GameModel::~GameModel()
{
    if (_levelData) {
        delete _levelData;
    }
    if (_actorFactory) {
        delete _actorFactory;
    }
    if (_productFactory) {
        delete _productFactory;
    }

}

GameModel* GameModel::create(cocos2d::Layer* aLayer) {

    GameModel* pRet = new GameModel();
	
	if(!pRet->init(aLayer)){
		delete pRet;
		pRet = nullptr;
	}
    
    return pRet;
}

static GameModel* create(cocos2d::Layer* aLayer, int aLevel)
{    
    GameModel* pRet = new GameModel();
    
    
    return pRet;
}

bool GameModel::init(cocos2d::Layer* aLayer)
{
	this->clearLayer(aLayer);
	
    if (_actorFactory) {
        delete _actorFactory;
        _actorFactory  = nullptr;
    }
    _actorFactory = ActorFactory::create();
    
    if (_productFactory) {
        delete _productFactory;
        _productFactory  = nullptr;
    }
    _productFactory = ProductFactory::create();

    _firstUsed = -1;
    _lastUsed = -1;
    
	int levelToLoad = PlayerData::getInstance()->getCurrentLevel();
	
    this->loadLevel(aLayer, levelToLoad);
	
	this->arrange();

    return true;
}

// TODO: it may be obsolete, as far as using lazy loading
void GameModel::loadActors()
{
//    std::vector<int> carriers  = _levelData->getCarrierActorTypes();
//    
//    WalkingGnome* actor;
//    for(int nType : carriers){
//        actor = _actorFactory->getActorByType(nType);
//        _carriers.push_back(actor);
//        _gameLayer->addChild(actor);
//     
//    }
    
    //_gnome = GameObjectBase::create("gnow.png", Point(-0.06, -0.35), 0.18);
    //aLayer->addChild(_gnome);
    
}

void GameModel::loadLevel(cocos2d::Layer* aLayer, int aLevel)
{
    
    _gameLayer = aLayer;
    if (_levelData) {
        delete _levelData;
        _levelData  = nullptr;
    }
    _levelData = LevelDataProvider::create(aLevel);
    
	// 1. loads all sprites images as is, with relative factors
    std::string bkgImg = _levelData->getBackgroundImageName();
    _background = GameObjectBase::create(bkgImg,Point(0.0, 0.0), 1.0);
    _gameLayer->addChild(_background);
	
	_heap = Heap::create(GAME_BG_FLOOR, Point(0.0, -0.16), 0.48);
	_gameLayer->addChild(_heap);
    
    this->loadActors();
    
    FlashLights *topLights = FlashLights::create(GAME_LIGHTS_TOP_MASK, 2, 1.0f, Point(_background->getContentSize().width/2 - 10, _background->getContentSize().height - 34), 1.0);
    _gameLayer->addChild(topLights);

    
    FlashLights *treeLights = FlashLights::create(GAME_LIGHTS_TREE_MASK, 3, 2.0f, Point(180, 400), 1.0);
    _gameLayer->addChild(treeLights);
    
    
    _btnsHolder = Menu::create();
    _btnsHolder->setPosition(Vec2(0, 0));
    //_btnsHolder->setContentSize(aLayer->getContentSize());
    _gameLayer->addChild(_btnsHolder);
    
    this->addButton(GAME_PAUSE_BTN, GAME_PAUSE_BTN_SEL, CC_CALLBACK_1(GameScene::onPauseCliked, (GameScene *)aLayer), Vec2(0, _background->getContentSize().height), Vec2(0, 1));
    
}

void GameModel::addButton(const std::string normalFN, const std::string selectedFN, const ccMenuCallback& callback, Vec2 position, Vec2 anchor) {
    MenuItem *btn = MenuItemSprite::create(
                        Sprite::createWithSpriteFrameName(normalFN),
                        Sprite::createWithSpriteFrameName(selectedFN),
                        callback);
    btn->setPosition(position);
    btn->setAnchorPoint(anchor);
    _btnsHolder->addChild(btn);
}

void GameModel::clearLayer(cocos2d::Layer* aLayer)
{
	// loop through all layer children;

}

// arranges actual positions/sizes for all visible objects
void GameModel::arrange()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	_sceneCenter = Point(visibleSize.width/2.0f, visibleSize.height/2.0f);
	
    _background->setPosition(_sceneCenter);
    
    this->arrangeSceneCoordinates(visibleSize);
    
    this->arrangeGameObjectForLayer(_background, visibleSize, _sceneCenter);
	this->arrangeGameObjectForLayer((GameObjectBase*)_heap, visibleSize, _sceneCenter);

    for (WalkingGnome* carrier : _carriers) {
        this->arrangeGameObjectForLayer((GameObjectBase*)carrier, visibleSize, _sceneCenter);
        carrier->setPosition(_walkingLineStart);
    }

}

// apply effective Scale to GameObject (Sprite)
    // in order to minimize multiresolution support
    // we are going to leverage special scale factor.
    // this percent of full visible current screen which should be used
    // for given sprite to arrange actual content size.
    // mostly this factor is defined (hardcoded) on design stage
void GameModel::arrangeGameObjectForLayer(GameObjectBase* aGameObject, cocos2d::Size aLayerSize, cocos2d::Point aLayerCenter)
{
	float maxScreenDimention = aLayerSize.width >= aLayerSize.height ? aLayerSize.width : aLayerSize.height;
	
	Size  actualSize = aGameObject->getContentSize();
	float maxDimention = actualSize.width >= actualSize.height ? actualSize.width : actualSize.height;

    float sizeFactor = aGameObject->getRelativeSizeFactor();
	
    float actualScale = (maxScreenDimention * sizeFactor) / maxDimention;
	
	aGameObject->setScale(actualScale);
	
	cocos2d::Point actualPosition;
	actualPosition.x = aLayerCenter.x + aLayerSize.width * aGameObject->getRelativePosition().x;
    float rp = aGameObject->getRelativePosition().y;
    float offset = aLayerSize.height * rp;
    actualPosition.y = aLayerCenter.y + offset;
	
	aGameObject->setPosition(actualPosition);

}

cocos2d::Point GameModel::arrangePointInScene(cocos2d::Point aRelativePoint, cocos2d::Size aLayerSize)
{
    float x = _sceneCenter.x + aLayerSize.width * aRelativePoint.x;
    float y = _sceneCenter.y + aLayerSize.height * aRelativePoint.y;
    return Point(x,y);

}
void GameModel::arrangeSceneCoordinates(cocos2d::Size aLayerSize)
{
    Point relative = _levelData->getWalkingLineStart();
    _walkingLineStart = arrangePointInScene(relative, aLayerSize);
    
    relative = _levelData->getWalkingLineEnd();
    _walkingLineEnd = arrangePointInScene(relative, aLayerSize);
    
}


WalkingGnome* GameModel::initNewCarrier()
{
    
    WalkingGnome* newCarrier = nullptr;
    
    // get next id from level data
    int carrierTypeID = _levelData->getNextCarrierType();
    // create and return new carrier by actorFactory
    newCarrier = _actorFactory->getWalkingGnomeByType(carrierTypeID);
    _gameLayer->addChild(newCarrier);
    return newCarrier;
}

TossingGnome* GameModel::getNextTossingGnome()
{
    TossingGnome* nextGnome = nullptr;
    
    std::vector<Point> points = _levelData->getTossingActorPositionList();
    std::vector<int> types = _levelData->getTossingActorTypes();
    Point point;
    int tosserTypeID;
    if (points.size() > _tossers.size()) { //lazy loading
        int nextID = _tossers.size();
        
        cocos2d::Size layerSize = cocos2d::Director::getInstance()->getVisibleSize();
        point = arrangePointInScene(points[nextID], layerSize);
        
        tosserTypeID = types[nextID];
        nextGnome = _actorFactory->getTossingGnomeByType(tosserTypeID);
        nextGnome->setPosition(point);
        nextGnome->setTossingPos(point);
        _gameLayer->addChild(nextGnome);
        _tossers.push_back(nextGnome);
        
        float maxScreenDimention = layerSize.width >= layerSize.height ? layerSize.width : layerSize.height;
        
        Size  actualSize = nextGnome->getContentSize();
        float maxDimention = actualSize.width >= actualSize.height ? actualSize.width : actualSize.height;
        float sizeFactor = nextGnome->getRelativeSizeFactor();
        
        float actualScale = (maxScreenDimention * sizeFactor) / maxDimention;
        
        nextGnome->setScale(actualScale);

    }
    else{
        int randId = rand()%_tossers.size();
        nextGnome = _tossers[randId];
    }
    
    return nextGnome;
}

WalkingGnome* GameModel::getNextIdleCarrier()
{
    WalkingGnome* nextCarrierGnome = nullptr;

    std::vector<WalkingGnome*>::iterator itCarrier = _carriers.begin();
    
    // initials
    if (_lastUsed == -1) {
        _firstUsed = 0;
        _lastUsed = 0;
        
        if (_lastUsed >= _carriers.size()) {  // run out of available gnomes
            _lastUsed = _carriers.size();
            nextCarrierGnome = this->initNewCarrier();
            _carriers.push_back(nextCarrierGnome);
        }
        else{
            nextCarrierGnome = _carriers.at(_lastUsed);
        }
    }
    else{ // regular loop
    
        _lastUsed++;
        if (_lastUsed >= _carriers.size()) {
            _lastUsed = 0; // circuled index
        }
        
        if (_lastUsed == _firstUsed) {
            // run out of capacity, need more carriers
            nextCarrierGnome = this->initNewCarrier();
            if (_lastUsed == 0) {
                _lastUsed = _carriers.size();
                _carriers.push_back(nextCarrierGnome);
            }
            else{
                _carriers.insert(itCarrier+_lastUsed, nextCarrierGnome);
            }
        }
        else{
            nextCarrierGnome = _carriers.at(_lastUsed);
        }
    }
    
    nextCarrierGnome->setPosition(_walkingLineStart);
    
    return nextCarrierGnome;
}

// check the index of most oldest
// walking carrier and shift the index
// if required
bool GameModel::checkUpdateArrived()
{
    bool ret = false;
    
    if (_firstUsed == -1) {
        return ret;
    }
    
    WalkingGnome* carrier = _carriers[_firstUsed];
    float posX = carrier->getPositionX();
    
    if (posX >= _walkingLineEnd.x) {
        _firstUsed++;
        if (_firstUsed >= _carriers.size()) {
            _firstUsed = 0; // circuled index
            ret = true;
        }
        
        carrier->stopAllActions();
    }

    return ret;
}

float GameModel::getWalkDuration()
{
    float durationInSec = 0.0f;
    float walkDistance = _walkingLineStart.getDistance(_walkingLineEnd);
    float speed = _levelData->getWalkingSpeed();
    
    durationInSec = walkDistance / speed;
    
    return durationInSec;
    
}

cocos2d::Point GameModel::getWalkLineEnd()
{
    return _walkingLineEnd;
}

float GameModel::getCarrierIntervalInSec()
{
    return getWalkDuration()/_levelData->getCarrierPerScreen();
}

float GameModel::getTossIntervalInSec()
{
    float walkInterval = getWalkDuration();
    
    float tossInterval = (walkInterval* 0.8) / (_levelData->getCarrierPerScreen() * _levelData->getTossingFreq());
    //float tossInterval = (walkInterval) / (_levelData->getTossingFreq());
    return tossInterval;
}

int GameModel::getTossesPerCarrier()
{
    return _levelData->getTossingFreq();
}






