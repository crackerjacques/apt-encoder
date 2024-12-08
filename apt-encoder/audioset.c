#include "main.h"
#include "audioset.h"

int InitAudioDevice(char *device) {
    //Open Sound Device
    if(!strncmp(device,_APT_AUDIO_STDOUT,sizeof(_APT_AUDIO_STDOUT))) {
        return 1;  
    }
    
    AlsaAudioDevice *adev = malloc(sizeof(AlsaAudioDevice));
    int err;
    unsigned int actual_rate = WF_SAMPLE_RATE;

    // open PCM
    if ((err = snd_pcm_open(&adev->handle, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        fprintf(stderr, "Cannot open audio device %s (%s)\n", device, snd_strerror(err));
        return -1;
    }

    // init params
    snd_pcm_hw_params_alloca(&adev->params);
    snd_pcm_hw_params_any(adev->handle, adev->params);
    if ((err = snd_pcm_hw_params_set_access(adev->handle, adev->params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
        fprintf(stderr, "Cannot set interleaved mode (%s)\n", snd_strerror(err));
        return -1;
    }

    if ((err = snd_pcm_hw_params_set_format(adev->handle, adev->params, SND_PCM_FORMAT_S16_LE)) < 0) {
        fprintf(stderr, "Cannot set format (%s)\n", snd_strerror(err));
        return -1;
    }

    if ((err = snd_pcm_hw_params_set_channels(adev->handle, adev->params, WF_CHANNELS)) < 0) {
        fprintf(stderr, "Cannot set channels (%s)\n", snd_strerror(err));
        return -1;
    }

    if ((err = snd_pcm_hw_params_set_rate_near(adev->handle, adev->params, &actual_rate, 0)) < 0) {
        fprintf(stderr, "Cannot set rate (%s)\n", snd_strerror(err));
        return -1;
    }

    // apply
    if ((err = snd_pcm_hw_params(adev->handle, adev->params)) < 0) {
        fprintf(stderr, "Cannot set parameters (%s)\n", snd_strerror(err));
        return -1;
    }

    // buffering
    snd_pcm_prepare(adev->handle);

    return (intptr_t)adev;
}