#include "esp_netif_cpp.h"
#include "esp_netif.h"
#include "esp_wifi_types.h"
#include "esp_wifi_default.h"
#include "esp_event_cpp.h"

namespace esp
{
    default_wifi_iface::default_wifi_iface(esp_netif_t *interface) : iface(interface) {}
    default_wifi_iface::default_wifi_iface(default_wifi_iface &&other) : iface(other.iface)
    {
        other.iface = 0;
    }

    default_wifi_iface::~default_wifi_iface()
    {
        if (iface)
        {
            esp_netif_destroy_default_wifi(iface);
            iface = 0;
        }
    }

    esp_netif_t *default_wifi_iface::get()
    {
        return iface;
    }

    netif::netif()
    {
        esp_netif_init();
    }

    netif *netif::get()
    {
        static netif obj;
        return &obj;
    }

    default_wifi_iface netif::create_default_wifi_sta()
    {
        event::default_queue::get();
        return esp_netif_create_default_wifi_sta();
    }

    default_wifi_iface netif::create_default_wifi_ap()
    {
        event::default_queue::get();
        return esp_netif_create_default_wifi_ap();
    }
}