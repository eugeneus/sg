
#include "GameController.h"
#include "GameModel.h"
#include "PlayerData.h"
#include "GameState.h"
#include "TouchController.h"

#include "GameObjectBase.h"


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
    
    _launchCountDown = 0.0f;
    
   return true;
}

void GameController::update(float dt)
{
    
    // call data model for walkingline situp
    // new member launchCarrier()
    // which will do the next:
    // get carrier frequency,
    // calc time interval,
    // remove dt from time interval until < = 0.0f
    //   then start animation for next carrier
    
    if (_launchCountDown <= 0.0f) {
        
        //_launchCountDown = _theModel->getNextLaunchInterval();
        
        // getNExtCarrier
        // create/update walkig animation
        // start anmation
    }
    else{
        _launchCountDown -= dt;
    }

    //check the carrier fihish walking line:
    // get firstUsed
    // check the position
    // if position >= walking line end
    // update firstUsed++
    // this will the model method checkArrivedCarriers();
}






