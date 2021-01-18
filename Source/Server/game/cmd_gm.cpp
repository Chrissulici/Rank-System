///search:
namespace DoSetTypes{
typedef enum do_set_types_s {GOLD, RACE, SEX, JOB, EXP, MAX_HP, MAX_SP, SKILL, ALIGNMENT, ALIGN

///add:
#ifdef ENABLE_RANK_SYSTEM
	, RANK, RANK_POINT
#endif

///search:
	{ "align",		NUMBER,	NULL	},

///add:
#ifdef ENABLE_RANK_SYSTEM
	{ "rank",		NUMBER,	NULL	},
	{ "rank_point",	NUMBER,	NULL	},
#endif

///search:
		case DoSetTypes::ALIGN: // alignment
		case DoSetTypes::ALIGNMENT: // alignment
			{
				int	amount = 0;
				str_to_number(amount, arg3);
#ifdef ENABLE_UPDATE_ALIGNMENT_FIX
				tch->UpdateAlignment(amount - tch->GetRealAlignment());
#else
				tch->UpdateAlignment(amount - ch->GetRealAlignment());
#endif
			}
			break;

///add:
#ifdef ENABLE_RANK_SYSTEM
		case DoSetTypes::RANK:
			{
				int rank = 0;
				str_to_number(rank, arg3);
				tch->SetRank(rank);
				tch->ComputePoints();
				tch->PointsPacket();
				tch->UpdatePacket();
			}
			break;
			
		case DoSetTypes::RANK_POINT:
			{
				int rank_point = 0;
				str_to_number(rank_point, arg3);
				tch->SetRankPoint(rank_point);
				tch->ComputePoints();
				tch->PointsPacket();
				tch->UpdatePacket();
			}
			break;
#endif

