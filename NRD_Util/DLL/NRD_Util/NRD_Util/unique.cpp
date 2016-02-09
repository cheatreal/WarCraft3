#include "WarCraft.h"

mixunit *uniqueMixunits[UNIQUE_COUNT];
mixunit *legendaryMixunits[LEGENDARY_COUNT];
mixunit *hiddenMixunits[HIDDEN_COUNT];

void setUnique()
{
	uniqueMixunits[0] = new mixunit(u8"���ƶ� ������ â", 4, TEMARI, 2, AMBU, 2, SASORI, 2, JUUGO, 1);
	uniqueMixunits[1] = new mixunit(u8"������ ����4���ع�", 7, NARUTO, 2, YAMATO, 1, KARIN, 1, OROCHIMARU, 1, AMBU, 1, JUUGO, 1, SAKURA, 1);
	uniqueMixunits[2] = new mixunit(u8"����", 6, CHOUJI, 1, NARUTO, 2, SASUKE1, 1, AMBU, 2, SAI, 2, SASUKE, 1);
	uniqueMixunits[3] = new mixunit(u8"���̴ٶ� ��ī��Ű", 3, ZETSU, 3, SASUKE1, 1, CHOUJI, 1);
	uniqueMixunits[4] = new mixunit(u8"�ϸ� ��ȭ", 6, CHOUJI, 1, NARUTO, 1, SASUKE1, 1, TEMARI, 2, AMBU, 1, YAMATO, 1);
	uniqueMixunits[5] = new mixunit(u8"�繫��", 5, KABUTO, 1, YAMATO, 1, SASORI, 2, JUUGO, 1, SASUKE1, 1);
	uniqueMixunits[6] = new mixunit(u8"��Ҹ� ��������", 2, KARIN, 2, SASORI, 5);
	uniqueMixunits[7] = new mixunit(u8"�罺�� ��ȭ������", 5, KARIN, 1, JUUGO, 1, SASUKE, 2, SASUKE1, 1, KABUTO, 1);
	uniqueMixunits[8] = new mixunit(u8"�����", 5, JIRAIYA, 1, TSUNADE, 1, SAKURA, 2, KARIN, 2, KABUTO, 1);
	uniqueMixunits[9] = new mixunit(u8"�߸��� �Ϻ�", 7, YAMATO, 2, SASUKE, 1, NARUTO, 1, SAKURA, 1, SAI, 2, KABUTO, 1, TEMARI, 1);
	uniqueMixunits[10] = new mixunit(u8"���� ���Ŀ�", 5, TEMARI, 2, AMBU, 1, CHOUJI, 2, JIRAIYA, 1, SAI, 1);
	uniqueMixunits[11] = new mixunit(u8"����ġ���� ��ī��Ű", 4, OROCHIMARU, 2, JIRAIYA, 1, TSUNADE, 1, SASUKE1, 1);
	uniqueMixunits[12] = new mixunit(u8"��Ÿġ ��ȭ������", 6, SAI, 1, ZETSU, 1, JUUGO, 1, OROCHIMARU, 1, YAMATO, 2, TEMARI, 1);
	uniqueMixunits[13] = new mixunit(u8"�ں���", 7, JUUGO, 1, OROCHIMARU, 1, AMBU, 1, SAKURA, 2, NARUTO, 1, SAI, 1, SASUKE, 1);
	uniqueMixunits[14] = new mixunit(u8"��� ����ȭ", 4, JUUGO, 2, SASUKE1, 1, KABUTO, 1, OROCHIMARU, 1);
	uniqueMixunits[15] = new mixunit(u8"�����̾� ȣ��", 4, JIRAIYA, 2, NARUTO, 2, SAKURA, 1, OROCHIMARU, 1);
	uniqueMixunits[16] = new mixunit(u8"õ�� ���� �Ŷ�õ��", 4, TSUNADE, 1, JIRAIYA, 2, OROCHIMARU, 1, ZETSU, 1);
	uniqueMixunits[17] = new mixunit(u8"���ַ�", 5, KARIN, 1, JUUGO, 2, OROCHIMARU, 1, ZETSU, 1, SASUKE, 1);
	uniqueMixunits[18] = new mixunit(u8"īī�� ��ȭ�� �����", 5, SAKURA, 2, SASUKE, 2, NARUTO, 2, SAI, 2, JIRAIYA, 1);
	uniqueMixunits[19] = new mixunit(u8"ĭ���", 6, CHOUJI, 1, TEMARI, 2, SAI, 1, KABUTO, 1, YAMATO, 1, SASORI, 1);
	uniqueMixunits[20] = new mixunit(u8"������", 5, KABUTO, 1, TEMARI, 1, SAI, 2, AMBU, 2, SASUKE, 1);
	uniqueMixunits[21] = new mixunit(u8"���� ������ �Ѹ�����", 6, SAI, 3, CHOUJI, 1, TEMARI, 1, NARUTO, 1, SAKURA, 1, SASUKE, 1);
	uniqueMixunits[22] = new mixunit(u8"��ó�", 6, NARUTO, 2, SAKURA, 1, TEMARI, 1, SAI, 1, CHOUJI, 1, JIRAIYA, 1);
	uniqueMixunits[23] = new mixunit(u8"Ű�̸���", 6, NARUTO, 1, SASUKE1, 1, KABUTO, 1, SASUKE, 1, OROCHIMARU, 1, KARIN, 1);
	uniqueMixunits[24] = new mixunit(u8"ų���� 8�������ַ�", 4, CHOUJI, 2, ZETSU, 2, OROCHIMARU, 1, YAMATO, 1);
	uniqueMixunits[25] = new mixunit(u8"����", 6, TEMARI, 1, SAKURA, 2, KARIN, 1, KABUTO, 1, YAMATO, 1, AMBU, 1);
	uniqueMixunits[26] = new mixunit(u8"�޿찡 ����Ÿ", 6, AMBU, 2, SAI, 1, SASUKE, 1, NARUTO, 2, SASUKE1, 1, CHOUJI, 1);

}

