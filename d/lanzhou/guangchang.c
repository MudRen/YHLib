#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����㳡");
        set("long", @LONG
���������ݳǵ�����㳡���������������������Ľ�ͨҪ
�������۵���������ԭ��Ҫ����������Ը��ص���������
�������㲻ʱ�����Կ���һЩ������������˴����նӴҴ���
����ȥ�������ǳ��е������ģ���һ���ܿ����Ĺ㳡��������
���ɳ�ܴ�����������ʯ�ĵ��澭������һ���ɳ��һЩ��
�ֺ��е��������������������һЩ����������������ݡ�
��������������ԭ����������һ����ǣ����ص����˶�����
��������Ĳ����������������У����С�����������˶���
���Լ�����Ʒ��һ�����־���
LONG);
        set("no_sleep_room",1);
        set("outdoors", "lanzhou");
        set("exits", ([
                "east"   : __DIR__"dongdajie1",
                "south"  : __DIR__"nandajie1",
                "west"   : __DIR__"xidajie1",
                "north"  : __DIR__"beidajie1",
        ]));
        set("objects", ([
                "/d/beijing/npc/maiyi2" : 1,
                "/d/beijing/npc/haoke1" : 2,
        	__DIR__"npc/liumangtou" : 1,    
        	__DIR__"npc/xiaofan" : 1,
                "/clone/npc/walker" : 1,
        ]));
        setup();
}

void init()
{
       add_action("do_zuan", "zuan");

}

int do_zuan(string arg)
{
       object me = this_player();

       if (me->is_busy() || me->is_fighting())
              return notify_fail("����æ������˵�ɣ�\n");
 
       if (me->query("family/family_name") != "����")
              return notify_fail("ʲô��\n");

       me->start_busy(1);

       write(HIC "����˲�ע�⣬���ĵ�����ص���\n" NOR);

       me->move("/d/mingjiao/didao2");

       return 1;
}