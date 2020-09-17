#include "hd.h"
#include "CmdHwinfoMonitor.h"

#include <QDebug>

CmdHwinfoMonitor::CmdHwinfoMonitor()
    : CmdHwinfo()
{
    initInfo();
}

void CmdHwinfoMonitor::initInfo()
{
    hd_data_t *hd_data = nullptr;
    hd_data = static_cast<hd_data_t *>(calloc(1, sizeof * hd_data)) ;

    hd_t *hd, *hd0;
    hd0 = hd_list(hd_data, hw_monitor, 1, nullptr);

    for (hd = hd0; hd; hd = hd->next) {

        QMap<QString, QString> mapInfo;

        // 基本信息
        addMapInfo(mapInfo, "SysFS ID", hd->sysfs_id);
        addMapInfo(mapInfo, "SysFS BusID", hd->sysfs_bus_id);
        addMapInfo(mapInfo, "Device", hd->device.name);
        addMapInfo(mapInfo, "Hardware Class", hd->base_class.name);          // 设备类别
        addMapInfo(mapInfo, "Model", hd->model);                             // 设备型号
        addMapInfo(mapInfo, "Vendor", hd->vendor.name);                      // 设备厂商
        addMapInfo(mapInfo, "SubVendor", hd->sub_vendor.name);               // 子厂商
        addMapInfo(mapInfo, "Device", hd->device.name);                      // 设备名称
        addMapInfo(mapInfo, "SubDevice", hd->sub_device.name);               // 子设备
        addMapInfo(mapInfo, "Serial ID", hd->serial);                        // 设备序列号
        addMapInfo(mapInfo, "Driver", hd->driver);                           // 设备驱动
        addMapInfo(mapInfo, "Revision", hd->revision.name);                  // 版本
        addMapInfo(mapInfo, "Driver Modules", hd->driver_module);            // *******


        monitor_info_t *monitor = hd->detail->monitor.data;
        addMapInfo(mapInfo, "Size", QString("%1x%2 mm").arg(monitor->width_mm).arg(monitor->height_mm));
        addMapInfo(mapInfo, "Year of Manufacture", QString("%1").arg(monitor->manu_year));
        addMapInfo(mapInfo, "Week of Manufacture", QString("%1").arg(monitor->manu_week));

        hd_res_t *hdr0 = hd->res;
        QString resulotion = "";
        for (hd_res_t *hdr = hdr0; hdr ; hdr = hdr->next) {
            resulotion += QString("%1x%2@%3").arg(hdr->monitor.width).arg(hdr->monitor.height).arg(hdr->monitor.vfreq);
            resulotion += " ";
        }
        addMapInfo(mapInfo, "Resolution", resulotion);

        addMMInfo(int(hd->idx), mapInfo);
    }
}
