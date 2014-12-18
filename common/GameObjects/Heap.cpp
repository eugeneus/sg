
#include "Heap.h"

USING_NS_CC;

Heap::Heap(){}

Heap::~Heap() {}

Heap* Heap::create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor) {

	Heap* pRet = new Heap();

    if (!pRet->init(aFileName, aRelativePos, aRelativeSizeFactor))
    {
		delete pRet;
		pRet = nullptr;
    }

    return pRet;

}




