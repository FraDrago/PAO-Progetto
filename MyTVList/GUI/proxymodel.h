#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>

class proxymodel: public QSortFilterProxyModel  {
public:
    proxymodel(QObject* = nullptr);
    int toggleType(const QModelIndex&);


protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;

        };
#endif // PROXYMODEL_H
