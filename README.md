# ESPeaker32
Speaker bluetooth basato su ESP32, UDA1334, TDA7056B, MT3608, TC4056A ESPeaker32 è un progetto che replica uno speaker Bluetooth commerciale utilizzando un microcontrollore ESP32.
Il dispositivo si alimenta con una batteria agli ioni di litio, ricaricabile tramite micro-USB, e supporta la riproduzione di audio stereo tramite il protocollo A2DP.

## 🚀 Caratteristiche principali
- **Connettività**: Bluetooth con ESP32, supporto A2DP per audio stereo.  
- **Conversione Audio**: DAC UDA1334 per conversione digitale-analogica fino a 24 bit e 192 kHz.  
- **Amplificazione**: TDA7056B in configurazione BTL.  
- **Gestione Energia**: Alimentazione a batteria con BMS integrato e regolazione della tensione tramite convertitore DC-DC boost.  
- **Ottimizzazione del Rumore**: Filtraggio dell'alimentazione tramite filtri pi-greco del secondo ordine per ridurre il rumore ad alta frequenza sui rail di alimentazione.  

## 📁 Struttura del progetto
- 📜 **Tesina**: [ESPeaker32.pdf](https://github.com/rickb3n/ESPeaker32/blob/main/ESPeaker32.pdf)
- **🛠 Hardware**: Schema elettrico e PCB con analisi e filtraggio del rumore ad alta frequenza.
- **💾 Firmware**: [Libreria ESP32-A2DP](https://github.com/pschatzmann/ESP32-A2DP)
- **🌡 Analisi termica**: Monitoraggio delle temperature e confronto teorico.  

⭐ **Supporta il progetto**: Se questo repository ti è stato utile, lascia una **⭐ Star**! è gratis, pulsante in alto a destra.

🔍 **Tag**: `Tesina` `pdf` `DISIM` `UnivAQ` `ESP32` `Bluetooth` 

![1](https://github.com/rickb3n/ESPeaker32/blob/main/ESPeaker32_render_3d.jpg)
![2](https://github.com/rickb3n/ESPeaker32/blob/main/pcb_fabric.jpg)
![3](https://github.com/rickb3n/ESPeaker32/blob/main/pcb1.jpg)
![4](https://github.com/rickb3n/ESPeaker32/blob/main/ESPeaker32_finale.jpg)
