///search struct SCreateData:
			DWORD	m_dwHair;

///add:
#ifdef ENABLE_RANK_SYSTEM
			BYTE	m_bRank;
#endif

///search:
		void					SetHair(DWORD eHair);

///add:
#ifdef ENABLE_RANK_SYSTEM
		void					SetRank(BYTE bRank);
		BYTE					GetRank() const{ return m_bRank; }
#endif

///search:
		DWORD					m_dwLevel;

///add:
#ifdef ENABLE_RANK_SYSTEM
		BYTE					m_bRank;
#endif

