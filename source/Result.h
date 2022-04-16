#pragma once

#include <vector>
#include <algorithm>
#include <windows.h>

#pragma pack(1)
typedef struct _ANS_NODE {

	BYTE iconId; // ͼ���� ImageList �еı�ţ���ֵ�����ļ����͵õ�

	BYTE length; // �ļ������ȣ����������̫��ʱ�����մ�ֵ��С���������

	UINT info; // ���������� ID ������λ�����ļ� FRN ����27λ�������ڻ�ȡ�ļ������ļ�·��

	bool operator < (const _ANS_NODE& other) const
	{
		return length < other.length;
	}

	_ANS_NODE(BYTE _iconId, BYTE _length, UINT _info) : iconId(_iconId), length(_length), info(_info) {}

}ANS_NODE, * PANS_NODE;
#pragma pack()

class CResultTable : public std::vector<ANS_NODE> {
public:
	CResultTable() : std::vector<ANS_NODE>() {}

	// ����������϶�ʱ����������Ľ϶�ʱ�䣬����ʱ��������ܿ�����������ģ��ʲ���������
	void sort()
	{
		if (this->size() <= 4096)
		{
			std::sort(begin(), end());
		}
	}
};