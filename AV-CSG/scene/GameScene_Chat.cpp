#include "stdafx.h"
#include "GameScene_Chat.h"
#include "data\resourcedata\PicturePool.h"


GameScene_Chat::GameScene_Chat(const std::string& strChatId)
{
    m_ChatPageList = CChatParser::Instance()->GetChat(strChatId);
    if (m_ChatPageList)
    {
        m_ChatPage = CChatPageParser::Instance()->GetChatPage(
            m_ChatPageList->at(m_PresentChat));
        if (m_ChatPage)
        {
            m_PictureBackgroud = CPicturePool::GetInstance()->GetPicture(
                m_ChatPage->BackgroundID);
            m_PictureMessageRect = CPicturePool::GetInstance()->GetPicture(
                m_ChatPage->SpeckerID);
        }
    }
}


GameScene_Chat::GameScene_Chat()
    : m_PictureBackgroud(NULL)
    , m_PictureMessageRect(NULL)
    , m_PresentChat(0)
    , m_ChatPageList(0)
    , m_ChatPage(NULL)
{
}

GameScene_Chat::~GameScene_Chat()
{
}

void GameScene_Chat::Update()
{
    if (InputEngine_->ClickOk())
    {
        if (m_PresentChat < (int)m_ChatPageList->size())
        {
            m_PresentChat++;
            m_ChatPage = CChatPageParser::Instance()->GetChatPage(
                m_ChatPageList->at(m_PresentChat));
            if (m_ChatPage)
            {
                m_PictureBackgroud = CPicturePool::GetInstance()->GetPicture(
                    m_ChatPage->BackgroundID);
                m_PictureMessageRect = CPicturePool::GetInstance()->GetPicture(
                    m_ChatPage->SpeckerID);
            }
        }
    }
}

void GameScene_Chat::Reset()
{
    ///> ���ͼ��
    SelectObject(g_hMemDC, GetStockObject(BLACK_BRUSH));
    Rectangle(g_hMemDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void GameScene_Chat::Output()
{
    if (!m_ChatPageList && !m_ChatPage && (m_PresentChat < (int)m_ChatPageList->size()))
    {
        return;
    }
    //�Ȼ��Ʊ���
    if (m_PictureBackgroud)
    {
        m_PictureBackgroud->DrawBitmap(g_hMemDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    }
    //�ٻ��ƶԻ���
    if (m_PictureMessageRect)
    {
        m_PictureMessageRect->DrawBitmap(g_hMemDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    }

    RECT textRect;
    ::SetBkMode(g_hMemDC, TRANSPARENT);
    ::SetTextColor(g_hMemDC, RGB(255,0,0));

    ::SetRect(&textRect, 180, 150, 200, 250);
    ::DrawText(g_hMemDC, CA2W(m_ChatPage->Content.c_str()), -1, &textRect, DT_NOCLIP);
    ::BitBlt(g_hWndDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, g_hMemDC, 0, 0, SRCCOPY);
}