#pragma once

#include <string.h>
#include <windows.h>

/* ��Сд��ĸ���ӳ�� */
typedef struct _CASE_MAP {

	char map[256];

	_CASE_MAP()
	{
		memset(map, 0, sizeof(map));

		for (BYTE i = 'A'; i <= 'Z'; ++i)
		{
			map[i] = i + 32;
			map[i + 32] = i;
		}
	}
}CASE_MAP;


#ifndef FORMAT_MAXSIZE
#define FORMAT_MAXSIZE 64 // ���ģʽ������
#endif

/* ��༭�������õ�dp���� */
typedef struct _SIMI_DP {

	USHORT dp[FORMAT_MAXSIZE + 10][FORMAT_MAXSIZE + 10];

	_SIMI_DP()
	{
		memset(dp, 0, sizeof(dp));

		for (USHORT i = 0; i < FORMAT_MAXSIZE + 10; ++i)
		{
			dp[0][i] = i;
			dp[i][0] = i;
		}
	}
}SIMI_DP;

namespace strpro {

	// ���ַ�ת���ֽ�
	bool wideCharToMultiByte(wchar_t* wstr, USHORT& length, char* str);

	// �ָ��׺��
	void splitSuffix(wchar_t* name, USHORT& nameLen, wchar_t*& suff, USHORT& suffLen);

	// תСд
	void tolower(char* str, USHORT length);

	// ˫�ֽڱ���ͳһ��Ϊ����
	bool hasZh(const char* str);

	// �ַ����Ƚ����ִ�Сд
	bool strncmp(const char* str1, const char* str2, USHORT length);

	// �ַ����ȽϺ��Դ�Сд
	bool strnicmp(const char* str1, const char* str2, USHORT length);

	bool match_simi_en(const char* format, USHORT flength, const char* str, USHORT slength);
	bool match_simi_zh(const char* format, USHORT flength, const char* str, USHORT slength);

	bool match_simi_case(const char* format, USHORT flength, const char* str, USHORT slength);
	bool match_simi_nocase(const char* format, USHORT flength, const char* str, USHORT slength);

	bool match_prec_case(const char* format, USHORT flength, const char* str, USHORT slength);
	bool match_prec_nocase(const char* format, USHORT flength, const char* str, USHORT slength);

	bool match_cont_case(const char* format, USHORT flength, const char* str, USHORT slength);
	bool match_cont_nocase(const char* format, USHORT flength, const char* str, USHORT slength);
}