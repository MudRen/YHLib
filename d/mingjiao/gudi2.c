#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "���عȵ�");
	set("long", @LONG
�㷭���Ƕ�����Ҳ�ƵĴ�ɽ�����������ǰ������һƬãã
�ƺ���ɽʯ��Ӳ�ޱȣ��㿴���ұ���һ�������(tree)�����ɽ��
�������ƺ��и�Сɽ��(dong)��
LONG );
	set("item_desc", ([
		"dong": WHT "һ����֪��ǳ��ɽ����\n" NOR,
		"tree": GRN "һ��ͦ�ν�˶��������\n" NOR,
	]));
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_climb", "climb");
}

int do_enter(string arg)
{
        object ob, me = this_player();
        int n = me->query("age");

        if (! arg || arg != "dong")
        {
                write("��Ҫ������ת��\n");
                return 1;
        }

        foreach (ob in deep_inventory(me))

        if (ob->is_character())
        {
                ob->move(environment(me));
                message_vision("\n$N��" + ob->name() + "�ӱ��Ϸ�������"
                               "�����ڵ��ϡ�\n\n" NOR, me);
        }

        message_vision(HIY "$N" HIY "������һ�������������Ŷ���������"
                       "ȥ��\n\n" NOR, me);

        if (n < 15)
        {
                message_vision(HIW "$N" HIW "�������ɣ�����ǰ��͸����"
                       "�������д�ϲ�������ʩ������ǰ�С�\n\n" NOR, me);
                me->move(__DIR__"gudi3");
        } else
        {
                message_vision(HIR "$N" HIR "�н��������߽�խ����Ҳ"
                       "�����¡�$N" HIR "��ʱ����˫�磬��ǰһ\n����"
                       "���ӹ�Ȼǰ���˳�����������ǰ�У�ȴ��������"
                       "����Ӳ��\nʯ��ѹ�����ؿڱ��ģ���Ȼ��Ҳ��������"
                       "��$N" HIR "��Ϣ���ܣ�ֻ�ú��ˣ�\n��������Ƕ��"
                       "��ʯ֮�У�ǰ�����ǲ��ܣ�����ȴҲ�Ѳ��ã���һ��"
                       "\n$N" HIR "�ŵû����ɢ���߾���ƽ֮����˫����"
                       "ʯ�����ƣ����Ӳ����˳�\n���;����ؿ�һ���ʹ"
                       "������������һ���߹ǡ�\n\n" NOR, me);
                me->receive_damage("qi", 150);
                me->receive_wound("qi", 100);
        }
        return 1;
}

int do_climb(string arg)
{
        object me = this_player();

        if (! arg || arg != "tree")
        {
                write("���������������\n");
                return 1;
        }
        message_vision(HIY "$N" HIY "����������ҡ����ҡ�������Ƿ��"
                       "ʵ��\n" NOR, me);
        message_vision(HIR "$N" HIR "��Ȼһ��ʧ�֣���������ֱ����ȥ"
                       "��\n", me);
        me->move(__DIR__"shanjiao");
        me->unconcious();
        return 1;
}