void setLegendary()
{
	legendaryMixunits[0] = new mixunit(u8"������Ÿ �β��� �θ�", 10, NARUTO, 2, YAMATO, 1, KARIN, 1, OROCHIMARU, 1, AMBU, 3, JUUGO, 3, SAKURA, 1, TEMARI, 2, SASORI, 2, JIRAIYA, 2);
	legendaryMixunits[1] = new mixunit(u8"������ ��ȸ��", 7, TSUNADE, 1, JIRAIYA, 4, OROCHIMARU, 2, ZETSU, 1, NARUTO, 4, SAKURA, 2, CHOUJI, 2);
	legendaryMixunits[2] = new mixunit(u8"������ ����6���ع�", 12, NARUTO, 4, YAMATO, 1, KARIN, 1, OROCHIMARU, 1, AMBU, 3, JUUGO, 1, SAKURA, 1, SAI, 1, SASUKE, 1, SASUKE1, 1, CHOUJI, 1, JIRAIYA, 1);
	legendaryMixunits[3] = new mixunit(u8"����ī�� �̳��� 4��ȣī��", 9, NARUTO, 4, SAKURA, 2, TEMARI, 1, SAI, 1, CHOUJI, 1, JIRAIYA, 3, OROCHIMARU, 2, SASUKE, 1, KARIN, 1);
	legendaryMixunits[4] = new mixunit(u8"�ٷ��� �����Ѱ� ����", 12, KABUTO, 1, YAMATO, 1, SASORI, 3, JUUGO, 2, SASUKE1, 1, TEMARI, 2, AMBU, 2, SAKURA, 2, SASUKE, 2, NARUTO, 2, SAI, 2, JIRAIYA, 1);
	legendaryMixunits[5] = new mixunit(u8"���̴ٶ� ���������� �׷�����Ʈ", 10, ZETSU, 4, SASUKE1, 1, CHOUJI, 2, KARIN, 2, SASORI, 5, SAI, 1, JUUGO, 1, OROCHIMARU, 1, YAMATO, 2, TEMARI, 1);
	legendaryMixunits[6] = new mixunit(u8"���մ��� ����", 6, TSUNADE, 3, JIRAIYA, 3, OROCHIMARU, 2, ZETSU, 1, SASUKE, 1, KARIN, 1);
	legendaryMixunits[7] = new mixunit(u8"����Ʈ ����", 11, CHOUJI, 2, NARUTO, 3, SASUKE1, 2, TEMARI, 1, SAKURA, 2, KARIN, 1, KABUTO, 1, YAMATO, 1, AMBU, 3, SAI, 2, SASUKE, 1);
	legendaryMixunits[8] = new mixunit(u8"������ ������ 3��ȣī��", 7, TEMARI, 3, AMBU, 3, CHOUJI, 2, JIRAIYA, 3, KABUTO, 1, SAI, 3, SASUKE, 1);
	legendaryMixunits[9] = new mixunit(u8"�罺�� �ҿ��� ������", 7, JUUGO, 5, SASUKE1, 2, KABUTO, 2, OROCHIMARU, 2, KARIN, 2, ZETSU, 1, SASUKE, 3);
	legendaryMixunits[10] = new mixunit(u8"���� ������ ��ȣ�� ��", 5, TSUNADE, 4, JIRAIYA, 3, SAKURA, 2, KARIN, 2, KABUTO, 1);
	legendaryMixunits[11] = new mixunit(u8"�߸��� ȣī�� ���ӾϺ�", 11, YAMATO, 3, SASUKE, 2, NARUTO, 1, SAKURA, 1, SAI, 2, KABUTO, 1, TEMARI, 1, CHOUJI, 2, ZETSU, 2, OROCHIMARU, 2, KARIN, 1);
	legendaryMixunits[12] = new mixunit(u8"���Ű ��ó� ������ ������", 13, NARUTO, 2, SAKURA, 1, TEMARI, 1, SAI, 1, CHOUJI, 3, JIRAIYA, 1, ZETSU, 2, OROCHIMARU, 1, YAMATO, 2, KABUTO, 1, SASORI, 2, JUUGO, 1, SASUKE1, 1);
	legendaryMixunits[13] = new mixunit(u8"��ġ�� ��Ÿġ �Ϻ�", 10, SAI, 1, ZETSU, 3, JUUGO, 2, OROCHIMARU, 1, YAMATO, 2, TEMARI, 1, KARIN, 1, SASUKE, 2, SASUKE1, 2, KABUTO, 2);
	legendaryMixunits[14] = new mixunit(u8"�ں��� �Ȱ������� Ż�ִ���", 8, JUUGO, 2, OROCHIMARU, 2, AMBU, 2, SAKURA, 4, NARUTO, 3, SAI, 3, SASUKE, 3, JIRAIYA, 1);
	legendaryMixunits[15] = new mixunit(u8"�����̾� ���θ��", 6, JIRAIYA, 5, NARUTO, 2, SAKURA, 1, OROCHIMARU, 2, TSUNADE, 1, ZETSU, 1);
	legendaryMixunits[16] = new mixunit(u8"Ű�̸��� ���� �ع�", 11, NARUTO, 2, SASUKE1, 3, KABUTO, 2, SASUKE, 1, OROCHIMARU, 2, KARIN, 1, CHOUJI, 1, TEMARI, 2, AMBU, 1, YAMATO, 1, JUUGO, 2);
	legendaryMixunits[17] = new mixunit(u8"ų���� �̼�ȭ", 8, CHOUJI, 2, ZETSU, 2, OROCHIMARU, 2, YAMATO, 2, KABUTO, 1, SASORI, 2, JUUGO, 2, SASUKE1, 1);
	legendaryMixunits[18] = new mixunit(u8"��� ���Ǵ��� ��ȹ", 9, KARIN, 1, JUUGO, 1, SASUKE, 2, SASUKE1, 1, KABUTO, 1, TSUNADE, 1, JIRAIYA, 2, OROCHIMARU, 1, ZETSU, 3);
	legendaryMixunits[19] = new mixunit(u8"�޿찡 ����", 6, CHOUJI, 2, NARUTO, 4, SASUKE1, 3, AMBU, 4, SAI, 3, SASUKE, 2);
	legendaryMixunits[20] = new mixunit(u8"ī���� ������ ������", 12, JIRAIYA, 2, TSUNADE, 2, SAKURA, 2, KARIN, 2, KABUTO, 1, OROCHIMARU, 2, SASUKE1, 2, CHOUJI, 1, NARUTO, 2, AMBU, 2, SAI, 2, SASUKE, 1);
}

