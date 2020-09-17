#include "hd.h"
#include "CmdHwinfo.h"
#include <QDebug>

CmdHwinfo::CmdHwinfo()
{

}

void CmdHwinfo::printInfo()
{
    foreach (int keyMM, m_MMInfo.keys()) {
        qDebug() << "*************************" << keyMM  << "***************************";
        foreach (const QString &key, m_MMInfo[keyMM].keys()) {
            qDebug() << key << " ********************** " << m_MMInfo[keyMM][key];
        }
        qDebug() << endl;
        qDebug() << endl;
    }
}

const QMap<int, QMap<QString, QString> > &CmdHwinfo::MMInfo()
{
    return m_MMInfo;
}

void CmdHwinfo::addMapInfo(QMap<QString, QString> &mapInfo, const QString &key, const QString &value)
{
    if (!value.isEmpty()) {
        mapInfo.insert(key, value);
    }
}

void CmdHwinfo::addMMInfo(int key, const QMap<QString, QString> &mapInfo)
{
    m_MMInfo.insert(key, mapInfo);
}

void CmdHwinfo::charPInfo(const QString &info, char *p)
{
    if (p) {
        QString::fromLocal8Bit(p);
        qDebug() << info << " ************* " << QString::fromLocal8Bit(p);
    } else {
        qDebug() << info << " ************* " << "";
    }
}

void CmdHwinfo::charAInfo(const QString &info, char a[], int length)
{
    if (length > 0) {
        qDebug() << info << " ************* " << a;
    } else {
        qDebug() << info << " ************* " << "";
    }
}

void CmdHwinfo::charAInfo(const QString &info, unsigned char a[], unsigned int length)
{
    if (length > 0) {
        QString edid;
        for (unsigned int i = 0; i < length; i++) {
            edid.append(a[i]);
        }
        qDebug() << info << " ************* " << edid;
    } else {
        qDebug() << info << " ************* " << "";
    }
}

void CmdHwinfo::printEdid(unsigned int edid_len[], unsigned char edid_data[][0x80])
{
    charAInfo("edid", edid_data[0], sizeof(edid_data[0]) / sizeof(unsigned char));
    charAInfo("edid", edid_data[1], sizeof(edid_data[1]) / sizeof(unsigned char));
    charAInfo("edid", edid_data[2], sizeof(edid_data[2]) / sizeof(unsigned char));
    charAInfo("edid", edid_data[3], sizeof(edid_data[3]) / sizeof(unsigned char));
    charAInfo("edid", edid_data[4], sizeof(edid_data[4]) / sizeof(unsigned char));
    charAInfo("edid", edid_data[5], sizeof(edid_data[5]) / sizeof(unsigned char));
}
