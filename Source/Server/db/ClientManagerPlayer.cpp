///search:
			"gold = %lld, "

///add:
#ifdef ENABLE_RANK_SYSTEM
			"rank = %d, "
			"rank_point = %d, "
			"first_duel = %d, "
#endif

///search:
		pkTab->gold,

///add:
#ifdef ENABLE_RANK_SYSTEM
		pkTab->bRank,
		pkTab->dwRankPoint,
		pkTab->bFirstDuel,
#endif

///search:
												"gold, "

///add:
#ifdef ENABLE_RANK_SYSTEM
												"rank, "
												"rank_point, "
												"first_duel, "
#endif

///search:
	str_to_number(pkTab->gold, row[col++]);

///add:
#ifdef ENABLE_RANK_SYSTEM
	str_to_number(pkTab->bRank, row[col++]);
	str_to_number(pkTab->dwRankPoint, row[col++]);
	str_to_number(pkTab->bFirstDuel, row[col++]);
#endif

///search:
													"gold, "

///add:
#ifdef ENABLE_RANK_SYSTEM
													"rank, "
													"rank_point, "
													"first_duel, "
#endif

///search:
													"%lld, "

///add:
#ifdef ENABLE_RANK_SYSTEM
													"%d, "
													"%d, "
													"%d, "
#endif

///search:
													packet->player_table.gold

///add:
#ifdef ENABLE_RANK_SYSTEM
													,packet->player_table.bRank
													,packet->player_table.dwRankPoint
													,packet->player_table.bFirstDuel
#endif

