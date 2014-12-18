
#include "GameModel.h"

#include "GameObjectBase.h"
#include "Heap.h"

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
	
    this->loadLevel(aLayer, 1);
	
	this->arrange();

    return true;
}

void GameModel::loadLevel(cocos2d::Layer* aLayer, int aLevel)
{

	// 1. loads all sprites images as is, with relative factors
    _background = Sprite::create("bg.jpg");
    aLayer->addChild(_background);
	
	_heap = Heap::create("bg_floor", Point(0.0, 0.0), 1.0);
	aLayer->addChild(_heap);
	
}

void GameModel::clearLayer(cocos2d::Layer aLayer)
{
	// loop through all layer children;

}

// arranges actual positions/sizes for all visible objects
void GameModel::arrange()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	_sceneCenter = Point(visibleSize.width/2.0f, visibleSize.height/2.0f);
	
    _background->setPosition(_sceneCenter);
    
	this->arrangeGameObjectForLayer(_heap, visibleSize, _sceneCenter);

}

// apply effective Scale to GameObject (Sprite)
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
	
	// sizeFactor = 0.1
	// width = 150
	// screen = 640
	// actualFactor = 0.234375
	// effectiveFactor = 1-0.134375 = 0.865625
	// effectiveWidth = 150 * 0.865625 = 129.84375
	// check: 129.84375/640 = 
	// 0.1 - x
	// 0.234375 - 150
	// x = 150 * 0.1 / 0.234375
	// 0.4266666666666667
// deprecated
void GameModel::scaleGameObject(GameObjectBase* aGameObject)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float maxScreenDimention = visibleSize.width >= visibleSize.height ? visibleSize.width : visibleSize.height;
	
    float sizeFactor = aGameObject->getRelativeSizeFactor();
	Size  actualSize = aGameObject->getContentSize();
	float maxDimention = actualSize.width >= actualSize.height ? actualSize.width : actualSize.height;
	
	float actualSizeFactor =  maxDimention /  maxScreenDimention;
	
	float effectiveDim = (maxDimention * sizeFactor) / actualSizeFactor; //recalc size
	float effectiveScale = effectiveDim / maxDimention; // recalc scale
	
	aGameObject->setScale(effectiveScale);
	
	

}

void GameModel::arrangeGameObjectForLayer(GameObjectBase* aGameObject, cocos2d::Size aLayerSize, cocos2d::Point aLayerCenter)
{
	float maxScreenDimention = aLayerSize.width >= aLayerSize.height ? aLayerSize.width : aLayerSize.height;
	
    float sizeFactor = aGameObject->getRelativeSizeFactor();
	Size  actualSize = aGameObject->getContentSize();
	float maxDimention = actualSize.width >= actualSize.height ? actualSize.width : actualSize.height;
	
	float actualSizeFactor =  maxDimention /  maxScreenDimention;
	
	float effectiveDim = (maxDimention * sizeFactor) / actualSizeFactor; //recalc size
	float effectiveScale = effectiveDim / maxDimention; // recalc scale
	
	aGameObject->setScale(effectiveScale);
	
	cocos2d::Point actualPosition;
	actualPosition.x = aLayerCenter.x + aLayerCenter.x * aGameObject->getRelativePosition().x;
	actualPosition.y = aLayerCenter.y + aLayerCenter.y * aGameObject->getRelativePosition().y;
	
	aGameObject->setPosition(actualPosition);

}



