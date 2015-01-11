
#include "GameController.h"
#include "GameModel.h"
#include "PlayerData.h"
#include "GameState.h"
#include "TouchController.h"

#include "GameObjectBase.h"
#include "WalkingGnome.h"
#include "TossingGnome.h"
#include "AnimationFactory.h"
#include "Product.h"


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
    _tossCountDown = _theModel->getTossIntervalInSec() * 2.0f;
    _tossCountCountDown = 0.0f;
    
   return true;
}

void GameController::update(float dt)
{
    
    // ask model to check if there are gnomes
    // finished walking line and then do corresponding updates
    _theModel->checkUpdateArrived();

    // launch carrier section
    if (_launchCountDown <= 0.0f) {
        
        _launchCountDown = _theModel->getCarrierIntervalInSec();
        _tossCountCountDown += _theModel->getTossesPerCarrier();
        
        WalkingGnome* gnome = _theModel->getNextIdleCarrier();
        int typeId = gnome->getTypeID();
        //TODO:
        //  get and assign GiftID
        //  fill tossing dequeue for given carrier by required number of products
        //
        
        float walkDuration = _theModel->getWalkDuration();
        Point endPoint = _theModel->getWalkLineEnd();
        FiniteTimeAction* walkAction = _animationFactory->getWalkingActionByType(typeId, walkDuration, endPoint);
        
        gnome->runAction(walkAction);
    }
    else{
        _launchCountDown -= dt;
    }
    
    // toss products section
    
    //Product* nextProd = nullptr;
    int nextProd = _theModel->getNextTossingProd(dt);
    if (nextProd) {
        TossingGnome* tossingGnome = _theModel->getNextTossingGnome();
        Point pos1 = tossingGnome->getTossingPos();
        Point pos2 = Point(pos1.x, pos1.y+60.0);
        FiniteTimeAction* action = _animationFactory->getJumpActionByType(1, 1, pos1,pos2);
        
        tossingGnome->runAction(action);
    }
    
//    // old version
//    if (_tossCountCountDown > 0) {
//        if (_tossCountDown <=0.0f) {
//            _tossCountDown = _theModel->getTossIntervalInSec();
//            _tossCountCountDown--;
//            
//            // push tossing action:
//            // determine tossing point
//            TossingGnome* tossingGnome = _theModel->getNextTossingGnome();
//            Point pos1 = tossingGnome->getTossingPos();
//            Point pos2 = Point(pos1.x, pos1.y+60.0);
//            FiniteTimeAction* action = _animationFactory->getJumpActionByType(1, 1, pos1,pos2);
//
//            tossingGnome->runAction(action);
//            
//            // get next pop next product from
//            // tossing dequeue
//            // get corresponding animation
//            // run tossing animation
//            // run gnome-tosser animation
//            
//            
//        }
//        else{
//            _tossCountDown -= dt;
//            //log("_tossCountDown %f", _tossCountDown);
//        }
//    }

}






