
#include "LevelDataProvider.h"

USING_NS_CC;

LevelDataProvider::LevelDataProvider(){}

LevelDataProvider::~LevelDataProvider() {}

LevelDataProvider* LevelDataProvider::create(int aLevelID) {

    LevelDataProvider* pRet = new LevelDataProvider();
    
    if (!pRet->initWithLevel(aLevelID))
    {
        delete pRet;
        pRet = nullptr;
    }
    
   return pRet;
}

bool LevelDataProvider::initWithLevel(int aLevelID)
{
    bool ret = true;
    if (!init("Level.plist"))
    {
        ret = false;
    }
    else{
        this->_lastUsedActorType = 0;
        this->updateValues();
        this->LoadLevelByID(aLevelID);
    }

}

void LevelDataProvider::LoadLevelByID(int aLevelID)
{
    std::string fileName = "Level_";
    
    char buff[5];
    sprintf(buff, "%d", aLevelID);
    std::string strLevelID = buff;
    fileName += strLevelID;
    fileName += ".plist";
    
    this->init(fileName); // parent's init
    this->updateValues();

}

void LevelDataProvider::updateValues()
{
    
    updateIntValue(_levelID, "LevelID", nullptr);

    CCLOG("_levelID = %d",_levelID);

    updateStringValue(_backgroundImageName, "BackgroundImageName", nullptr);
    
    CCLOG("BackgroundImageName = %s",_backgroundImageName.c_str());

//
//    std::string _chearImageName;
//    std::string _christmasTreeImageName;
//    std::string _productHeapImageName;
//    std::string _carpetImageName;
//    
//    // tossingActor
    
    ValueVector tossingActors;
    if (updateValueVectorValue(tossingActors, "TossingActors", nullptr)) {
        for (const Value& value : tossingActors) {
            _tossingActorList.push_back(value.asInt());
        }
    }
//    // carrierActor
//    std::vector<int> _carrierActorList; // list of IDs of carrier actors which should appear on the Level
    ValueVector carrierActor;
    if (updateValueVectorValue(carrierActor, "CarrierActors", nullptr)) {
        for (const Value& value : carrierActor) {
            _carrierActorList.push_back(value.asInt());
        }
    }
//    // walkingActor
//    std::vector<int> _walkingActorList; // list of IDs of walking actors which should appear on the Level
//    
//    std::vector<int> _randomProductsQueue; // list of ID,s of vatious items which are not a part
    ValueVector randomProductList;
    if (updateValueVectorValue(randomProductList, "RandomProductList", nullptr)) {
        for (const Value& value : randomProductList) {
            _randomProductsQueue.push_back(value.asInt());
        }
    }
    
//    std::vector<int> _giftsQueue;
    ValueVector giftList;
    if (updateValueVectorValue(giftList, "GiftList", nullptr)) {
        for (const Value& value : giftList) {
            _giftsQueue.push_back(value.asInt());
        }
    }
//    cocos2d::Point _productHeapPos;
    
    ValueMap val;
    if (updateValueMapValue(val, "ProductHeapPos", nullptr)) {
        _productHeapPos.x = val.at("x").asFloat();
        _productHeapPos.y = val.at("y").asFloat();
    }
    
//    cocos2d::Size  _productHeapSz;
//    
//    cocos2d::Point _chearPos;
//    cocos2d::Size  _chearSz;
//    
//    cocos2d::Point _christmasTreePos;
//    cocos2d::Size  _christmasTreeSz;
//    
//    cocos2d::Point _carpetPos;
//    cocos2d::Size  _carpetSz;
//    
//    std::vector<cocos2d::Point> _tossingActorPositionList; // list relative position for given tossing Actor
//    
//    cocos2d::Point _walkingLineStartPos;
//    cocos2d::Point _walkingLineEndPos;
//    
//    
//    //std::vector<GiftDesc> _giftsQueue; // list of gifts, determones order fo occurance
//    
//    //GiftBox
//    std::vector<int> _giftBoxList; // list of Boxes we going to use on the level (appearance of box)
//    
//    // game play definition
//    
//    int _walkingSpeed; //spped of carriers, eccential parameter for game
    updateIntValue(_walkingSpeed, "WalkingSpeed", nullptr);
    
//    int _tossingSpeed; // base speed for fallen products
    updateIntValue(_tossingSpeed, "TossingSpeed", nullptr);
//    int _tossingFreq; // tosses per sec
    updateIntValue(_tossingFreq, "TossingFrequency", nullptr);
    updateIntValue(_carrierFreq, "CarrierFrequency", nullptr);
    
//    
//    int _requiredGifts; // how much gifts should be collected
//    // probably we need aray by gifts types
//    int _requiredPoints;
//    
//    int _avialableBonuses;
    
    
    
}

//bool LevelDataProvider::init(int aLeveID)
//{
//    //load data from default level data
//    ValueMap defaultLevelData = FileUtils::getInstance()->getValueMapFromFile("Level.plist");
//    
//    if (defaultLevelData.empty()) {
//        return false;
//    }
//    // parse values, load into members
//    // ...
//    ///
//    
//    std::string fileName = "Level_";
//    
//    char buff[5];
//    sprintf(buff, "%d", aLeveID);
//    std::string strLevelID = buff;
//    fileName += strLevelID;
//    fileName += ".plist";
//    
//    ValueMap levelData = FileUtils::getInstance()->getValueMapFromFile(fileName);
//    // parse values, load into  (override defaults) members
//    // ...
//    ///
//    
//    return true;
//}


std::string LevelDataProvider::getBackgroundImageName()
{
    return _backgroundImageName;
}

std::vector<int> LevelDataProvider::getTossingActorTypes()
{
    return _tossingActorList;
}

std::vector<int> LevelDataProvider::getCarrierActorTypes()
{
    return _carrierActorList;
}

int LevelDataProvider::getNextCarrierType()
{
    int actorType = _carrierActorList.at(_lastUsedActorType);
    
    _lastUsedActorType = (_lastUsedActorType + 1) >= _carrierActorList.size() ? 0 :  _lastUsedActorType++;
    
    return actorType;
}

cocos2d::Point LevelDataProvider::getProductHeapPos()
{
    return _productHeapPos;
}

float LevelDataProvider::getProductHeapSize()
{
    return _productHeapSz;
}

float LevelDataProvider::getWalkingSpeed()
{
    return _walkingSpeed;
}

float LevelDataProvider::getTossingFreq()
{
    return _tossingFreq;
}

float LevelDataProvider::getCarrierFreq()
{
    return _carrierFreq;
}



