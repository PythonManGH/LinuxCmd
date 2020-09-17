#ifndef CMDHWINFONETWORK_H
#define CMDHWINFONETWORK_H

#include "CmdHwinfo.h"

class CmdHwinfoNetwork : public CmdHwinfo
{
public:
    CmdHwinfoNetwork();

protected:
    /**
     * @brief initInfo 初始化信息
     */
    void initInfo() override;
};

#endif // CMDHWINFONETWORK_H
