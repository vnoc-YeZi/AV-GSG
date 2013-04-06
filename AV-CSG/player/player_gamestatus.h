#pragma once
#include <list>

#define Default_Life    2

class Player_GameStatus
{
public:
    Player_GameStatus();
    ~Player_GameStatus();

public:
    ///> ������ߵ÷�
    int GetMaxScore();
    bool SetMaxScore(int nMaxScore);

    ///> �õ���ҵ÷ְ�ĵ÷�, ջ��Ϊ��ͷ�, ջ��Ϊ��߷� 
    bool PopScore(int& nScore);
    ///> ֵ����ҷ���
    bool PushScore(int nScore);
    ///> ��÷���ջ
    bool GetScoreStack(int nScoreStack[]);
    ///> ���÷���ջ
    void SetScoreStack(int nScoreStack[]);

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

    ///> ������Ϸ״̬
    void ResetGameStatus();

private:
    ///> ��Ҵ�ɻ��ĵ�����ߵ÷�
    int m_nMaxScore;
    ///> �洢ǰ10��ҵĵ÷�
    std::list<int> m_nScoreList;
    ///> ��ǰ�÷�
    int m_nScroe;
    ///> ʣ��Ѫ��
    int m_HP;
    ///> ʣ����������
    int m_nLife;
};