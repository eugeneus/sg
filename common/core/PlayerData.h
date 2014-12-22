#ifndef __SantaGnomes__PlayerData__
#define __SantaGnomes__PlayerData__


/*
 
 Contains User related data:
 
 current level, points, achievements, bonuses, purchases.
 may be it is interface to Socials : GameCenters, FB, etc
 
 */


#include "cocos2d.h"

#include "PlayerDataProvider.h"

class PlayerData : public cocos2d::Node {

public:

	static PlayerData* getInstance();
	
    PlayerData();
    
    ~PlayerData();
    
    static PlayerData* create();
    
    bool init();
    
    int getCurrentLevel();
    void setLevel(int aNextLevel);
    int getPoints();
    int setPoints(int aNewPointsValue);
    
protected:
    
    int _currentLevel;
   
   // total achevenebts information
   
   // by level acievements information

private:
    
};

#endif /* defined(__SantaGnomes__PlayerData__) */
