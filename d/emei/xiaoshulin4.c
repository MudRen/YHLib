#include <ansi.h>
inherit ROOM;

void create()
{
      	set("short","С����");
      	set("long",@LONG
���Ƕ���ɽ�𶥻��������һƬС���֡������Ƕ�����Ů
�����ǵ��޹��Ĵ��������º������һ���ˡ�
LONG);
      	set("objects", ([
           	__DIR__"npc/songqingshu" : 1,
      	]));
      	set("outdoors", "emei");
      	set("exits",([
          	"northwest" : __DIR__"xiaoshulin3", 
          	"north"     : __DIR__"qinggong", 
      	]));
      	setup();
}

int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();

        if (dir == "north")
        {
                if ((string)me->query("family/family_name") != "������"
                & objectp(present("song qingshu", environment(me))))
                        return notify_fail(CYN "������һ����ȣ�����ʲô"
                                           "�ˣ��������ͷ���Ե����ʲô��\n" NOR);
        }
        return ::valid_leave(me, dir);
}
