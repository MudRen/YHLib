#include <room.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�������ݳǵı����ţ���Ϊ����ʧ�𣬵����ڳ�ǽ���Ǻ�
�����ģ���˰�ֽ���ֵĹٸ���ʾ (gaoshi) ���Ե��ر����ۡ�
������һƬ��ɽ���룬һ������С����ɽ�����Ѷ��ϡ�
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"beidajie2",
		"north" : "/d/shaolin/yidao",
		"west"  : "/d/huanghe/caodi1",
	]));
        set("objects", ([
                "/kungfu/class/yunlong/ma" : 1,
                "/d/beijing/npc/ducha" : 1,
                __DIR__"npc/bing" : 4,
                "/clone/npc/walker" : 1,
        ]));
	set("outdoors", "city");
	setup();
        replace_program(ROOM);
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}

