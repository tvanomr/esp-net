#ifndef __ESP_NETIF_H__
#define __ESP_NETIF_H__

#include "esp_netif.h"

namespace esp
{
    class netif;

    class default_wifi_iface
    {
        esp_netif_t *iface;
        default_wifi_iface() = default;
        default_wifi_iface(esp_netif_t *interface);
        friend class netif;

    public:
        default_wifi_iface(default_wifi_iface &&);
        default_wifi_iface(const default_wifi_iface &) = delete;
        esp_netif_t *get();
        ~default_wifi_iface();
    };

    class netif
    {
        netif();

    public:
        static netif *get();
        default_wifi_iface create_default_wifi_sta();
        default_wifi_iface create_default_wifi_ap();
    };
}

#endif