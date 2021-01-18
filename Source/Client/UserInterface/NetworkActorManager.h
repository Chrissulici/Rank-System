///search struct SNetworkActorData:
	DWORD	m_dwHair;

///add:
#ifdef ENABLE_RANK_SYSTEM
	BYTE	m_bRank;
#endif

///search struct SNetworkUpdateActorData:
	DWORD	m_dwHair;

///add:
#ifdef ENABLE_RANK_SYSTEM
	BYTE	m_bRank;
#endif

///search:
		m_dwHair=0;

///add:
#ifdef ENABLE_RANK_SYSTEM
		m_bRank=0;
#endif

