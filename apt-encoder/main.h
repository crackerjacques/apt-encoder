#ifndef NA_MAIN_H_   
#define NA_MAIN_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
// #include <linux/soundcard.h>
#include <alsa/asoundlib.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <getopt.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

#define _APT_FILE_NO_SET "σame"
#define _APT_AUDIO_DEVICE "default" 
#define _APT_AUDIO_STDOUT "io://stdout/"
#define _APT_AUDIO_STDIN  "io://stdin/"

typedef struct {
    char *device;         // Audio device
    char filename[1024];  // First image
    char secondfile[1024];// Second image
    uint8_t loop;         // Images loop
    uint8_t console;      // User console
    uint8_t datab;        // First image data channel B mode
    uint8_t isfile;       // Write to WAV file
    uint8_t chdev;        // Custom audio device
    uint8_t usestdin;     // Read image data from STDIN
    uint8_t usestdout;    // Write audio to STDOUT
    uint8_t multistdin;   // Multi mode on STDIN
} AptOptSettings;

typedef struct {
    int device;
    FILE *file;
} AptAudioSettings;

// 
extern FILE *logfile;
extern int AudioDevice;
extern uint8_t AptImageSet;

// prototype
void *SoundThread(void *vargp);
void Usage(char *p_name);
void CloseImageFile(FILE *reg, FILE *alt);
void ClearConsole();
void SignalHandler(int number);

#endif