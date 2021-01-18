///search typedef struct SPlayerTable:
	long long		gold;

///add:
#ifdef ENABLE_RANK_SYSTEM
	BYTE			bRank;
	DWORD			dwRankPoint;
	BYTE			bFirstDuel;
#endif

///add at the end:
#ifdef ENABLE_RANK_SYSTEM
typedef struct SRankVictim
{
	DWORD	dwVictimPID;
	DWORD	dwLastKillTime;
} TRankVictim;
#endif

