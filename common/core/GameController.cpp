
#include "GameController.h"
#include "GameModel.h"
#include "PlayerData.h"
#include "GameState.h"
#include "TouchController.h"


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
    
    
   return true;
}



