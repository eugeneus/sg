
#include "GameModel.h"

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
   return false;
}

void GameModel::loadLevel(cocos2d::Layer* aLayer, int aLevel)
{
	// 1. loads all sprites images as is 
	
	// 2. arrange sprites size according current screen
	this->arrange();
}

void GameModel::arrange()
{
	auto dirs = Director::getInstance();
	Size visibleSize = dirs->getVisibleSize();
	
	_sceneCenter = Point(visibleSize.width/2.0f, visibleSize.height/2.0f);
	
	

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
void GameModel::scaleGameObject(Node* aNode) // GameObjectBase
{
	auto dirs = Director::getInstance();
	Size visibleSize = dirs->getVisibleSize();
	float maxScreenDimention = visibleSize.width >= visibleSize.height ? visibleSize.width : visibleSize.height;
	
    float sizeFactor = 0.0;//aNode->getSizeFactor();
	Size  actualSize = aNode->getContentSize();
	float maxDimention = actualSize.width >= actualSize.height ? actualSize.width : actualSize.height;
	
	
	float actualSizeFactor =  maxDimention /  maxScreenDimention;
	
	float effectiveDim = (maxDimention * sizeFactor) / actualSizeFactor;
	
	float effectiveScale = effectiveDim / maxDimention;
	
	aNode->setScale(effectiveScale);

}



