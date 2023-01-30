#include <stdio.h>
#include "esp-wifi-station.h"
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
        station::station()
        {
            esp_netif_init();
            interface = esp_netif_create_default_wifi_sta();
        }
        station::~station()
        {
            esp_netif_destroy_default_wifi(interface);
        }
    }
}