#include "HelloWorldScene.h"
#include "ListViewScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(winSize.width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

	CCMenuItemFont *pListViewEnterItem = CCMenuItemFont::create(
			"# Show All #",
		   	this,
		   	menu_selector(HelloWorld::enterToListViewCallback)
	);

	//pListViewEnterItem->setFontSize(100);
	pListViewEnterItem->setFontSizeObj(80);
	pListViewEnterItem->setColor(ccORANGE);
    pListViewEnterItem->setPosition( ccp(winSize.width / 2, winSize.height / 2) );

    CCMenu* pListViewEnterMenu = CCMenu::create(pListViewEnterItem, NULL);
    pListViewEnterMenu->setPosition(CCPointZero);
    this->addChild(pListViewEnterMenu, 1);

    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::enterToListViewCallback(CCObject* pSender)
{
	CCScene *s = ListViewScene::scene();
	// transition: right to left
	CCTransitionSlideInR *transition = CCTransitionSlideInR::create(1, s);
	// push to stack
	CCDirector::sharedDirector()->pushScene(transition);
}
