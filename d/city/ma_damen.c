#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ׯ");
	set("long",
"����һ����Ϊ�����Ĵ�լԺ�����������ǰ����ͷ�ߴ��
ʯʨ����ס�˴������࣬���������������������Ϲ�����
��������д�š�" HIW "��ׯ" NOR "�����֡����Ԫ��ؤ�︱����������Ҵ�
������ʮ����������������˸������������������Զ�
");
        set("outdoors", "city");
	set("exits", ([
		"south" : __DIR__"xidajie2",
		"north" : __DIR__"ma_dayuan",
	]));
	set("objects", ([
		"/d/gaibang/npc/1dai" : 1 + random(2),
		"/d/gaibang/npc/2dai" : 1 + random(2),
	]));	
	setup();
	replace_program(ROOM);
}
