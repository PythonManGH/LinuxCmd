#include "hd.h"
#include "CmdHwinfoGpu.h"
#include <QDebug>

CmdHwinfoGpu::CmdHwinfoGpu()
    : CmdHwinfo()
{
    initInfo();
}

void CmdHwinfoGpu::initInfo()
{
    hd_data_t *hd_data = nullptr;
    hd_data = static_cast<hd_data_t *>(calloc(1, sizeof * hd_data)) ;

    hd_t *hd, *hd0;
    hd0 = hd_list(hd_data, hw_display, 1, nullptr);

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

        // Config Status: cfg=new, avail=yes, need=no, active=unknown


        // 获取irq
        unsigned int irq = 0;
        hd_res_t *hrt0, *hrt;
        hrt0 = hd->res;
        for (hrt = hrt0; hrt; hrt = hrt->next) {
            if (hrt->irq.base != 0) {
                irq = hrt->irq.base;
            }
        }
        addMapInfo(mapInfo, "IRQ", QString::number(irq));



        addMMInfo(int(hd->idx), mapInfo);
    }
}
