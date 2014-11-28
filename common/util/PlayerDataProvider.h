#ifndef __SantaGnomes__PlayerDataProvider__
#define __SantaGnomes__PlayerDataProvider__

/*
 Purpose of this class.
 Loads data from persistence.
 Read data to persistence.

 Player data:
 Player data will probably 2 level:
 0 per level info. contains all results, assets user got on each level
 1 current level, totals for levels ?
 
 Per level:
 1. User Identifier
 2. Level ID 
 3. Points
 4. Achievements
 5. Bonuses gained
 6. Bonuses spent
 --
 7. Number of errors
 8. Fails?
 9. Failed attempts on level
10. Number of swipes
11. Number of good swipes
12. Number of wrong swipes 
-- 
*/

#include "cocos2d.h"

class PlayerDataProvider : public cocos2d::Node {

public:
    PlayerDataProvider();
    
    ~PlayerDataProvider();
    
    static PlayerDataProvider* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__PlayerDataProvider__) */