void setHidden()
{
	hiddenMixunits[0] = new mixunit(u8"��Ÿ��� ����", 7, OROCHIMARU, 2, JIRAIYA, 2, TSUNADE, 2, SASUKE1, 1, SAKURA, 2, KARIN, 2, KABUTO, 1);
	hiddenMixunits[1] = new mixunit(u8"��Ҹ� �𷡸����� ��������", 7, KARIN, 2, SASORI, 6, CHOUJI, 1, TEMARI, 2, SAI, 1, KABUTO, 1, YAMATO, 1);
	hiddenMixunits[2] = new mixunit(u8"�罺�� �⸰", 10, KARIN, 1, JUUGO, 2, SASUKE, 2, SASUKE1, 2, KABUTO, 2, SAI, 1, ZETSU, 1, OROCHIMARU, 1, YAMATO, 2, TEMARI, 1);
	hiddenMixunits[3] = new mixunit(u8"���� ���� 2��ȣī��", 6, JIRAIYA, 3, NARUTO, 2, SAKURA, 1, OROCHIMARU, 3, TSUNADE, 1, SASUKE1, 1);
	hiddenMixunits[4] = new mixunit(u8"���� �Ͻö� �ʴ�ȣī��", 11, TSUNADE, 1, YAMATO, 4, SASUKE, 1, NARUTO, 1, SAKURA, 1, SAI, 3, KABUTO, 1, TEMARI, 2, ZETSU, 1, JUUGO, 1, OROCHIMARU, 1);
	hiddenMixunits[5] = new mixunit(u8"�繫�� ���� 6��ȣī��", 8, KABUTO, 2, TEMARI, 2, SAI, 4, AMBU, 2, SASUKE, 2, YAMATO, 2, NARUTO, 1, SAKURA, 1);
	hiddenMixunits[6] = new mixunit(u8"��Ű��ġ ���� ����", 4, CHOUJI, 6, KABUTO, 1, TEMARI, 1, SAI, 1);
	hiddenMixunits[7] = new mixunit(u8"��� ���� ����ȭ", 4, JUUGO, 4, SASUKE1, 2, KABUTO, 2, OROCHIMARU, 2);
	hiddenMixunits[8] = new mixunit(u8"�����ġ", 9, SAI, 3, CHOUJI, 1, TEMARI, 3, NARUTO, 1, SAKURA, 1, SASUKE, 1, AMBU, 2, SASORI, 2, JUUGO, 1);
	hiddenMixunits[9] = new mixunit(u8"�׸��� ǳ�м���", 9, TEMARI, 3, SAKURA, 2, KARIN, 1, KABUTO, 1, YAMATO, 2, AMBU, 2, CHOUJI, 1, NARUTO, 1, SASUKE1, 1);
	hiddenMixunits[10] = new mixunit(u8"ȣ��Ű ������", 9, KARIN, 1, JUUGO, 3, OROCHIMARU, 2, ZETSU, 1, SASUKE, 2, AMBU, 1, SAKURA, 2, NARUTO, 1, SAI, 1);
}

