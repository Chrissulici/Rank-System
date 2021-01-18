///search:
		addPacket.bEmpire = m_bEmpire;

///add:
#ifdef ENABLE_RANK_SYSTEM
		addPacket.bRank = (IsPC()) ? GetRank() : 0;
#endif

///search:
	pack.sAlignment	= m_iAlignment / 10;

///add:
#ifdef ENABLE_RANK_SYSTEM
	pack.bRank = (IsPC()) ? GetRank() : 0;
#endif

///search:
	tab.gold				= GetGold();

///add:
#ifdef ENABLE_RANK_SYSTEM
	tab.bRank				= GetRank();
	tab.dwRankPoint			= GetRankPoint();
	tab.bFirstDuel			= GetFirstDuel();
#endif

///search:
	SetGold(t->gold);

///add:
#ifdef ENABLE_RANK_SYSTEM
	SetRank(t->bRank);
	SetRankPoint(t->dwRankPoint);
	SetFirstDuel(t->bFirstDuel);
#endif

