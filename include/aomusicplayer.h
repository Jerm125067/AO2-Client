#ifndef AOMUSICPLAYER_H
#define AOMUSICPLAYER_H
#include "file_functions.h"

#if defined(BASSAUDIO)
#include "bass.h"
#elif defined(QTAUDIO)
#include <QMediaPlayer>
#endif
#include "aoapplication.h"

#include <QWidget>
#include <string.h>
#include <QDebug>

#if defined(BASSAUDIO)
class AOMusicPlayer
{
public:
  AOMusicPlayer(QWidget *parent, AOApplication *p_ao_app);
  virtual ~AOMusicPlayer();
  void set_volume(int p_value, int channel=-1);
  void set_looping(bool toggle, int channel=0);

  const int m_channelmax = 4;

  //These have to be public for the stupid sync thing
//  QWORD loop_start = 0;
//  QWORD loop_end = 0;

public slots:
  void play(QString p_song, int channel=0, bool crossfade=false);
  void stop(int channel=0);

private:
  QWidget *m_parent;
  AOApplication *ao_app;

  bool m_looping = false;
  int m_volume = 0;

  // Channel 0 = music
  // Channel 1 = ambience
  // Channel 2 = extra
  // Channel 3 = extra
  HSTREAM m_stream_list[4];

//  HSYNC loop_sync;
};
#elif defined(QTAUDIO)
class AOMusicPlayer
{
public:
  AOMusicPlayer(QWidget *parent, AOApplication *p_ao_app);
  ~AOMusicPlayer();

  void play(QString p_song);
  void set_volume(int p_value);

private:
  QMediaPlayer m_player;
  QWidget *m_parent;
  AOApplication *ao_app;

  int m_volume = 0;
};
#else
class AOMusicPlayer
{
public:
  AOMusicPlayer(QWidget *parent, AOApplication *p_ao_app);
  ~AOMusicPlayer();

  void play(QString p_song);
  void set_volume(int p_value);

private:
  QWidget *m_parent;
  AOApplication *ao_app;
};
#endif

#endif // AOMUSICPLAYER_H
