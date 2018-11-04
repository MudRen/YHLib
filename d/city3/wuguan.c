#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ţ���");
	set("long", @LONG
��ţ����ڽ����к����������ܶ������С���Ǵ�������
����������Ȼ�����ڽ������ѳ������������ʦ�����Ҳ��
���ˣ�ȴ�����ǵ�����ҵʦ������Ҳ����������ʦ���ǣ����
���ﳤ�õõ��ڰ����������أ������ַ�����������ݴ�����
��������ڴ����ڡ�
LONG);
	set("objects", ([
		__DIR__"npc/mawude" : 1,
		__DIR__"npc/zhangfang" : 1,
	]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
	set("exits", ([
		"southwest" : __DIR__"northroad3",
		"east"      : __DIR__"wuguanchen",
		"south"     : __DIR__"wuguanlong",
		"west"      : __DIR__"wuguanxiao",
		"north"     : __DIR__"wuguanliu",
		"up"        : __DIR__"practice",
                "down"      : __DIR__"wuxiuxi",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if (! me->query_temp("marks/jinniu_paied")
           && (dir == "up" || dir == "down"))
	        return notify_fail(CYN "�����Ц��: ���Ǳ��ݵ��Ӳ��ܽ�ȥ�ġ�\n" NOR);

	return ::valid_leave(me, dir);
}
