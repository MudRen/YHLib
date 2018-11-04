#include <ansi.h>
inherit ROOM;

void create()
{
    	set("short", "��");
    	set("long", @LONG
������ﶣ�����ѵģ����������ϸһ����������������
�������ر������һ�߶������Ѿ���̵�ľͷ������һ��
���õĲ��ȴû�ж��١�
LONG);
        set("no_fight", 1);
        set("exits", ([
              	"west" : __DIR__"guofu_houyuan",
        ]));
        set("objects", ([
           	__DIR__"npc/guanjia1" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_pi", "pi");

}

int do_pi(string arg)
{

        object me, weapon;
        int costj, costq;

        me = this_player();

        if (me->query_temp("mark/������"))
            	return notify_fail(CYN "�񷿹������µ���ιιι������ȥ����������"
                                   "��������\n" NOR);

        if (me->query_temp("job_name") != "����") 
            	return notify_fail(CYN "�񷿹��¶���ȵ���û����Ϲ����ʲô��\n" NOR);

        if (me->is_busy())
		return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || weapon->query("id")!= "chai dao")
                return notify_fail(CYN "�񷿹��¼�Ц������׼����ʲô������ѽ����"
                                   "����\n" NOR);

        if (! arg || arg != "chai" )
		return notify_fail("��Ҫ��ʲô��\n");

        costj = random((int)me->query("con") / 3) + 1;
        costq = random((int)me->query("str") / 3) + 1;

        if ((int)me->query("jing") < costj
	   || (int)me->query("qi") < costq)
	{
                message_vision(HIR "\n$N" HIR "��һ�ᣬһ��С�Ĳ񵶾�Ȼ�����Լ�"
                               "�����ϡ�\n" NOR, me);
                me->unconcious();
                return 1;
        }
        
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       
        me->start_busy(1 + random(2));

        if (! (int)me->query_condition("wuguan_job")
           && (int)me->query_temp("mark/��") > 10 + random(10)
           && present("chaifang guanshi", environment(me)))
	{
                me->set_temp("mark/������", 1);
                message_vision(CYN "\n�񷿹��¶�$N" CYN "˵���ɵĲ������ˣ����"
                               "��ȥ��Ү�ɴ�ү����(" HIY "task ok" NOR + CYN ")��"
                               "��\n" NOR, me);
                return 1;
        }

        message_vision(HIW "$N" HIW "����һ��ľͷ��һ����ȥ����ľͷ��Ϊ��Ƭ��\n" NOR, me);
        me->add_temp("mark/��", 1);

        if ((int)me->query_skill("blade", 1) < 50
           && (int)me->query_skill("strike", 1) < 50
           && me->can_improve_skill("blade")
           && me->can_improve_skill("strike"))
	{  
                write(HIC "������������ж��ڵ������Ʒ���Щ��ᡣ\n" NOR);
                me->improve_skill("blade", (int)(me->query("int") / 6));
                me->improve_skill("strike", (int)(me->query("int") / 6));
        }
        return 1;
}
