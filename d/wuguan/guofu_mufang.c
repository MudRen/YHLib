#include <ansi.h>
inherit ROOM;

void create()
{
    	set("short", "ľ��");
    	set("long", @LONG
һ���ݣ���ͱ��޴�ĺ�������ס�ˣ�������˺ö೤��
ľͷ��׼��Ҫ������õģ���������ȥ��ǰ�ȵðѳ�ľͷ��
�̳�һ�ؽصġ��㿴���������ڷ����ľ��š�
LONG);
        set("no_fight", 1);
        set("exits", ([
             	"west" : __DIR__"guofu_houyuan2",
        ]) );
        set("objects", ([
           	__DIR__"npc/guanjia2" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_pi", "ju");
}

int do_pi(string arg)
{ 
        object me, weapon;
        int costj, costq;

        me = this_player();

        if (me->query_temp("mark/������"))
            	return notify_fail(CYN "ľ���������µ���ιιι������ȥ����������"
                                   "��������\n" NOR);

        if (me->query_temp("job_name") != "��ľͷ") 
            	return notify_fail(CYN "ľ�����¶���ȵ���û����Ϲ����ʲô��\n" NOR);

        if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

        if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");

        if (! objectp(weapon = me->query_temp("weapon"))
	   || weapon->query("id") != "ju zi")
                return notify_fail(CYN "ľ�����¼�Ц����������ʲô����ľͷ������"
                                   "����\n" NOR);

        if (! arg || arg != "mutou")
		return notify_fail("��Ҫ��ʲô��\n");

        costj = random((int)me->query("con") / 3) + 1;
        costq = random((int)me->query("str") / 3) + 1;

        if ((int)me->query("jing") < costj
	   || (int)me->query("qi") < costq)
	{
        	message_vision(HIR "\nͻȻ��ľͷ��Ȼ���ˣ�����İ��ľͷ������$N"
                               HIR "ͷ�ϡ�\n", me);
                me->unconcious();
                return 1;
        }

        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);
        me->start_busy(1 + random(2));

        if (! (int)me->query_condition("wuguan_job")
           && (int)me->query_temp("mark/��") > 10 + random(10)
           && present("mufang guanshi", environment(me)))
	{
                me->set_temp("mark/������", 1);
                message_vision(CYN "\nľ�����¶�$N" CYN "˵���ɵĲ������ˣ����"
                               "��ȥ��Ү�ɴ�ү����(" HIY "task ok" NOR + CYN ")��"
                               "��\n" NOR, me);
                return 1;
        }

        message_vision(HIM "$N" HIM "����һ��ľͷ����������������\n" NOR, me);
        me->add_temp("mark/��", 1);

        if ((int)me->query_skill("hand", 1) < 50
           && (int)me->query_skill("sword", 1) < 50
           && me->can_improve_skill("hand")
           && me->can_improve_skill("sword"))
	{
                write(HIC "���ھ�ľͷ�������ж��ַ���������Щ��ᡣ\n" NOR);
                me->improve_skill("hand", (int)(me->query("int") / 6));
                me->improve_skill("sword", (int)(me->query("int") / 6));
        }
        return 1;
}
