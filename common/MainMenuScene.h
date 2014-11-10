
#ifndef __SantaGnomes__MainMenuScene__
#define __SantaGnomes__MainMenuScene__

#include "cocos2d.h"

class MainMenuScene : cocos2d::Scene {

private:
   typedef cocos2d::Scene super;

protected:

public:
   MainMenuScene();

   ~MainMenuScene();

   static MainMenuScene* create();
   
   bool init();

};
#endif /* defined(__SantaGnomes__MainMenuScene__) */
