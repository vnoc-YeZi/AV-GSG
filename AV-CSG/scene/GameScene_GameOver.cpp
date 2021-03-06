#include "stdafx.h"
#include "GameScene_GameOver.h"
#include "data\resourcedata\PicturePool.h"

GameScene_GameOver::GameScene_GameOver()
    : m_Picture(NULL)
{
    m_Picture = CPicturePool::GetInstance()->GetPicture("gameover");
}

GameScene_GameOver::~GameScene_GameOver()
{
}

void GameScene_GameOver::Update()
{
    if (InputEngine_->ClickOk())
    {
        SceneEngine_->Pop();
    }
}

void GameScene_GameOver::Reset()
{
    ///> 清空图像
    SelectObject(g_hMemDC, GetStockObject(BLACK_BRUSH));
    Rectangle(g_hMemDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void GameScene_GameOver::Output()
{
    //先绘制背景
    if (m_Picture)
    {
        m_Picture->DrawBitmap(g_hMemDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    }

    //绘制排名
    TCHAR szOut[150] = {0};
    RECT textRect;
    wsprintf(szOut, L"本场最终得分: %d\n玩家最高得分: %d",
    Player_->gamestatus_.GetScore(), Player_->gamestatus_.GetMaxScore());

    ::SetBkMode(g_hMemDC, TRANSPARENT);
    ::SetTextColor(g_hMemDC, RGB(255,0,0));

    ::SetRect(&textRect, 180, 150, 200, 250);
    ::DrawText(g_hMemDC, szOut, -1, &textRect, DT_NOCLIP);
    ::BitBlt(g_hWndDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, g_hMemDC, 0, 0, SRCCOPY);
}