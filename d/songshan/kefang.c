#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ�ɿͷ�");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ɽ�ɹ�ǰ��������ο���ס��
�������ʮ�ּ�ª�� ��ǽ����ʮ����Сľ���� ��Ȼ��ª�˵�
�����ܱ��ڻ�ɽ��¶��ǿ�ö��ˡ�
LONG);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([
	       "west"  :  __DIR__"changlang",
	]));
	setup();
}


