
#include "FlachLightsModeFactory.h"
USING_NS_CC;

void FlachLightsModeFactory::runAction(int mode, Sprite *target, float delay, const std::string frameMask, int frameCount)
{
    switch(mode)
    {
        case kModeStepByStep:
        {
            FlachLightsModeFactory::runStepByStepAction(target, delay, frameMask, frameCount);
            break;
        }
        case kModeOne:
        {
            FlachLightsModeFactory::runStepByStepAction(target, delay, frameMask, frameCount);
            break;
        }
            
        default:
        {
            FlachLightsModeFactory::runStepByStepAction(target, delay, frameMask, frameCount);
            break;
        }
    }
}

cocos2d::Animation *FlachLightsModeFactory::createFrameAnimation(const std::string frameMask, int frameCount, float delay) {
    
    Animation *animation = Animation::create();
    animation->setDelayPerUnit(delay);
    
    for (int i=1; i <= frameCount; i++) {
        std::string frameName = CCString::createWithFormat(frameMask.c_str(), i)->getCString();
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
        animation->addSpriteFrame(frame);
    }
    
    return animation;
}

void FlachLightsModeFactory::runStepByStepAction(Sprite *target, float delay, const std::string frameMask, int frameCount) {
    
    Animation *animation = FlachLightsModeFactory::createFrameAnimation(frameMask, frameCount, delay);
    
    auto fadeIn = FadeTo::create(delay/4, 127);
    auto wait = DelayTime::create(3* delay/4);
    auto fadeOut = FadeTo::create(delay/4, 255);
    
    Sequence *pulseSequence = Sequence::create(fadeIn, wait, fadeOut, nullptr);
    
    target->runAction(RepeatForever::create(pulseSequence));
    target->runAction(RepeatForever::create(Animate::create(animation)));
}