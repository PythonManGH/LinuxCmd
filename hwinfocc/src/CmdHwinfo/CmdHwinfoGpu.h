#ifndef CMDHWINFOGPU_H
#define CMDHWINFOGPU_H

#include "CmdHwinfo.h"

class CmdHwinfoGpu : public CmdHwinfo
{
public:
    CmdHwinfoGpu();
protected:
    /**
     * @brief initInfo 初始化信息
     */
    void initInfo() override;
};

#endif // CMDHWINFOGPU_H
