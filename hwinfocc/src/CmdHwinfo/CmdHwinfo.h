#ifndef CMDHWINFO_H
#define CMDHWINFO_H

#include <QObject>
#include <QMap>

class CmdHwinfo
{
public:
    CmdHwinfo();

public:
    /**
     * @brief printInfo : Print map info of m_MapInfo
     */
    virtual void printInfo();

    /**
     * @brief MMInfo 获取设备信息
     * @return 返回设备信息
     */
    const QMap<int, QMap<QString, QString> > &MMInfo();

protected:

    /**
     * @brief initInfo : init devices info
     */
    virtual void initInfo() = 0;

    /**
     * @brief addMapInfo 添加key-value值到一个map
     * @param mapInfo 要被添加到的map
     * @param key key值
     * @param value　value值
     */
    void addMapInfo(QMap<QString, QString> &mapInfo, const QString &key, const QString &value);

    /**
     * @brief addMMInfo 将mapInfo添加到mapMapInfo
     * @param key key值
     * @param mapInfo QMap<QString, QString>的值
     */
    void addMMInfo(int key, const QMap<QString, QString> &mapInfo);

    /**
     * @brief charPInfo : 打印char* 信息
     * @param info
     * @param p
     */
    void charPInfo(const QString &info, char *p);

    /**
     * @brief charAInfo 打印char[]　信息
     * @param info
     * @param a
     */
    void charAInfo(const QString &info, char a[], int length);
    void charAInfo(const QString &info, unsigned char a[], unsigned int length);

    void printEdid(unsigned int edid_len[], unsigned char edid_data[][0x80]);

protected:
    QMap<int, QMap<QString, QString> > m_MMInfo; // MapMapInfo
};

#endif // CMDHWINFO_H
