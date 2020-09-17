#include "hd.h"
#include "CmdHwinfoNetwork.h"

CmdHwinfoNetwork::CmdHwinfoNetwork()
    : CmdHwinfo()
{
    initInfo();
}

void CmdHwinfoNetwork::initInfo()
{
    hd_data_t *hd_data = nullptr;
    hd_data = static_cast<hd_data_t *>(calloc(1, sizeof * hd_data)) ;

    hd_t *hd, *hd0;
    hd0 = hd_list(hd_data, hw_network, 1, nullptr);

    for (hd = hd0; hd; hd = hd->next) {

        QMap<QString, QString> mapInfo;

        // 基本信息
        addMapInfo(mapInfo, "SysFS ID", hd->sysfs_id);
        addMapInfo(mapInfo, "SysFS BusID", hd->sysfs_bus_id);
        addMapInfo(mapInfo, "SysFS Device Link", hd->sysfs_device_link);
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

        //　Device File
        QString deviceFile;
        QString unix_dev_name = QString("%1").arg(hd->unix_dev_name);
        QString unix_dev_name2 = QString("%1").arg(hd->unix_dev_name2);
        if (!unix_dev_name.isNull()) {
            deviceFile = unix_dev_name;
        }
        if (!unix_dev_name2.isEmpty()) {
            deviceFile += " (" + unix_dev_name2 + ")";
        }
        addMapInfo(mapInfo, "Device File", deviceFile);


        hd_res_t *hrt0, *hrt;
        hrt0 = hd->res;
        for (hrt = hrt0; hrt; hrt = hrt->next) {
            if (res_hwaddr == hrt->any.type) {
                addMapInfo(mapInfo, "HW Address", hrt->hwaddr.addr);
            } else if (res_phwaddr == hrt->any.type) {
                addMapInfo(mapInfo, "Permanent HW Address", hrt->hwaddr.addr);
            } else if (res_link == hrt->any.type) {
                addMapInfo(mapInfo, "Link detected", hrt->link.state ? "yes" : "no");
            } else {
                // nothing to do ...
            }
        }

        addMMInfo(int(hd->idx), mapInfo);
    }
}
