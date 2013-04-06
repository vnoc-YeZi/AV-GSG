#pragma once

#define Default_Life    2

typedef struct _ScoreList
{
    int nScore[10];
}ScoreList;

class Player_GameStatus
{
public:
    Player_GameStatus();
    ~Player_GameStatus();

public:
    ///> ������ߵ÷�
    int GetMaxScore();
    bool SetMaxScore(int nScore);

    ///> ʣ������
    int GetLife();
    int AddLife(int nAdd = 1);
    int SubLife(int nSub = 1);

    ///> Ѫ��
    int GetHp();
    void SetHp(int nHp);
    int AddHp(int nAdd);
    int SubHp(int nSub);

    ///> ��ǰ�÷�
    int GetScore();
    int AddScore(int nAdd);
    int SubScore(int nSub);

    ///> ǰʮ���а�
    bool SetScore2List(int nScore);
    void GetScoreList(ScoreList& list);
    void SetScoreList(const ScoreList& list);

    ///> ������Ϸ״̬
    void ResetGameStatus();

private:
    ///> ��Ҵ�ɻ��ĵ�����ߵ÷�
    int m_nMaxScore;
    ///> ��ǰ�÷�
    int m_nScroe;
    ///> ʣ��Ѫ��
    int m_HP;
    ///> ʣ����������
    int m_nLife;
    ///> ǰʮ���а�
    ScoreList m_ScoreList;
};