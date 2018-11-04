#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", "����");
        set("long", @LONG
������һ��������������Բ�أ������ڳ��У�������ȥ
ֻ��������ǣ�˫������ˮ��������ˮ�ξ��峺�������˺�̦
�࣬ԭ��Բ�����ܶ�����䣬��ˮ��ӳ����ɫ����׵����ӳ
�ڱ��̵ĳ��У��Եø�������޽ྻ���ľ������ֻ���ر߳�
���˴��̵�����(rattan)���ص��ƺ��и���(hole)��

LONG);
        set("item_desc", ([
        	"rattan" : GRN "\n���������ذ��ߵĴ������٣������������ϰ�ȥ��\n" NOR,
        	"hole"   : WHT "\nǱ���ڳص׵�һ��С�������ƺ��������ȥ��\n" NOR,
        ]));
        setup();
}

void init()
{
        add_action("do_zuan", "zuan");
        add_action("do_climb", "climb");
}

int do_zuan(string arg)
{
        object me = this_player();

        if (! arg || arg != "hole")
		return notify_fail("��Ҫ��ʲô��\n");

        message("vision", HIC "ֻ��" + me->name() + HIC "���պ�����һ�����ӳ��ص�"
                          "�Ķ���ȥ��\n" NOR, environment(me), ({me}) );
        write(HIC "\n�㳯�ص׵Ķ���ȥ����֪ͻȻһ���������������㳶�������С�\n\n" NOR);

        me->move(__DIR__"lake3");
        message_vision(HIC "\n$N" HIC "���������ٲ������˳�����\n\n" NOR, me);

        return 1;
}

int do_climb(string arg)
{
    	object me = this_player();

    	if (! arg || arg != "rattan")
		return notify_fail("��Ҫ��ʲô��\n");

        message("vision", HIC "ֻ��" + me->name() + HIC "˳������������ȥ��\n" NOR,
                          environment(me), ({me}));
        me->move(__DIR__"feicui1");
        message_vision(HIC "\n$N" HIC "˳������ˮ���ܵ�����������\n\n" NOR, me);
        return 1;
}

