#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
���Ǽ���ķ��ӣ�ʮ�ֿ����������������ﺹ��䤱���
�����Ź��򣬵�����һЩ�����õĹ��ߡ�
LONG);
        set("no_fight", 1);
        set("can_dazuo", 1);
	set("exits", ([
	       "north" : __DIR__"guofu_wuchang3",
	       "east" : __DIR__"guofu_lang1",
        ]));
	setup();
}