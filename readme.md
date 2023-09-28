# Recruiting SW Telemetry Project1

## Introduzione
Il progetto consiste nella realizzazione di una applicazione utilizzando [ImGui](https://github.com/ocornut/imgui) per la gestione di dati di telemetria della vettura. Per maggiori informazioni è possibile consultare l'assignment del progetto nel file [projectInstruction](/projectInstruction.md).

Le istruzioni fornite richiedevano solamente di definire una funzionalità di login e l'applicazione in generale, lasciando libera la scelta delle altre funzionalità che potevano essere implementate. Nel file [TelemetryProjectPlan.pdf](./Deliverable/TelemetryProjectPlan.pdf) sono presenti delle informazioni aggiuntive sulle funzionalità presenti nell'applicazione rapportate anche ai permessi dell'utente.

Tutti i valori dei dati visualizzati sono stati generati randomizzati una volta appena avviata l'applicazione.

Sono stati gestiti tre tipologie di utenti:
- Basic user
- Maintainer
- Admin

Tramite la funzione login è possibile passare da un utente all'altro inserendo le credenziali all'interno degli appositi campi di testo. 

*Per accedere come un Maintainer è necessario inserire:*
- username: *maintainer*
- password: *maintainer*

*Per accedere come un Admin è necessario inserire:*
- username: *admin*
- password: *admin*

Sono stati creati inoltre degli ulteriori utenti (Maintainer, Admin) accessibili tramite le credenziali:

**Maintainer**
- username: *topolino*
- password: *paperino*
---
**Admin**
- username: *pluto*
- password: *paperino*

In base a se un utente è un Basic user, un Maintainer o un Admin avrà uno stile di visualizzazione dell'applicazione diverso e delle funzionalità diverse (vedi [TelemetryProjectPlan.pdf](./Deliverable/TelemetryProjectPlan.pdf))

Per l'inserimento delle immagini nell'applicazione è stata utilizzata la libreria [stb_image.h](https://github.com/nothings/stb). 

***ATTENZIONE**: per caricare le immagini all'interno dell'applicazione è necessario che queste siano presenti nella cartella [data](./data/).*
## Prerequisiti

- `git` e account [GitHub](https://github.com)
- C/C++ toolchain, con CMake
- OpenGL
- GLEW
- GLFW3

Per Debian / Ubuntu puoi utilizzare:

```bash
sudo apt install build-essential cmake libglfw3-dev libglew-dev mesa-utils
```

## Setup
- scaricare ed estrarre i [file del progetto](
https://github.com/nicolomarconi02/recruiting-sw-Telemetry-project1/archive/refs/heads/main.zip)

## Building
- per eseguire l'applicazione è possibile utilizzare il file [run.sh](run.sh) 
    - se [run.sh](run.sh) non è eseguibile è necessario utilizzare:
```bash
chmod +x run.sh
./run.sh
```
- è possibile inoltre utilizzare il file [build.sh](/build.sh) per compilare il programma senza eseguirlo automaticamente 
    - se [build.sh](/build.sh) non è eseguibile è necessario utilizzare:

```bash
chmod +x build.sh
./build.sh
```
- In questo caso per eseguire l'applicazione è necessario eseguire questi ulteriori comandi:
```bash
cd bin
./project_1
```