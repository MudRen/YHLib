#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���پ�");
        set("long", @long
������ǡ�������������̫��ľӴ������������Ϊ���ɣ�
��Ʒ�������������ǲ�ͬ�����������ɵ����������������
����ɫ������ͨ����ʥ�ã�����ͨ�����ҡ�
long);

	set("objects",([
                CLASS_D("kunlun") + "/hetaichong" : 1,
		__DIR__"npc/kl-dizi2" :   1,
		__DIR__"npc/kl-dizi4" :   1,
	]));

	set("exits", ([
                "east" : __DIR__"jiuqulang1",
                "west" : __DIR__"sleeproom",
	]));

        set("no_clean_up", 0);
        create_door("west", "С��", "east", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}
