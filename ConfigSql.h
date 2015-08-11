#pragma once
	
#include <qvariant.h>
#include <QString>
#include <QList>
#include <QSqlQuery>

class areaT {
public:
  QString id;
  QString areaname;
};

class regionT {
public:
  QString regionid;
  QString regionname;
};


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


	
	QList<areaT> queryLArea()
	{
		QList<areaT> dataList;

		QSqlQuery query("SELECT id,areaname FROM t_queue_area");
		while (query.next()) {
			areaT data;
			data.id = query.value("id").toString();
			data.areaname = query.value("areaname").toString();

			dataList.append(data);
		}
		return dataList;
	}

	QList<regionT> queryLRegion(QString areaid)
	{
		QList<regionT> dataList;

		QSqlQuery query("SELECT regionid,regionname FROM t_queue_region WHERE areaid = '"+areaid+"'");

		while (query.next()) {
			regionT data;
			data.regionid = query.value("regionid").toString();
			data.regionname = query.value("regionname").toString();

			dataList.append(data);
		}
		return dataList;
	}

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

