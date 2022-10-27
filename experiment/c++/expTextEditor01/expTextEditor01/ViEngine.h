#ifndef VIENGINE_H
#define VIENGINE_H

#include "qevent.h"
#include <QObject>

class ViEngine : public QObject
{
    Q_OBJECT
public:
    // Edit Mode
    enum class EditMode {
        CMD     = 0,        // Command Input
        INSERT  = 1         // Character Insert
    };

public:
    explicit ViEngine(QObject *parent = nullptr);
    ~ViEngine();

public:
    EditMode  editMode();                             // Mode Getter
    void                setEditMode(EditMode value);  // Mode Setter

public:
    bool    processKeyPressEvent(QKeyEvent *event); //

public:
    bool    cmdModeKeyPressEvent(QKeyEvent *event); //  コマンドモード時キー押下処理
    bool    insModeKeyPressEvent(QKeyEvent *event); //  挿入モード時キー押下処理

private:
    ViEngine::EditMode    m_EditMode;

signals:
    void    editModeChanged(ViEngine::EditMode value);                          // Signal Of Edit Mode Changed

};

#endif // VIENGINE_H
