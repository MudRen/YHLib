#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
���Ǵ�˵�����صİ���ɽ��ԶԶ��ȥ��������ɳ�ѻ��γ�
��ɽ�����һֻ���յļ�����һ��ɽ�����������ǰ��ɽ�ź�
һ��С·ͨ��һ��ɽ���ϵ�ɽׯ�������ǡ�������ŷ�������
լ��һ���˴���ȥ�������ˡ�
LONG);
        set("exits", ([ 
                "east" : __DIR__"shamo4",
                "westup" : __DIR__"btshan1",
        ]));
        set("objects", ([ 
                "/clone/beast/jinshe" : 3,
        ]));
        setup();
}
