///search ::Chat:
	int len;
	char chatbuf[CHAT_MAX_LEN + 1];
	len = snprintf(chatbuf, sizeof(chatbuf), "%s : %s", ch->GetName(), strContent.c_str());

///replace:
#ifdef ENABLE_RANK_SYSTEM
	int len;
	char chatbuf[CHAT_MAX_LEN + 1];
	char rank[64];
	snprintf(rank, sizeof(rank), "|rank|%s|", ch->RankConvert(ch->GetRank()));
	len = snprintf(chatbuf, sizeof(chatbuf), "%s %s : %s", rank, ch->GetName(), strContent.c_str());
#else
	len = snprintf(chatbuf, sizeof(chatbuf), "%s : %s", ch->GetName(), strContent.c_str());
#endif

