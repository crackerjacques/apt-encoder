#ifndef NA_AUDIO_SETUP_H_   
#define NA_AUDIO_SETUP_H_

//Math
#define   WF_TPI   6.283185307
//Device Parameters
#define   WF_SAMPLE_RATE  24000 //24khz
#define   WF_CHANNELS    1     //mono
#define   WF_SAMPLEBITS  16    //16bits
#define   WF_BUFFER_DIV  2     //buffer divider

extern int16_t audio_buffer[WF_SAMPLE_RATE/WF_BUFFER_DIV];

// for ALSA handler
typedef struct {
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
} AlsaAudioDevice;

int InitAudioDevice(char *device);

#endif