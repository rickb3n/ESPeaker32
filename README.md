# ESPeaker32
Speaker bluetooth basato su ESP32, UDA1334, TDA7056B, MT3608, TC4056A

ESPeaker32 è un progetto che replica uno speaker Bluetooth commerciale utilizzando un microcontrollore ESP32.  
Il dispositivo si alimenta con una batteria agli ioni di litio, ricaricabile tramite micro-USB, e supporta la riproduzione di audio stereo tramite il protocollo A2DP.

## 🚀 Caratteristiche principali
- **Connettività**: Bluetooth con ESP32, supporto A2DP per audio stereo.  
- **Conversione Audio**: DAC UDA1334 per conversione digitale-analogica fino a 24 bit e 192 kHz.  
- **Amplificazione**: TDA7056B in configurazione BTL.  
- **Gestione Energia**: Alimentazione a batteria con BMS integrato e regolazione della tensione tramite convertitore DC-DC boost.  
- **Ottimizzazione del Rumore**: Filtraggio dell'alimentazione tramite filtri pi-greco del secondo ordine per ridurre il rumore ad alta frequenza sui rail di alimentazione.  

## 📁 Struttura del progetto
- **🛠 Hardware**: Schema elettrico e PCB con gestione energetica e amplificazione ottimizzata.  
- **💾 Firmware**: Implementazione del protocollo I2S per la comunicazione tra ESP32 e DAC.  
- **🌡 Analisi termica**: Monitoraggio delle temperature e confronto teorico.  
