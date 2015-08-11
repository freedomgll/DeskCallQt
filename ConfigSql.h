#pragma once
	
#include <qvariant.h>
#include <QString>
#include <QList>
#include <QSqlQuery>

class classT {
public:
  QString classid;
  QString classname;
};


class businessT {
public:
  QString businessid;
  QString businessname;
  QString businesscode;
  int layer;
};

class ConfigSql
{
public:
	ConfigSql(void);
	~ConfigSql(void);

	QList<classT> queryLClass(QString regionid)
	{
		QList<classT> dataList;

		QSqlQuery query("SELECT classid,classname FROM t_queue_class WHERE regionid = '"+regionid+"' ORDER BY reorder");
		while (query.next()) {
			classT data;
			data.classid = query.value("classid").toString();
			data.classname = query.value("classname").toString();

			dataList.append(data);
		}
		return dataList;
	}

	QList<businessT> queryLBusiness(QString classid)
	{
		QList<businessT> dataList;

		QSqlQuery query("SELECT businessid,businessname,businesscode,2 as layer FROM t_queue_business WHERE enabled = 1 AND classid = '"+classid+"'");
		while (query.next()) {
			businessT data;
			data.businessid = query.value("businessid").toString();
			data.businessname = query.value("businessname").toString();
			data.businesscode = query.value("businesscode").toString();
			data.layer = query.value("layer").toInt();

			dataList.append(data);
		}
		return dataList;
	}
};

