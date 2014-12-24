
#include "LevelDataProvider.h"

USING_NS_CC;

LevelDataProvider::LevelDataProvider(){}

LevelDataProvider::~LevelDataProvider() {}

LevelDataProvider* LevelDataProvider::create(int aLevelID) {

    LevelDataProvider* pRet = new LevelDataProvider();
    
    if (!pRet->init("Level.plist"))
    {
        delete pRet;
        pRet = nullptr;
    }
    else{
        pRet->updateValues();
        pRet->LoadLevelByID(aLevelID);
    }
    
   return pRet;
}

void LevelDataProvider::LoadLevelByID(int aLevelID)
{
    std::string fileName = "Level_";
    
    char buff[5];
    sprintf(buff, "%d", aLevelID);
    std::string strLevelID = buff;
    fileName += strLevelID;
    fileName += ".plist";
    
    this->init(fileName);
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
//    // walkingActor
//    std::vector<int> _walkingActorList; // list of IDs of walking actors which should appear on the Level
//    
//    std::vector<int> _randomProductsQueue; // list of ID,s of vatious items which are not a part
//    
//    std::vector<int> _giftsQueue;
//    
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
//    int _tossingSpeed; // base speed for fallen products
//    
//    int _tossingFreq; // tosses per sec
//    
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



