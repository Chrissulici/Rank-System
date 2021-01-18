///search:
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 0);
#endif

///add:
#ifdef ENABLE_RANK_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_RANK_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_RANK_SYSTEM", 0);
#endif

