#include <ansi.h>
inherit ROOM;
 
int do_stuff(object ob);
 
void create()
{
        set("short", HIB "���ڵ꡿" NOR);
        set("long", HIB @LONG

                      ��                ��  

    �����൱���壬�����Ũ����ʱ�شӰ뿪�����ŷ�Ʈ����������
��ɢ��һЩ�ƾɵ���Ʒ�������������Ѿ��޷��ֱ������Щʲ�ᶫ��
�ˡ�ǽ�Ͽ���һЩ�ʲݵ����壬ǽ�ǵ�һյ���������Ƶط���һ����΢
���Ĺ�â��Ҳʼ����Щ�ֿ�������Ĺ��졣


LONG NOR);
	set("exits", ([
		"west" : "/d/death/road1",
	]) );

	set("objects", ([
		__DIR__"npc/ghost": 1,
	]) );

	 set("no_fight", 1);
	 set("no_sleep_room", 1);

        setup();
        replace_program(ROOM);
}
