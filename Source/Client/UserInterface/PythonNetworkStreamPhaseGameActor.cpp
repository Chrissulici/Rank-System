///search:
	kNetActorData.m_dwHair=0;

///add:
#ifdef ENABLE_RANK_SYSTEM
	kNetActorData.m_bRank = 0;
#endif

///search:
		kNetActorData.m_dwHair=chrInfoPacket.awPart[CHR_EQUIPPART_HAIR];

///add:
#ifdef ENABLE_RANK_SYSTEM
		kNetActorData.m_bRank=chrInfoPacket.bRank;
#endif

///search:
	kNetUpdateActorData.m_dwHair=chrUpdatePacket.awPart[CHR_EQUIPPART_HAIR];

///add:
#ifdef ENABLE_RANK_SYSTEM
	kNetUpdateActorData.m_bRank=chrUpdatePacket.bRank;
#endif

///search:
	kNetUpdateActorData.m_dwHair=chrUpdatePacket.awPart[CHR_EQUIPPART_HAIR];

///add:
#ifdef ENABLE_RANK_SYSTEM
	kNetUpdateActorData.m_bRank=chrUpdatePacket.bRank;
#endif

