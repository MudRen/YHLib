#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
����¶�����䳡���ö�����������������ţ������ڳ���
û���˻�ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ���
LONG);
        set("no_fight", 1);
        set("can_dazuo", 1);
	set("exits", ([
	       "north" : __DIR__"guofu_wuchang4",
	       "west" : __DIR__"guofu_lang2",
        ]));
	setup();
}
