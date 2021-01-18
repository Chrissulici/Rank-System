///search CHARACTER::Dead:
	TPacketGCDead pack;
	pack.header	= HEADER_GC_DEAD;
	pack.vid	= m_vid;
	PacketAround(&pack, sizeof(pack));

	REMOVE_BIT(m_pointsInstant.instant_flag, INSTANT_FLAG_STUN);

///add before:
#ifdef ENABLE_RANK_SYSTEM
	#define MAP_INDEXES 4 //Here you set how many map indexes you want.
	int mapIndexRankTable[MAP_INDEXES] = 
	{
		1,		//Map1 red
		21,		//Map1 yellow
		41,		//Map1 blue
		72,		//V3
	};
	
	for (int i = 0; i < MAP_INDEXES; ++i)
	{
		if (pkKiller && !GetWarMap() && IsPC() && pkKiller->IsPC() && GetMapIndex() == mapIndexRankTable[i] && pkKiller->GetMapIndex() == mapIndexRankTable[i])
			SetRankDuel(this, pkKiller);
	}
#endif

///add at the end:
#ifdef ENABLE_RANK_SYSTEM
void CHARACTER::SetRankDuel(LPCHARACTER pChar, LPCHARACTER pkKiller)
{
	bool bRankup = false;
	bool bDerank = false;
	bool bInfoKiller = true;
	bool bInfoThis = true;
	
	int rankTable[13][2] = 
	{
		{	1,		100		},	// Bronze I
		{	2,		200		},	// Bronze II
		{	3,		300		},	// Bronze III
		{	4,		400		},	// Silver I
		{	5,		500		},	// Silver II
		{	6,		600		},	// Silver III
		{	7,		700		},	// Gold I
		{	8,		800		},	// Gold II
		{	9,		900		},	// Gold III
		{	10,		1000	},	// Immortal I
		{	11,		1100	},	// Immortal II
		{	12,		1200	},	// Immortal III
		{	13,		2000	},	// Ultimate
	};
		
	if (NULL == pChar || NULL == pkKiller)
		return;
	
	if (false == pChar->IsPC() || false == pkKiller->IsPC()) 
		return;
	
	if (!pChar->GetDesc() || !pkKiller->GetDesc())
		return;
	
	if (!strcmp(pChar->GetDesc()->GetHostName(), pkKiller->GetDesc()->GetHostName()))
	{
		pkKiller->ChatPacket(CHAT_TYPE_INFO, "You killed someone with with the same IP, therefore he didn't receive any rank points");
		ChatPacket(CHAT_TYPE_INFO, "You was killed by someone with the same IP, therefore you didn't receive any rank points");
		return;
	}

#ifdef ENABLE_HWID_SYSTEM
	if ((!strcmp(pChar->GetHwid(3), pkKiller->GetHwid(3))) && (!strcmp(pChar->GetHwid(4), pkKiller->GetHwid(4))))
	{
		pkKiller->ChatPacket(CHAT_TYPE_INFO, "You killed someone with with the same Hardware, therefore he didn't receive any rank points");
		ChatPacket(CHAT_TYPE_INFO, "You was killed by someone with the same Hardware, therefore you didn't receive any rank points");
		return;
	}
#endif

	if (pkKiller->GetFirstDuel() < POINT_FIRST_DUEL){
		bInfoKiller = false;
		pkKiller->SetFirstDuel(pkKiller->GetFirstDuel() + 1);
	}
	
	if (pChar->GetFirstDuel() < POINT_FIRST_DUEL)
		bInfoThis = false;
	
	if (pkKiller->GetFirstDuel() == POINT_FIRST_DUEL){
		pkKiller->ChatPacket(CHAT_TYPE_BIG_NOTICE, "Congratulations, you've finished your 10 duels, from now on you can increase your rank.");
		pkKiller->SetRankPoint(rankTable[0][1]);
		pkKiller->SetFirstDuel(pkKiller->GetFirstDuel() + 1);
	}
	
	for ( TRankMap::iterator iter = m_RankUp.begin(); iter != m_RankUp.end(); iter++ )
	{
		if(iter->first == pkKiller->GetPlayerID() && iter->second.dwVictimPID == pChar->GetPlayerID())
		{
			if (get_dword_time() < iter->second.dwLastKillTime + 600 * 1000){
				pkKiller->ChatPacket(CHAT_TYPE_INFO, "wait");
				return;
			}
			else
				m_RankUp.erase(iter);
		}
	}

	if (pkKiller->GetFirstDuel() >= POINT_FIRST_DUEL)
	{
		pkKiller->SetRankPoint(pkKiller->GetRankPoint() + POINT_PER_WIN);
		
		if (pkKiller->GetRankPoint() >= rankTable[pkKiller->GetRank()][1] && pkKiller->GetRankPoint() < rankTable[pkKiller->GetRank()+1][1] && pkKiller->GetRank() < 13)
		{
			pkKiller->SetRank(pkKiller->GetRank()+1);
			pkKiller->ComputePoints();
			pkKiller->PointsPacket();
			pkKiller->UpdatePacket();
			bRankup = true;
		}
	}
	else
		pkKiller->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You need %d more matches to get the rank."), POINT_FIRST_DUEL - pkKiller->GetFirstDuel());

	if (pChar->GetFirstDuel() >= POINT_FIRST_DUEL)
	{
		pChar->SetRankPoint(pChar->GetRankPoint() - POINT_PER_LOSE);
		
		if (pChar->GetRankPoint() < rankTable[0][1])
			pChar->SetRankPoint(rankTable[0][1]);
		else if (pChar->GetRankPoint() < rankTable[pChar->GetRank()+1][1] && pChar->GetRank() > 1)
		{
			pChar->SetRank(pChar->GetRank()-1);
			pChar->ComputePoints();
			pChar->PointsPacket();
			pChar->UpdatePacket();
			bDerank = true;
		}
	}

	// char szNoticeRank[QUERY_MAX_LEN];
	
	// if (bRankup)
	// {
		// snprintf(szNoticeRank, sizeof(szNoticeRank), "%s got rankup into %s.", pkKiller->GetName(), GetRankName(pkKiller->GetRank()));
		// BroadcastNotice(szNoticeRank);
	// }
	
	// if (bDerank)
	// {
		// snprintf(szNoticeRank, sizeof(szNoticeRank), "%s got derank into %s.", GetName(), GetRankName(GetRank()));
		// BroadcastNotice(szNoticeRank);
	// }
	
	if (pChar->GetRankPoint() > 0 && pChar->GetFirstDuel() < POINT_FIRST_DUEL)
		pChar->SetRankPoint(0);
	
	if (pkKiller->GetRankPoint() > 0 && pkKiller->GetFirstDuel() < POINT_FIRST_DUEL)
		pkKiller->SetRankPoint(0);
	
	if (bInfoKiller)
		pkKiller->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You've Won +%d rank points (You have: %d)"), POINT_PER_WIN, pkKiller->GetRankPoint());

	if (bInfoThis)
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You've Lost -%d rank points (You have: %d)"), POINT_PER_LOSE, pChar->GetRankPoint());
	
	if (pChar->GetRankPoint() < rankTable[0][1] && pChar->GetFirstDuel() >= POINT_FIRST_DUEL)
		pChar->SetRankPoint(rankTable[0][1]);
	
	if (pkKiller->GetRankPoint() < rankTable[0][1] && pkKiller->GetFirstDuel() >= POINT_FIRST_DUEL)
		pkKiller->SetRankPoint(rankTable[0][1]);
	
	if (pChar->GetRankPoint() < 0)
	{
		pChar->SetRankPoint(0);
		pChar->SetRank(0);
		pChar->ComputePoints();
		pChar->PointsPacket();
		pChar->UpdatePacket();
	}
	
	if (pkKiller->GetRankPoint() < 0)
	{
		pkKiller->SetRankPoint(0);
		pkKiller->SetRank(0);
		pkKiller->ComputePoints();
		pkKiller->PointsPacket();
		pkKiller->UpdatePacket();
	}
	
	if (pkKiller->GetFirstDuel() > POINT_FIRST_DUEL+1)
		pkKiller->SetFirstDuel(POINT_FIRST_DUEL+1);
	
	if (pkKiller->GetRank() > 13)
		pkKiller->SetRank(13);
	
	SRankVictim tempRank;
	tempRank.dwVictimPID = pChar->GetPlayerID();
	tempRank.dwLastKillTime = get_dword_time();
	m_RankUp.insert(std::make_pair(pkKiller->GetPlayerID(), tempRank));
}
#endif

