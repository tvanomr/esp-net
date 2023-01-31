idf_component_register(SRCS "esp_wifi_station.cpp" "esp_netif.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_netif esp_wifi esp-event-cpp)
