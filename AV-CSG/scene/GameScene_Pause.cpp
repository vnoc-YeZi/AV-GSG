#include "stdafx.h"
#include "GameScene_Pause.h"
#include "control\game\GameFrame.h"

GameScene_Parse::GameScene_Parse()
{

}

GameScene_Parse::~GameScene_Parse()
{

}

void GameScene_Parse::Update()
{
    ///> ��ͣ����ֻ����ȡ����ͣ����Ϣ
    if (InputEngine_->ClickPause())
    {
        SceneEngine_->Pop();
    }
}
