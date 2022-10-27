#include "ViEngine.h"

ViEngine::ViEngine(QObject *parent)
    : QObject{parent}
    , m_EditMode(EditMode::CMD)
{
}

ViEngine::~ViEngine()
{
}

////////////////////////////
// Property Setter/Getter //
////////////////////////////
// Edit Mode Setter
void ViEngine::setEditMode(EditMode value)
{
    if(m_EditMode != value){
        m_EditMode = value;             // Change Mode
        emit editModeChanged(value);    // signal transmission
    }
}

// Mode Getter
ViEngine::EditMode ViEngine::editMode()
{
    return m_EditMode;
}


///////////////////
// Public Method //
///////////////////

bool ViEngine::processKeyPressEvent(QKeyEvent *event)
{
    switch(m_EditMode){
        case EditMode::CMD:
            return cmdModeKeyPressEvent(event);    // コマンドモード時キー押下処理
            break;
        case EditMode::INSERT:
            return insModeKeyPressEvent(event);    // 挿入モード時キー押下処理
            break;
        default:
            break;
    }
    return false;
}

////////////////////
// Private Method //
////////////////////

//  コマンドモード時キー押下処理
bool ViEngine::cmdModeKeyPressEvent(QKeyEvent *event)
{
    QString text = event->text();
    if(text == "i"){
        // When "i" is pressed → Charactor Insert Mode
        setEditMode(EditMode::INSERT);
        return true;
    }
    return true;
}

//  挿入モード時キー押下処理
bool ViEngine::insModeKeyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape ){
        // When "ESC" is pressed → Command Input Mode
        setEditMode(EditMode::CMD);
        return true;
    }
    return false;
}
