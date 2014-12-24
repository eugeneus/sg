
#include "ActorFactory.h"

#include "GameObjectBase.h"

USING_NS_CC;

ActorFactory::ActorFactory(){}

ActorFactory::~ActorFactory() {}

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
    _actorsDB = FileUtils::getInstance()->getValueMapFromFile("Actors.plist");
    
   return true;
}

GameObjectBase* ActorFactory::getActorByType(int aTypeID)
{
    
    ValueVector actorsArray = _actorsDB.at("Root").asValueVector();
    
    ValueMap actorMap = actorsArray.at(aTypeID).asValueMap();
    
    std::string baseFrameName = actorMap.at("BaseFrameName").asString();
    
    float posX = actorMap.at("PosX").asFloat();
    float posY = actorMap.at("PosY").asFloat();
    float size = actorMap.at("Size").asFloat();
    
    GameObjectBase* actor = GameObjectBase::create(baseFrameName, cocos2d::Point(posX,posY), size);
    
    //// under construction
    // may create frame animation
    int frames = actorMap.at("countFrames").asInt();
    if (frames) {
        // create frame animation
    }
    
    ValueMap headMap = actorMap.at("Head").asValueMap();
    ValueMap bodyMap = actorMap.at("Body").asValueMap();
    ValueMap handsMap = actorMap.at("Hansd").asValueMap();
    ValueMap legsMap = actorMap.at("Legs").asValueMap();
    
    //// under construction
    
    return actor;
}




