#ifndef __SantaGnomes__LevelDataProvider__
#define __SantaGnomes__LevelDataProvider__

/*
	This class is for loading level configuration data from persistence.
	Persistence is deemed to be plist file, but may be any king.
	
	Loads, converts data.
*/

#include "cocos2d.h"

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
	
	// carrierActor
	// std::string _imageNameBase;
	// tossingActor
	// std::string _imageNameBase;
	// walkingActor
	// std::string _imageNameBase;
	
	//GiftBox
	// std::string _baseImageName;
	
	// list of
	//GiftDesc
	// giftID
	
	// listOf random Products (not a gift stuff)
	// productID

private:
    
};

#endif /* defined(__SantaGnomes__LevelDataProvider__) */
