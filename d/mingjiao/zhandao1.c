//zhandao1.c
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ջ��");
	set("long", @LONG
������ͨ�����̵�ջ��������ï�����ƣ�������ա�
LONG );
	set("exits", ([
		"northup"   : __DIR__"zhandao2",
		"southdown" : __DIR__"lhqhoumen",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}

void init()
{
	object me = this_player();
	
	if (interactive(me) && random((int)me->query_skill("dodge")) <= 10) 
	{
		me->receive_damage("qi", 50);
		me->receive_wound("qi",  50);
message_vision(HIR"$Nһ��С�Ľ���̤�˸��գ�... ��...��\n"NOR, me);
		me->move(__DIR__"lhqpaifang");
		tell_object(me, HIR "���ջ���������������� !�������ˡ�\n" NOR);
message("vision", HIR"ֻ��" + me->query("name") + "��ջ������ͨһ���������������ڵ��ϰ�������������\n"NOR, environment(me), me);
	}
}

