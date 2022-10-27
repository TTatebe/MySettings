#ifndef VIEDITVIEW_H
#define VIEDITVIEW_H

#include <QPlainTextEdit>

#include "ViEngine.h"
//class ViEngine;

class ViEditView : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit ViEditView(QWidget *parent = 0);       // Constructor
    ~ViEditView();                                  // Destructor

public:
    ViEngine::EditMode  editMode();                             // Mode Getter
    ViEngine            *m_viEngine = new ViEngine();

protected:
    void    keyPressEvent(QKeyEvent *event);        // キー押下時処理

public slots:
    void    setEditMode(ViEngine::EditMode value);  // Mode Setter

private:
    ViEngine::EditMode  m_EditMode;

signals:
    void    editModeChanged();                      // Signal Of Edit Mode Changed

};
#endif // VIEDITVIEW_H
