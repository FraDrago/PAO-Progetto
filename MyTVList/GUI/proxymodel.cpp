#include "proxymodel.h"
#include "qlistmodel.h"

proxymodel::proxymodel(QObject* parent) : QSortFilterProxyModel (parent) {}

bool proxymodel::filterAcceptsRow(int row_source, const QModelIndex&) const {

    QModelIndex index_source = sourceModel()->index(row_source, 0);

    return sourceModel()->data(index_source).toString().contains(filterRegExp());
}


int proxymodel::toggleType(const QModelIndex& index) {
    QModelIndex index_source = mapToSource(index);
    return index_source.row();
}
