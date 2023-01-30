#ifndef __ESP_WIFI_H__
#define __ESP_WIFI_H__

#include "esp_netif.h"

namespace esp
{
    namespace wifi
    {
        class station
        {
            esp_netif_t* interface;
            station();
            ~station();
        public:
            static station *get();
        };
    }
}

#endif