//debug function
void viewUniqueCost()
{
	for (int i = 0; i < UNIQUE_COUNT; i++)
	{
		WarCraftPrintTextEx("%s : %d", uniqueMixunits[i]->getUnitName(), uniqueMixunits[i]->getCost());
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
		sortMap[i] = uniqueMixunits[i]->getCost();
	}

	vector<pair<DWORD, DWORD> > vec(sortMap.begin(), sortMap.end());

	sort(vec.begin(), vec.end(), compare_pair_second<std::less>());

	for (int i = 0; i < 3; i++)
	{

		WarCraftPrintTextEx("|CFFFAFF21[%d]%s|R", i+1, uniqueMixunits[vec[i].first]->getUnitName());
		uniqueMixunits[vec[i].first]->viewMaterial();
		Sleep(2000);
		
	}

}



void createLegendary()
{
	map <DWORD, DWORD> sortMap;

	for (int i = 0; i < LEGENDARY_COUNT; i++)
	{
		sortMap[i] = legendaryMixunits[i]->getCost();
	}

	vector<pair<DWORD, DWORD> > vec(sortMap.begin(), sortMap.end());

	sort(vec.begin(), vec.end(), compare_pair_second<std::less>());

	for (int i = 0; i < 3; i++)
	{

		WarCraftPrintTextEx("|CFFFAFF21[%d]%s|R", i + 1, legendaryMixunits[vec[i].first]->getUnitName());
		legendaryMixunits[vec[i].first]->viewMaterial();
		Sleep(2000);

	}

}


void createHidden()
{
	map <DWORD, DWORD> sortMap;

	for (int i = 0; i < HIDDEN_COUNT; i++)
	{
		sortMap[i] = hiddenMixunits[i]->getCost();
	}

	vector<pair<DWORD, DWORD> > vec(sortMap.begin(), sortMap.end());

	sort(vec.begin(), vec.end(), compare_pair_second<std::less>());

	for (int i = 0; i < 3; i++)
	{

		WarCraftPrintTextEx("|CFFFAFF21[%d]%s|R", i + 1, hiddenMixunits[vec[i].first]->getUnitName());
		hiddenMixunits[vec[i].first]->viewMaterial();
		Sleep(2000);

	}

}



