///search:
void CPythonChat::SChatLine::Delete(CPythonChat::SChatLine* pkChatLine)
{
	pkChatLine->Instance.Destroy();

///add:
#ifdef ENABLE_RANK_SYSTEM
	pkChatLine->InstanceRank.Destroy();
#endif

///search:
CPythonChat::SChatLine::~SChatLine()
{
	Instance.Destroy();

///add:
#ifdef ENABLE_RANK_SYSTEM
	InstanceRank.Destroy();
#endif

///search void CPythonChat::UpdateViewMode(DWORD dwID):
		iHeight += pChatSet->m_iStep;
		--iLineIndex;
		int iWidth = pChatSet->m_ix;

///add:
#ifdef ENABLE_RANK_SYSTEM
		if (pChatLine->InstanceRank.GetWidth() > 0)
		{
			pChatLine->InstanceRank.SetPosition(iWidth + 4, pChatSet->m_iy + iHeight + 2);
			iWidth += pChatLine->InstanceRank.GetWidth() + 8;
		}
#endif

///search void CPythonChat::UpdateEditMode(DWORD dwID):
		iHeight += pChatSet->m_iStep;
		int iWidth = pChatSet->m_ix;

///add:
#ifdef ENABLE_RANK_SYSTEM
		if (pChatLine->InstanceRank.GetWidth() > 0)
		{
			pChatLine->InstanceRank.SetPosition(iWidth + 4, pChatSet->m_iy + iHeight + 2);
			iWidth += pChatLine->InstanceRank.GetWidth() + 8;
		}
#endif

///search:
	for (TChatLineList::iterator itor = pLineList->begin(); itor != pLineList->end(); ++itor)
	{
		CGraphicTextInstance & rInstance = (*itor)->Instance;
		rInstance.Render();

///add:
#ifdef ENABLE_RANK_SYSTEM
		CGraphicImageInstance & rankInstance = (*itor)->InstanceRank;
		rankInstance.Render();
#endif

///search void CPythonChat::AppendChat(int iType, const char * c_szChat):
	pChatLine->Instance.SetValue(c_szChat);

///replace:
	pChatLine->Instance.SetValue(strContent.c_str());
	
///add before:
	std::string strContent = c_szChat;
#ifdef ENABLE_RANK_SYSTEM
	{
		std::string isRankFlag("|rank|");
		int position = strContent.find(isRankFlag);
		
		if (position != std::string::npos)
		{
			strContent = strContent.substr(position + isRankFlag.length(), strContent.length());
			position = strContent.find("|");
			std::string c_szRank = strContent.substr(0, position);
			
			char buf[128];
			sprintf(buf, "d:/ymir work/ui/game/rank/chat/rank_%s.png", c_szRank.c_str());
			pChatLine->InstanceRank.SetImagePointer((CGraphicImage*)CResourceManager::Instance().GetResourcePointer(buf));
			strContent = strContent.substr(position + 1, strContent.length());
		}
	}
#endif

