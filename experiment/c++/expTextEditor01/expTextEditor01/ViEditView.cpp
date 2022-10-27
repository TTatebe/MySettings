#include "ViEditView.h"

/// Constructor
ViEditView::ViEditView(QWidget *parent)
    : QPlainTextEdit(parent)
    //, m_EditMode(ViEngine::CMD)
{
    connect(m_viEngine, SIGNAL(editModeChanged(ViEngine::EditMode)), this, SLOT(setEditMode(ViEngine::EditMode)));
    setEditMode(ViEngine::EditMode::CMD);
}

/// Destructor
ViEditView::~ViEditView()
{
}


////////////////////////////
// Property Setter/Getter //
////////////////////////////
// Edit Mode Setter
void ViEditView::setEditMode(ViEngine::EditMode value)
{
    if(m_EditMode != value){
        m_EditMode = value;             // Change Mode
        emit editModeChanged();    // signal transmission
    }
}

// Mode Getter
ViEngine::EditMode ViEditView::editMode()
{
    return m_EditMode;
}


////////////
// Events //
////////////

// キー押下時処理
void ViEditView::keyPressEvent(QKeyEvent *event)
{
    if(m_viEngine != 0 && m_viEngine->processKeyPressEvent(event))
    {
        return;
    }
    QPlainTextEdit::keyPressEvent(event);
}

////////////////////
// Private Method //
////////////////////
