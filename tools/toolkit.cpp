#include "toolkit.h"

ToolKit::ToolKit()
{

}

void ToolKit::removeNewLines(QString *text)
{
  if(text)
  {
    *text=text->replace("\n","");
  }
}

QString ToolKit::URlsToString(QList<QUrl> *urls)
{
  QString text;
  int length=urls->length();
  if(urls && length>0)
  {
    QUrl url;
    for(int i=0;i<length;i++)
    {
      url=urls->at(i);
      text.append((i!=0?" | ":"")+url.toString()+"\n");

    }
    return text;
  }
  else
  {
    return text;
  }
}

FragmentFrame ToolKit::maxValue(const QList<FragmentFrame> &frames)
{
  if (frames.isEmpty()) return FragmentFrame();
  if(frames.count()<2) return frames.first();
  FragmentFrame max=frames.first();
  foreach (FragmentFrame frame, frames)
  {
    if(frame>max)
      max=frame;
  }
  return max;
}

void ToolKit::Sort(QList<FragmentFrame> *frames)
{
 // RTimer timer("ToolKit::Sort(QList<FragmentFrame> *frames)","sort list of fragment frames by size");
  quint64 size =frames->first().size;
  int times=0;
  int length=frames->length();
  while (true)
  {
    times=0;
    for(int i=0;i<length;i++)
    {
      if(frames->at(i).size>size)
      {
        frames->swap(i,i-1);
        times++;
        size=frames->at(i).size;
      }
    }
    if(times==0) break;
  }
}

