#ifndef __ESP_WIFI_STATION_H__
#define __ESP_WIFI_STATION_H__

#include "esp_netif_cpp.h"

namespace esp
{
    namespace wifi
    {
        class station
        {
            default_wifi_iface interface;
            station();
            ~station();
        public:
            static station *get();
        };
    }
}

#endif