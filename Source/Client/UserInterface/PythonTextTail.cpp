///search:
		CGraphicTextInstance * pGuildNameInstance = pTextTail->pGuildNameTextInstance;

///add:
#ifdef ENABLE_RANK_SYSTEM
		CGraphicImageInstance * pRankInstance = pTextTail->pRankInstance;
#endif

///search:
		pTextTail->pTextInstance->SetColor(pTextTail->Color.r, pTextTail->Color.g, pTextTail->Color.b);
		pTextTail->pTextInstance->SetPosition(pTextTail->x + 4.0f, pTextTail->y + yPos, pTextTail->z);
		pTextTail->pTextInstance->Update();

///add before:
#ifdef ENABLE_RANK_SYSTEM
		if (pRankInstance)
			pRankInstance->SetPosition(pTextTail->x + (iNameWidth / 2 - 20.0f) + pRankInstance->GetWidth(), pTextTail->y - 45.0f);
#endif

///search:
		if (pTextTail->pLevelTextInstance)
			pTextTail->pLevelTextInstance->Render();

///add:
#ifdef ENABLE_RANK_SYSTEM
		if (pTextTail->pRankInstance)
			pTextTail->pRankInstance->Render();
#endif

///search:
	pTextTail->pLevelTextInstance=NULL;

///add:
#ifdef ENABLE_RANK_SYSTEM
	pTextTail->pRankInstance=NULL;
#endif

///add:
#ifdef ENABLE_RANK_SYSTEM
		if (pTextTail->pRankInstance)
			pTextTail->pRankInstance->Render();
#endif

///search:
	m_CharacterTextTailMap.insert(TTextTailMap::value_type(dwVirtualID, pTextTail));

///add before:
#ifdef ENABLE_RANK_SYSTEM
	CGraphicImageInstance *& prRank = pTextTail->pRankInstance;
	
	if (!prRank)
	{
		if(pCharacterInstance->IsPC())
		{
			char szFileName[256];
			sprintf(szFileName, "d:/ymir work/ui/game/rank/name/rank_%d.png", pCharacterInstance->GetRank());
			
			if (CResourceManager::Instance().IsFileExist(szFileName))
			{
				CGraphicImage * pRankImage = (CGraphicImage *)CResourceManager::Instance().GetResourcePointer(szFileName);
				
				if (pRankImage)
				{
					prRank = CGraphicImageInstance::New();
					prRank->SetImagePointer(pRankImage);
				}
			}
		}
	}
#endif

///search:
	pTextTail->pLevelTextInstance = NULL;

///add:
#ifdef ENABLE_RANK_SYSTEM
	pTextTail->pRankInstance = NULL;
#endif

///search:
	if (pTextTail->pLevelTextInstance)
	{
		CGraphicTextInstance::Delete(pTextTail->pLevelTextInstance);
		pTextTail->pLevelTextInstance = NULL;
	}

///add:
#ifdef ENABLE_RANK_SYSTEM
	if (pTextTail->pRankInstance)
	{
		CGraphicImageInstance::Delete(pTextTail->pRankInstance);
		pTextTail->pRankInstance = NULL;
	}
#endif

