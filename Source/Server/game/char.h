///search typedef struct character_point:
	long long		gold;

///add:
#ifdef ENABLE_RANK_SYSTEM
	BYTE			bRank;
	DWORD			dwRankPoint;
	BYTE			bFirstDuel;
#endif

///search:
};

ESex GET_SEX(LPCHARACTER ch);

///add before:
#ifdef ENABLE_RANK_SYSTEM
	public:
		int				GetRank() const		{ return m_points.bRank;	}
		void			SetRank(BYTE bRank) { m_points.bRank = bRank; }
		int				GetRankPoint() const		{ return m_points.dwRankPoint;	}
		void			SetRankPoint(DWORD dwRankPoint) { m_points.dwRankPoint = dwRankPoint; }
		int				GetFirstDuel() const		{ return m_points.bFirstDuel;	}
		void			SetFirstDuel(BYTE bFirstDuel) { m_points.bFirstDuel = bFirstDuel; }
		void			SetRankDuel(LPCHARACTER pChar, LPCHARACTER pkKiller);
		const char * RankConvert(BYTE bRank)
		{
			switch (bRank)
			{
				case 0:
					return "0";
				case 1:
					return "1";
				case 2:
					return "2";
				case 3:
					return "3";
				case 4:
					return "4";
				case 5:
					return "5";
				case 6:
					return "6";
				case 7:
					return "7";
				case 8:
					return "8";
				case 9:
					return "9";
				case 10:
					return "10";
				case 11:
					return "11";
				case 12:
					return "12";
				case 13:
					return "13";
			}
		}
	private:
		typedef std::map<DWORD, TRankVictim> TRankMap;
		TRankMap m_RankUp;
#endif

