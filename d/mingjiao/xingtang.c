// Room: /d/mingjiao/xingtang.c

#include <ansi.h>
#include <login.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ż����գ��ܲ�͸�硣�������ڰ��磬Ҳ�����
ҹһ�㣬ÿ��������ǽ�ϣ���ȼ�ż�֦ţ�;����м���һ��
����裬�������ڡ��·�����һ����������ˮţƤ�ޡ�������
�弰���������̾ߡ�����վ�����ֱֳ��е�ִ�����ڡ�������
����������������㣬���㲻���������������
LONG );
	set("no_fight", "1");
	set("exits", ([
		"west" : __DIR__"square",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

