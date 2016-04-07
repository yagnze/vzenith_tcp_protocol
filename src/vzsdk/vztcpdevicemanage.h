/*
 * vzsdk
 * Copyright 2013 - 2016, Vzenith Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef SRC_HSHA_TCPDEVICEMANAGE_H_
#define SRC_HSHA_TCPDEVICEMANAGE_H_

#include <map>
#include "vzsdk\vzsdkservice.h"

using namespace vzsdk;

namespace vzsdk {
typedef std::map<int, VzsdkServicesPtr> VzsdkServicesMap;

//����豸����
class VzTcpDeviceManage {
  public:
    VzTcpDeviceManage();
    ~VzTcpDeviceManage();
    int CreateNewService(const std::string& _ip
                         , const int _port
                         , const std::string& _user_name
                         , const std::string& _user_pwd);

    const VzsdkServicesPtr GetService(int _session_id);
    const VzsdkServicesPtr GetService(const std::string& _ip);

    bool ExistService(int _session_id);
    bool CloseService(int _session_id);

  protected:
    bool RemoveService(int _session_id);

  private:
    VzsdkServicesMap vzsdk_service_map;
};
}

#endif

