#include "WarCraft.h"

mixunit *mixunits[UNIQUE_COUNT];

void setUnique()
{
	//sai_unique.view();
	mixunits[0] = new mixunit(u8"���ƶ� ������ â", 4, TEMARI, 2, AMBU, 2, SASORI, 2, JUUGO, 1);
	mixunits[1] = new mixunit(u8"������ ����4���ع�", 7, NARUTO, 2, YAMATO, 1, KARIN, 1,OROCHIMARU, 1, AMBU, 1, JUUGO, 1, SAKURA, 1);
	mixunits[2] = new mixunit(u8"����", 6, CHOUJI, 1, NARUTO, 2 , SASUKE1, 1, AMBU, 2, SAI, 2, SASUKE, 1);
	mixunits[3] = new mixunit(u8"���̴ٶ� ��ī��Ű", 3, ZETSU, 3, SASUKE1, 1, CHOUJI, 1);
	mixunits[4] = new mixunit(u8"�ϸ� ��ȭ", 6, CHOUJI, 1, NARUTO, 1, SASUKE1, 1, TEMARI, 2, AMBU, 1, YAMATO, 1);
	mixunits[5] = new mixunit(u8"�繫��", 5, KABUTO, 1, YAMATO, 1, SASORI, 2, JUUGO, 1, SASUKE1, 1);
	mixunits[6] = new mixunit(u8"��Ҹ� ��������", 2, KARIN, 2, SASORI, 5 );
	mixunits[7] = new mixunit(u8"�罺�� ��ī��Ű", 5, KARIN, 1, JUUGO, 1, SASUKE,2 , SASUKE1,1 ,KABUTO,1 );
	mixunits[8] = new mixunit(u8"�����",5,JIRAIYA,1, TSUNADE, 1,SAKURA,2, KARIN,2,KABUTO,1);
	mixunits[9] = new mixunit(u8"�߸��� �Ϻ�",7 ,YAMATO, 2, SASUKE,1,NARUTO,1 ,SAKURA,1, SAI,2,KABUTO,1,TEMARI,1);
	mixunits[10] = new mixunit(u8"���� ���Ŀ�",5,  TEMARI,2 ,AMBU,1, CHOUJI,2,JIRAIYA,1,SAI,1);
	mixunits[11] = new mixunit(u8"����ġ���� ��ī��Ű", 4, OROCHIMARU,2, JIRAIYA,1, TSUNADE,1,SASUKE1,1);
	mixunits[12] = new mixunit(u8"��Ÿġ ��ȭ������", 6, SAI, 1,ZETSU,1,JUUGO,1,OROCHIMARU,1,YAMATO,2,TEMARI,1);
	mixunits[13] = new mixunit(u8"�ں���",7, JUUGO,1, OROCHIMARU,1,AMBU,1,SAKURA,2,NARUTO,1,SAI,1,SASUKE,1);
	mixunits[14] = new mixunit(u8"��� ����ȭ",4, JUUGO,2, SASUKE1,1,KABUTO,1,OROCHIMARU,1);
	mixunits[15] = new mixunit(u8"�����̾� ȣ��", 4, JIRAIYA,2, NARUTO,2,SAKURA,1,OROCHIMARU,1);
	mixunits[16] = new mixunit(u8"õ�� ���� �Ŷ�õ��", 4,TSUNADE,1, JIRAIYA,2,OROCHIMARU,1,ZETSU,1);
	mixunits[17] = new mixunit(u8"���ַ�", 5, KARIN, 1, JUUGO, 2, OROCHIMARU, 1, ZETSU, 1, SASUKE, 1);
	mixunits[18] = new mixunit(u8"īī�� ��ȭ�� �����",5, SAKURA,2, SASUKE,2, NARUTO,2,SAI,2,JIRAIYA,1);
	mixunits[19] = new mixunit(u8"ĭ���",6, CHOUJI,1,TEMARI,2,SAI,1,KABUTO,1,YAMATO,1,SASORI,1);
	mixunits[20] = new mixunit(u8"������",5,KABUTO,1,TEMARI,1,SAI,2,AMBU,1,SASUKE,1);
	mixunits[21] = new mixunit(u8"���� ������ �Ѹ�����", 6, SAI, 3, CHOUJI, 1, TEMARI, 1, NARUTO, 1, SAKURA, 1, SASUKE, 1);
	mixunits[22] = new mixunit(u8"��ó�",6, NARUTO,2,SAKURA,1,TEMARI,1,SAI,1,CHOUJI,1,JIRAIYA,1);
	mixunits[23] = new mixunit(u8"Ű�̸���",6, NARUTO,1,SASUKE1,1,KABUTO,1,SASUKE,1,OROCHIMARU,1,KARIN,1);
	mixunits[24] = new mixunit(u8"ų���� 8�������ַ�",4, CHOUJI,2,ZETSU,2,OROCHIMARU,1,YAMATO,1);
	mixunits[25] = new mixunit(u8"����",6, TEMARI,1,SAKURA,2, KARIN,1,KABUTO,1,YAMATO,1,AMBU,1);
	mixunits[26] = new mixunit(u8"�޿찡 ����Ÿ",6, AMBU,2,SAI,1,SASUKE,1,NARUTO,2,SASUKE1,1,CHOUJI,1);

}

//debug function
void viewUniqueCost()
{
	for (int i = 0; i < UNIQUE_COUNT; i++)
	{
		WarCraftPrintTextEx("%s : %d", mixunits[i]->getUnitName(), mixunits[i]->getCost());
		Sleep(500);
	}

}

template<template <typename> class P = std::less >
struct compare_pair_second {
	template<class T1, class T2> bool operator()(const std::pair<T1, T2>&left, const std::pair<T1, T2>&right) {
		return P<T2>()(left.second, right.second);
	}
};


void createUnique()
{
	map <DWORD, DWORD> sortMap;

	for (int i = 0; i < UNIQUE_COUNT; i++)
	{
		sortMap[i] = mixunits[i]->getCost();
	}

	vector<pair<DWORD, DWORD> > vec(sortMap.begin(), sortMap.end());

	sort(vec.begin(), vec.end(), compare_pair_second<std::less>());

	for (int i = 0; i < 3; i++)
	{

		WarCraftPrintTextEx("[%d]%s", i+1, mixunits[vec[i].first]->getUnitName());
		mixunits[vec[i].first]->viewMaterial();
		Sleep(1500);
		
	}

}

