#pragma once
#include "unit\crc.hpp"

///> ��ǰ��Ϸ�浵�汾
const DWORD CurSaveDataVer = 2;

typedef struct _SAVE_DATA_CONTENT
{
    ///> ������ߵ÷�
    int nMaxScore;
    ///> ǰʮ���а�
    ScoreList scroeList;

    _SAVE_DATA_CONTENT()
    {
        nMaxScore = 0;
        memset(&scroeList, 0, sizeof(scroeList));
    }
}SAVE_DATA_CONTENT;

typedef struct _SAVE_DATA_HEADER
{
    DWORD       dwVersion;  //> �浵�汾
    DWORD       dwSize;     //> �浵���ݴ�С
    DWORD       dwCheckSum; //> �浵����Ч���

    void Calc(const SAVE_DATA_CONTENT& Content)
    {
        dwVersion   = CurSaveDataVer;
        dwSize      = sizeof(SAVE_DATA_CONTENT);
        dwCheckSum  = zl::ExCRC32((BYTE*)&Content, dwSize);
    }
}SAVE_DATA_HEADER;

typedef struct _SAVE_DATA
{
    SAVE_DATA_HEADER    header;
    SAVE_DATA_CONTENT   content;
}SAVE_DATA;

class Player_SaveData
{
public:
    Player_SaveData();
    ~Player_SaveData();

    bool Save();
    bool Load();

private:
    bool LoadFile(SAVE_DATA& data);
    bool SaveFile(const SAVE_DATA& data);

private:
    std::string m_strDataFile;
};
