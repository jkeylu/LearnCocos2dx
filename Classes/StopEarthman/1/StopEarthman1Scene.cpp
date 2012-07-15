#include "StopEarthman1Scene.h"
#include "Log.h"

USING_NS_CC;

CCScene* StopEarthman1::scene()
{
	// 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	StopEarthman1 *layer = StopEarthman1::create();

	// add layer as a child to scene
	scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StopEarthman1::init()
{
	//////////////////////////////////////////////////////////////////////////
	// super init first
	//////////////////////////////////////////////////////////////////////////

	if (! CCLayer::init())
	{
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(StopEarthman1::menuCloseCallback) );
    pCloseItem->setPosition( ccp(winSize.width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);


	//////////////////////////////////////////////////////////////////////////
	// add your codes below...
	//////////////////////////////////////////////////////////////////////////
   
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("StopEarthman/1/images.plist", "StopEarthman/1/images.png");

	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey("StopEarthman/1/images.png");
	CCSpriteBatchNode *spriteBatch = CCSpriteBatchNode::create(texture);
	addChild(spriteBatch);

	CCSprite* pSprite = CCSprite::createWithSpriteFrameName("Background.png");

	pSprite->setPosition(ccp(winSize.width/2, winSize.height/2));
	spriteBatch->addChild(pSprite, 0);

	pSprite = CCSprite::createWithSpriteFrameName("Grass Block.png");

	pSprite->setPosition(ccp(winSize.width/2, winSize.height/2));
	spriteBatch->addChild(pSprite, 0);

	pSprite = CCSprite::createWithSpriteFrameName("p8.png");

	CCSize dim = pSprite->getContentSize();
	pSprite->setPosition(ccp(winSize.width/2, winSize.height/2+dim.height/2));
	spriteBatch->addChild(pSprite, 0);

    return true;
}

void StopEarthman1::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    //CCDirector::sharedDirector()->end();
	CCDirector::sharedDirector()->popScene();
}

