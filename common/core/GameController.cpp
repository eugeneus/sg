
#include "GameController.h"
#include "GameModel.h"
#include "PlayerData.h"
#include "GameState.h"
#include "TouchController.h"

#include "GameObjectBase.h"
#include "WalkingGnome.h"
#include "AnimationFactory.h"


USING_NS_CC;

GameController::GameController(){}

GameController::~GameController() {}

GameController* GameController::create(cocos2d::Layer* aLayer) {
    
    GameController* pRet = new GameController();
    if (!pRet->init(aLayer)) {
        delete pRet;
        pRet = nullptr;
    }

   return pRet;
}

bool GameController::init(cocos2d::Layer* aLayer)
{
    
    _theModel = GameModel::create(aLayer);
    _touchCtl = TouchController::create();
    _animationFactory = AnimationFactory::create();
    
    _launchCountDown = 0.0f;
    
   return true;
}

void GameController::update(float dt)
{
    
    // ask model to check if there are gnomes
    // finished walking line ad do corresponding updates
    _theModel->checkUpdateArrived();
    
    if (_launchCountDown <= 0.0f) {
        
        _launchCountDown = _theModel->getNextLaunchInterval();
        
        WalkingGnome* gnome = _theModel->getNextIdleCarrier();
        int typeId = gnome->getTypeID();
        float walkDuration = _theModel->getWalkDuration();
        Point endPoint = _theModel->getWalkLineEnd();
        FiniteTimeAction* walkAction = _animationFactory->getWalkingActionByType(typeId, walkDuration, endPoint);
        
        gnome->runAction(walkAction);
    }
    else{
        _launchCountDown -= dt;
    }

}






