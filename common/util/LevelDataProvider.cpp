
#include "LevelDataProvider.h"

USING_NS_CC;

LevelDataProvider::LevelDataProvider(){}

LevelDataProvider::~LevelDataProvider() {}

LevelDataProvider* LevelDataProvider::create(int aLeveID) {

    LevelDataProvider* pRet = new LevelDataProvider();
    
    if (pRet->init(aLeveID))
    {
        delete pRet;
        pRet = nullptr;
    }
    
   return pRet;
}

bool LevelDataProvider::init(int aLeveID)
{
    //load data from default level data
    ValueMap defaultLevelData = FileUtils::getInstance()->getValueMapFromFile("Level.plist");
    
    if (defaultLevelData.empty()) {
        return false;
    }
    // parse values, load into members
    // ...
    ///
    
    std::string fileName = "Level_";
    
    char buff[5];
    sprintf(buff, "%d", aLeveID);
    std::string strLevelID = buff;
    fileName += strLevelID;
    fileName += ".plist";
    
    ValueMap levelData = FileUtils::getInstance()->getValueMapFromFile(fileName);
    // parse values, load into  (override defaults) members
    // ...
    ///
    
    return true;
}



