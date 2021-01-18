///search:
		SetWeapon(c_rkCreateData.m_dwWeapon);

///add:
#ifdef ENABLE_RANK_SYSTEM
		SetRank(c_rkCreateData.m_bRank);
#endif

///search:
void CInstanceBase::SetPKMode(BYTE byPKMode)

///add:
#ifdef ENABLE_RANK_SYSTEM
void CInstanceBase::SetRank(BYTE bRank)
{
	m_bRank = bRank;
	RefreshTextTail();
}
#endif

