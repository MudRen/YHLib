#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short", "���");
      set("long", @LONG
���ǵ���Ӻ����ǣ����깩Ӧ���ʲ��ϡ����⸮�Թ���
�����صأ���ʷ�ƾã���紾�ӡ�����ǻ����ǣ����Ǻ���
�տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿���
��·����������µ���ľ���϶���һ����ľ�� (paizi)�����
�жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
        set("outdoors", "kaifeng");
        set("no_fight", 1);
        set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
                "/clone/npc/mafu": 1,
        ]));
        set("exits",([
               "west" : __DIR__"daoxiang",
               "up"   : "/clone/shop/kaifeng_shop",
        ]));
        setup();
        replace_program(TRANS_ROOM);
}
