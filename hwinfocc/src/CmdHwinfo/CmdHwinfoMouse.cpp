#include "hd.h"
#include "CmdHwinfoMouse.h"

CmdHwinfoMouse::CmdHwinfoMouse()
    : CmdHwinfo()
{
    initInfo();
}

void CmdHwinfoMouse::initInfo()
{
    hd_data_t *hd_data = nullptr;
    hd_data = static_cast<hd_data_t *>(calloc(1, sizeof * hd_data)) ;

    hd_t *hd, *hd0;
    hd0 = hd_list(hd_data, hw_mouse, 1, nullptr);

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

        // hotplug
        QString hpStr = "";
        hd_hotplug_t hp = hd->hotplug;
        if (hp == hp_none) {
            hpStr = "";
        } else if (hp == hp_pcmcia) {
            hpStr = "PCMCIA";
        } else if (hp == hp_pci) {
            hpStr = "PCI";
        } else if (hp == hp_usb) {
            hpStr = "USB";
        } else if (hp == hp_cardbus) {
            hpStr = "CARDBUS";
        } else if (hp == hp_ieee1394) {
            hpStr = "IEEE 1394";
        }
        addMapInfo(mapInfo, "Hotplug", hpStr);

        //　Device File
        QString deviceFile;
        QString unix_dev_name = QString("%1").arg(hd->unix_dev_name);
        QString unix_dev_name2 = QString("%1").arg(hd->unix_dev_name2);
        if (!unix_dev_name.isNull()) {
            deviceFile = unix_dev_name;
        }
        if (!unix_dev_name2.isNull()) {
            deviceFile += " (" + unix_dev_name2 + ")";
        }
        addMapInfo(mapInfo, "Device File", deviceFile);

        // Device Files
        QString deviceFiles;
        str_list_t *slt0, *slt;
        slt0 = hd->unix_dev_names;
        for (slt = slt0; slt; slt = slt->next) {
            if (slt->str && *slt->str != '\0') {
                deviceFiles += QString::fromLocal8Bit(slt->str);
                deviceFile += ", ";
            }
        }
        deviceFiles.replace(QRegExp(", $"), "");
        addMapInfo(mapInfo, "Device Files", deviceFiles);

        addMMInfo(int(hd->idx), mapInfo);
    }
}
