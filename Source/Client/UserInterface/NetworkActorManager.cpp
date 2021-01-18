///search:
	m_dwHair = src.m_dwHair;

///add:
#ifdef ENABLE_RANK_SYSTEM
	m_bRank = src.m_bRank;
#endif

///search:
	m_dwHair=0;

///add:
#ifdef ENABLE_RANK_SYSTEM
	m_bRank=0;
#endif

///search:
	kCreateData.m_dwHair=rkNetActorData.m_dwHair;

///add:
#ifdef ENABLE_RANK_SYSTEM
	kCreateData.m_bRank = rkNetActorData.m_bRank;
#endif

///search:
		pkInstFind->SetStateFlags(c_rkNetUpdateActorData.m_dwStateFlags);

///add:
#ifdef ENABLE_RANK_SYSTEM
		pkInstFind->SetRank(c_rkNetUpdateActorData.m_bRank);
#endif

///search:
	rkNetActorData.m_dwHair=c_rkNetUpdateActorData.m_dwHair;

///add:
#ifdef ENABLE_RANK_SYSTEM
	rkNetActorData.m_bRank = c_rkNetUpdateActorData.m_bRank;
#endif

