#ifndef TAB_H
#define TAB_H

#include <QWidget>

class QMenu;
class TabSupervisor;
class CardInfoWidget;

class Tab : public QWidget {
	Q_OBJECT
signals:
	void userEvent(bool globalEvent = true);
protected:
	QMenu *tabMenu;
	TabSupervisor *tabSupervisor;
protected slots:
	void showCardInfoPopup(const QPoint &pos, const QString &cardName);
	void deleteCardInfoPopup();
private:
	bool contentsChanged;
	CardInfoWidget *infoPopup;
public:
	Tab(TabSupervisor *_tabSupervisor, QWidget *parent = 0);
	QMenu *getTabMenu() const { return tabMenu; }
	bool getContentsChanged() const { return contentsChanged; }
	void setContentsChanged(bool _contentsChanged) { contentsChanged = _contentsChanged; }
	virtual QString getTabText() const = 0;
	virtual void retranslateUi() = 0;
	virtual void closeRequest() { }
};

#endif
