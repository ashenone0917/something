#pragma once

#include <string>

#include "Index.h"

#define MODE_PREC 0B0001 // ׼ȷ
#define MODE_CONT 0B0010 // ����
#define MODE_SIMI 0B0100 // ����
#define MODE_CASE 0B1000 // ���ִ�Сд

typedef struct _QUERY {

	BYTE type; // Ŀ���ļ�����
	BYTE attr; // Ŀ���ļ�����
	BYTE mode; // ����ƥ��ģʽ

	BYTE root_vid; // Ŀ��Ŀ¼��id
	UINT root_frn; // Ŀ��Ŀ¼frn

	std::string name; // Ŀ������
	std::string suff; // Ŀ���׺

	_QUERY(BYTE _type, BYTE _attr, BYTE _mode, BYTE _root_vid, UINT _root_frn, std::string _name, std::string _suff)
	{
		type = _type;
		attr = _attr;
		mode = _mode;
		root_vid = _root_vid;
		root_frn = _root_frn;
		name = _name;
		suff = _suff;
	}

	bool nameNeedMatch()
	{
		if (name == "")
		{
			return (mode & MODE_PREC); // �մ�����£�ֻ��׼ȷģʽ��Ҫƥ��
		}
		return true;
	}

	bool suffNeedMatch()
	{
		return suff != "";
	}

	bool typeNeedMatch()
	{
		return type != TYPE_ALL;
	}

	bool attrNeedMatch()
	{
		return attr != ATTR_ALL;
	}

	bool rootNeedMatch()
	{
		return root_vid != 0 && root_frn != 0;
	}

}QUERY;
