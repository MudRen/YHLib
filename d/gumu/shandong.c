
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����Сɽ�������һ��ǿ���ˮ���Ե����������γ�һ
��С�������⡣������ٽ�һ������Ļ����͵�Ҫ����ˮ��
�ˡ�����ɵ�С�ӱߡ������ҪǱˮ�ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("item_desc", ([
                "dong" : NOR + BLU"\nһ�����䡢�İ����ֲ���Сɽ����\n" NOR,
        ]));
        set("exits", ([
                "out"      : __DIR__"xiaohebian",
                "westdown" : __DIR__"mishi7",
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
	object obj;
	if (dir == "westdown" && me->query("family/family_name") != "��Ĺ��")
	{
		return notify_fail("��ô����ˮ����������ȥ��ɱѽ��\n");
	}
	if (dir == "westdown" && me->query("family/family_name")=="��Ĺ��")
	{
                message_sort(HIG "\n$N" HIG " ����һԾ������ˮ̯֮�У������"
                             "���������ι���������һ�̣�ȴץ�˿ա�ͻȻ$N" HIG 
                             "��ǰһ����һ�ɰ��������������$N" HIG "����һ��"
                             "���ڡ�\n"NOR, me);

		return 1;
	}
        return ::valid_leave(me, dir);
}
