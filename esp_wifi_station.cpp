#include <stdio.h>
#include "esp_wifi_station.h"
#include "esp_wifi_types.h"
#include "esp_wifi_default.h"
#include "esp_wifi.h"

namespace esp
{
    namespace wifi
    {
        station *station::get()
        {
            static station s;
            return &s;
        }
        station::station():interface(netif::get()->create_default_wifi_sta())
        {
            wifi_init_config_t cfg=WIFI_INIT_CONFIG_DEFAULT();
            /*if(cfg.nvs_enable)
            {
                auto err=nvs_flash_init();
                if()
            }*/
        }
        station::~station()
        {
        }
    }
}