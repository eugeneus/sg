#ifndef __SantaGnomes__LevelDataProvider__
#define __SantaGnomes__LevelDataProvider__

/*
	This class is for loading level configuration data from persistence.
	Persistence is deemed to be plist file, but may be any king.
	
	Loads, converts data.
*/

#include "cocos2d.h"

// should move to gift factory?
struct GiftDesc{
    int productsCount; // number of distinct Proudcts in a Gift Box
    std::vector<int> productList; // list of distinct product id's
    int giftsPerLevel;  // how may times given gift should appears on the level
};

class LevelDataProvider : public cocos2d::Node {

public:
    LevelDataProvider();
    
    ~LevelDataProvider();
    
    static LevelDataProvider* create();
    
    bool init();
    
protected:

	int _levelID;
	
	std::string _levelName;
	
	std::string _backgroundImageName;
    
    //
    // TODO: image names for other static stuff, aka decorations of level's scene
    // std::string _cheatImageName;
    // std::string _christmasTreeImageName;
    // std::string _productHeapImageName;
    // std::string _carpetImageName;
    // etc ...
    //
    
    // product section
    
    std::vector<int> _randomProductsQueue; // list of ID,s of vatious items which are not a part
                                           // of any Present determines order of occurance
    
    std::vector<GiftDesc> _giftsQueue; // list of gifts, determones order fo occurance
    

    //GiftBox
    std::vector<int> _giftBoxList; // list of gifts, determones order fo occurance
    
    // tossingActor
    std::vector<int> _tossingActorList; // list of IDs of carrier actors which sould appear on the Level
    std::vector<cocos2d::Point> _tossingActorPositionList; // list relative position for given tossing Actor
    
    // carrierActor
    std::vector<int> _carrierActorList; // list of IDs of carrier actors which sould appear on the Level
    
    // walkingActor
    std::vector<int> _walkingActorList; // list of IDs of walking actors which sould appear on the Level
    
    
    // list of
    //GiftDesc
    // giftID
    
    // listOf random Products (not a gift stuff)
    // productID
    
    
    //record giftDesc:
    // int totalProducts // count of distinct Products in the Gift
    // std::vector<int> productList  // list of distinct Product's IDs
    // int giftsPerLEvel // count of the gift of given type on the level
    //std::vector<>
	
	
	// for actors and stuffs we will not store image names in level:
	// it will be number of types (id)
	// even though the behaviour and other will be the same,
    // by ID we may employ different set of images,
    // so we may have lots of different looking stuff (actors, products, etc.)
	
	// game model will ask for types from level plist
	// then call suitable factory class
	// which will create corresponding sprite, using correct images
	
	// each factory will have plist configuration with sprite image description 
	// {id, 
	// number of base frames,
	// number of animation frames per base frame
	//
	//   imageBaseName1,...,imageBaseNameN}
	// it may be several image sets for single game object
	// first of all, even game object is single imaged - it have animation frames
	// if game object consists of several images (with differen animation frames) it will have set of set images
	// THE ISSUE: need to investigate our scaling mechanic: positioning diffrent part of single sprite, scaling different parts of sprite
	//  porbably solution the same: center based alingment on game object level.
	// but there are another issue: some part may have anchor shifted from the center 
	// need to be investigated!
	

private:
    
};

#endif /* defined(__SantaGnomes__LevelDataProvider__) */
