#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ��̵��������ķ��䡣����������״��������ǰ
խ�����Ϊ���Σ����߰�Բ������ȴ��������״��ԭ������
ȫ��̶��е������ң�ǰխ���ƣ����ʹָ����Բ�н�������
���ڡ����������ż��������õ�ľ�ˣ����ż���ɳ�� (bag)��
ֽ��(paper)��
LONG);

        set("exits", ([
                "south" : __DIR__"houtang2",
                "north" : __DIR__"chanfang2",
        ]));
        set("item_desc", ([
                "paper" : YEL "\n����һ������ţƤֽ�ᣬ����������ǽ�ϡ�����"
                          "����������\n�Ʒ��ģ���������Ŵ�(da)�򿴡�\n" NOR,

                "bag"   : WHT "\n����һ����ɳ�����������ǳ���ʵ��������ר����"
                          "����ϰָ��\n�ģ�����Դ�(ci)�������Կ���\n" NOR,
        ]));
        set("for_family", "ȫ���");
        setup();
}

void init()
{
        add_action("do_strike", "da");
        add_action("do_finger", "ci");
}

int do_finger()
{
        object me;
        int qi_cost, c_skill;

        me = this_player();
        c_skill=me->query_skill("finger", 1);

        message_vision(HIY "$N" HIY "��ָ�ݺݵص���ɳ��������ָ��΢΢"
                       "��Щʹ��\n" NOR, me);
        qi_cost = 25;

        if (me->query("qi") > qi_cost)
        {
                if (me->can_improve_skill("finger") && c_skill < 100)
		{
                	me->improve_skill("finger", 1 + random(me->query("str")));
		        tell_object(me, HIC "��ԡ�����ָ���������µ�����\n" NOR);
		}
                me->receive_damage("qi", qi_cost);
        }
        return 1;
}

int do_strike()
{
        object me;
        int qi_cost, c_skill;

        me = this_player();
        c_skill = me->query_skill("strike", 1);

        message_vision(HIY "$N" HIY "����һ����������һ���ͻ���ţƤ"
                       "ֽ�ᡣ\n" NOR, me);
        qi_cost = 25;

        if (me->query("qi") > qi_cost)
        {
                if (me->can_improve_skill("strike") && c_skill < 100)
		{
	                me->improve_skill("strike", 1 + random(me->query("str")));
		        tell_object(me, HIC "��ԡ������Ʒ��������µ�����\n" NOR);
		}
                me->receive_damage("qi", qi_cost);
        } 
        return 1;
}
