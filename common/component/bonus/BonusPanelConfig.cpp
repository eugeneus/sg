
#include "BonusPanelConfig.h"
#include "UIConstants.h"

USING_NS_CC;

BonusPanelConfig::BonusPanelConfig() {}
BonusPanelConfig::~BonusPanelConfig() {}

BonusPanelConfig *BonusPanelConfig::create() {
    BonusPanelConfig* pRet = new BonusPanelConfig();
    
    if (!pRet->init())
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

bool BonusPanelConfig::init() {
    
    return true;
}

int BonusPanelConfig::getPanelWidth() {
    return 300;
}

bool BonusPanelConfig::isLeft() {
    return false;
}

float BonusPanelConfig::getYPos() {
    return -100;
}

std::string BonusPanelConfig::getButtonMaskNormal() {
    return BONUS_SHOW_BTN_WAIT_MASK;
}

int BonusPanelConfig::getButtonFrameCountNormal() {
    return 2;
}

std::string BonusPanelConfig::getButtonMaskShow() {
    return BONUS_SHOW_BTN_NORMAL_MASK;
}

int BonusPanelConfig::getButtonFrameCountShow() {
    return 2;
}

std::string BonusPanelConfig::getButtonMaskHide() {
    return BONUS_SHOW_BTN_NORMAL_MASK;
}

int BonusPanelConfig::getButtonFrameCountHide() {
    return 2;
}

std::string BonusPanelConfig::getButtonMaskWait() {
    return BONUS_SHOW_BTN_WAIT_MASK;
}

int BonusPanelConfig::getButtonFrameCountWait() {
    return 2;
}
