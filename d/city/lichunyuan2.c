#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����Ժ��¥");
        set("long", @LONG
��վ������Ժ��¥���������������첻�����ơ����õľ�
�Ծ��µĴ��ϵ��£�ͻȻ�������Ī�����ջ�ͳ嶯��������
�������ǧ�������ڵ��ֶ����㣬���뵽���ǿ��ܾ������ս�
���е��۸��ڶ�����ʱ��Ϊ���ġ�
LONG);
        set("exits", ([
            	"down" : __DIR__"lichunyuan",
        ]));
        set("objects", ([
            	__DIR__"npc/guigong" : 1,
        ]));
	set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg", 1);
        set("piao_room", 1);
        setup();
}

int valid_leave(object me, string dir)
{
    	me = this_player();

    	if (me->query_condition("prostitute"))
      		return notify_fail(CYN "�깫һ�ѱ�ס�㣬�ȵ��������������ӣ�\n" NOR);

	return 1;
}
