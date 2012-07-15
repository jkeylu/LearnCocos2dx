

#ifndef __LIST_VIEW_SCENE__
#define __LIST_VIEW_SCENE__

#include <list>
#include "cocos2d.h"
#include "extensions/CCListView/CCListView.h"

USING_NS_CC;
USING_NS_CC_EXT;

class ListViewScene : public CCLayer, public CCListViewDelegate
{
public:
	ListViewScene();
	~ListViewScene();

    static cocos2d::CCScene* scene();
	virtual bool init();
    virtual void menuCloseCallback(CCObject* pSender);

	LAYER_CREATE_FUNC(ListViewScene);

public:
	virtual void CCListView_numberOfCells(CCListView *listView, CCListViewProtrolData *data);
	virtual void CCListView_cellForRow(CCListView *listView, CCListViewProtrolData *data);
	virtual void CCListView_didClickCellAtRow(CCListView *listView, CCListViewProtrolData *data);
	virtual void CCListView_didScrollToRow(CCListView *listView, CCListViewProtrolData *data);

private:
	void buildDataList();

private:
	CCListView *m_pListView;
	std::list<std::string> *m_pDataList;
};


#endif
