
#include "GameModel.h"
#include "GameScene.h"

#include "PlayerData.h"
#include "LevelDataProvider.h"
#include "ActorFactory.h"

#include "GameObjectBase.h"
#include "Heap.h"
#include "FlashLights.h"

USING_NS_CC;

GameModel::GameModel(){}

GameModel::~GameModel() {}

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
	

	int levelToLoad = PlayerData::getInstance()->getCurrentLevel();
	
    this->loadLevel(aLayer, levelToLoad);
	
	this->arrange();

    return true;
}

void GameModel::loadLevel(cocos2d::Layer* aLayer, int aLevel)
{
    LevelDataProvider* levelData = LevelDataProvider::create(aLevel);
    
	// 1. loads all sprites images as is, with relative factors
    _background = GameObjectBase::create("bg.jpg",Point(0.0, 0.0), 1.0);
    aLayer->addChild(_background);
	
	_heap = Heap::create("bg_floor.png", Point(0.0, -0.16), 0.48);
	aLayer->addChild(_heap);
    
    FlashLights *topLights = FlashLights::create("top_lights_0%i.png", 2, 1.0f, Point(_background->getContentSize().width/2 - 10, _background->getContentSize().height - 34), 1.0);
    aLayer->addChild(topLights);

    
    FlashLights *treeLights = FlashLights::create("tree_lights_0%i.png", 3, 2.0f, Point(180, 400), 1.0);
    aLayer->addChild(treeLights);
    
    _gnome = GameObjectBase::create("gnow.png", Point(-0.06, -0.35), 0.18);
    aLayer->addChild(_gnome);
    
    ActorFactory* actorFactory = ActorFactory::create();
    
    
    delete actorFactory;
    delete levelData;
	
    _btnsHolder = Menu::create();
    _btnsHolder->setPosition(Vec2(0, 0));
    //_btnsHolder->setContentSize(aLayer->getContentSize());
    aLayer->addChild(_btnsHolder);
    
    this->addButton("btn_pause.png", "btn_pause_sel.png", CC_CALLBACK_1(GameScene::onPauseCliked, (GameScene *)aLayer), Vec2(0, _background->getContentSize().height), Vec2(0, 1));
    
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
    
    this->arrangeGameObjectForLayer(_background, visibleSize, _sceneCenter);
	this->arrangeGameObjectForLayer((GameObjectBase*)_heap, visibleSize, _sceneCenter);
    this->arrangeGameObjectForLayer(_gnome, visibleSize, _sceneCenter);

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
    float  rp = aGameObject->getRelativePosition().y;
    float offset = aLayerSize.height * rp;
    actualPosition.y = aLayerCenter.y + offset;
	
	aGameObject->setPosition(actualPosition);

}



