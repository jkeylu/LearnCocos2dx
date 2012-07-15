
#include "Log.h"
#include "ListViewScene.h"

#include "StopEarthman/1/StopEarthman1Scene.h"

ListViewScene::ListViewScene()
{

}

ListViewScene::~ListViewScene()
{

}

CCScene* ListViewScene::scene()
{
	CCScene *scene = CCScene::create();
	ListViewScene *layer = ListViewScene::create();
	scene->addChild(layer);

    return scene;
}

void ListViewScene::buildDataList()
{
	std::list<std::string> *list = new std::list<std::string>;

	list->push_back("StopEarthman 1");
	list->push_back("hello");
	list->push_back("world");

	m_pDataList = list;
}

bool ListViewScene::init()
{
	if (!CCLayer::init()) {
		return false;
	}

	buildDataList();

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(ListViewScene::menuCloseCallback) );
    pCloseItem->setPosition( ccp(winSize.width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);



	CCListView *listView = CCListView::create(CCListViewModeVertical);
	CCSize listSize = CCSizeMake(winSize.width, winSize.height);
	listView->setContentSize(listSize);
	listView->setDelegate(this);
	listView->setPosition(CCPointZero);
	this->addChild(listView);

	m_pListView = listView;

	return true;
}

void ListViewScene::CCListView_numberOfCells(CCListView *listView, CCListViewProtrolData *data)
{
	data->nNumberOfRows = m_pDataList->size();
}

void ListViewScene::CCListView_cellForRow(CCListView *listView, CCListViewProtrolData *data)
{
	CCSize listSize = m_pListView->getContentSize();
	CCSize cellSize = CCSizeMake(listSize.width, listSize.height / 10);

	CCListViewCell *cell = CCListViewCell::node();
	cell->setOpacity(0);
	cell->setContentSize(cellSize);
	cell->setSelectionColor(ccc4(255, 0, 0, 255));
	data->cell = cell;

	std::list<std::string>::iterator it = m_pDataList->begin();
	for (int i = 0; i < data->nRow; ++i) {
		++it;
	}

	CCLabelTTF *cellLabel = CCLabelTTF::create(((std::string) *it).c_str(), "Arial", 32);
	cellLabel->setPosition(ccp(cellSize.width / 2, cellSize.height / 2));
	cell->addChild(cellLabel);
}

void ListViewScene::CCListView_didClickCellAtRow(CCListView *listView, CCListViewProtrolData *data)
{
	LOGD("row: %d", data->nRow);

	CCScene *scene = NULL;
	CCScene *transition = NULL;
	switch (data->nRow)
	{
		case 0:
			scene = StopEarthman1::scene();
			transition = CCTransitionRotoZoom::create(1, scene);
			CCDirector::sharedDirector()->pushScene(transition);
			break;
		case 1:
			break;
		default:
			break;
	}
}

void ListViewScene::CCListView_didScrollToRow(CCListView *listView, CCListViewProtrolData *data)
{
	
}

void ListViewScene::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}

