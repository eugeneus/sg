
#include "ActorFactory.h"

#include "GameObjectBase.h"
#include "WalkingGnome.h"


USING_NS_CC;

ActorFactory::ActorFactory(){}

ActorFactory::~ActorFactory()
{
    _actorsDB.clear();
}

ActorFactory* ActorFactory::create() {
    
    ActorFactory* pRet = new ActorFactory();
    if (!pRet->init()) {
        delete pRet;
        pRet = nullptr;
    }

   return pRet;
}

bool ActorFactory::init()
{
    
    //std::string path = FileUtils::getInstance()->fullPathForFilename("Actors.plist");
    _actorsDB = FileUtils::getInstance()->getValueMapFromFile("Actors1.plist");
    
   return true;
}

WalkingGnome* ActorFactory::getActorByType(int aTypeID)
{
    
    ValueVector actorsArray = _actorsDB.at("Array").asValueVector();
    
    ValueMap actorMap = actorsArray.at(aTypeID).asValueMap();
    
    std::string baseFrameName = actorMap.at("BaseFrameName").asString();
    
    float posX = actorMap.at("PosX").asFloat();
    float posY = actorMap.at("PosY").asFloat();
    float size = actorMap.at("Size").asFloat();
    
    WalkingGnome* actor = WalkingGnome::create(baseFrameName, cocos2d::Point(posX,posY), size);
    
    actor->setTypeID(aTypeID);
    
    //// under construction
    // may create frame animation
    int frames = actorMap.at("countFrames").asInt();
    if (frames) {
        // create frame animation
    }
    
    ValueMap headMap = actorMap.at("Head").asValueMap();
    ValueMap bodyMap = actorMap.at("Body").asValueMap();
    ValueMap handsMap = actorMap.at("Hands").asValueMap();
    ValueMap legsMap = actorMap.at("Legs").asValueMap();
    
    //// under construction
    
    return actor;
}






