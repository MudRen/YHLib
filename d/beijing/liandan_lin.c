#include <ansi.h> 
inherit ROOM;

int do_cai(string arg);

void init()
{
        add_action("do_cai", "cai");
}

int do_cai(string arg)
{
        object me = this_player();
        object ob;
        object ob1;

        if ((int)me->query_temp("caiyao") < 1)
                return notify_fail("�������˷�ʱ���ˣ����߰ɡ�\n");

        if (! arg || arg != "yao")
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy())
                return notify_fail("�����ң��ȱ𼱡�\n");
       
        if ((int)me->query("jing") < 40)
                return notify_fail("��̫���ˣ���Ϣ�°ɡ�\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("��̫���ˣ���Ϣ�°ɡ�\n");

        if ((int)me->query_temp("caiyao") == 2)
                return notify_fail("�������֣���ȥ���˰ɡ�\n");

        message_vision(HIC "\n$N" HIC "ſ�ڵ��ϣ��ɴ����۾��ڲݴ�����Ѱ"
                       "��ҩ�ݣ�����©����Ŀ�ꡣ\n" NOR, me); 
        me->start_call_out((: call_other, __FILE__, "cai", me :), 3);
        me->start_busy(4); 
        return 1;
}
 
void cai(object me)
{ 
        object ob;
        object ob1;
        int skill;

        if (! objectp(me) || ! living(me) || me->is_fighting())
                return;

        skill = (int)me->query_skill("bencao-changshi", 1);

        if (random(8) == 1)
        {
                tell_room(environment(me), HIR "\n�ݴ���һ��ζ���ͻȻ���һ��"
                                           "���ߡ�\n\n" NOR );
                ob = new("/clone/beast/dushe");
                ob->move(environment(me));
                ob->kill_ob(me);
        } else
        if (random(10) == 1 &&
           (string)me->query("family/family_name") != "�嶾��")
        {
                tell_room(environment(me), HIR "\nͻȻ�����Ӻ���һ��ζ�����"
                                           "��һ�������ɲ�����ӣ�����һ�Ѷ�"
                                           "������������\n" NOR + CYN "������"
                                           "��Ц�����ٺ٣������治�ɣ�����ײ"
                                           "���˱�ү����ү����Ҫ��Ҫ����\n\n" NOR);
                ob = new("/d/beijing/npc/liandan_langzhong");
                ob->move(environment(me));
                ob->kill_ob(me);
        } else
        if (random(skill) > 70)
        {
                ob1 = new("/d/beijing/npc/dan/caoyao");
                ob1->move(me, 1);
                me->receive_damage("jing", 10);
                me->receive_damage("qi", 10);
                me->set_temp("caiyao", 2);
                message_vision(HIW "$N" HIW "��ͨ�ٲ�֮����һ�۾ͷ�������һ��"
                               "�������ڲ�ͬ��С������ؽ������˳�����\n" NOR, me);
                me->improve_skill("bencao-changshi", me->query("int") / 4 + 1);
                tell_object(me, HIC "�ڲ�ҩ��������ġ����ݳ�ʶ������ˣ�\n" NOR);
        } else
        if (random(10) > 5)
        {
                me->receive_damage("jing", 10 + random(20));
                me->receive_damage("qi", 10 + random(20));   
                message_vision(CYN "һ�������󣬲ݴ����ƺ�û��$N" CYN 
                               "Ҫ�ҵĶ�����$N" CYN "ʧ����̾�˿�����\n"
                               NOR, me);
        } else
        { 
                ob1 = new("/d/beijing/npc/dan/caoyao");
                ob1->move(me, 1);
                me->receive_damage("jing", 10 + random(20));
                me->receive_damage("qi", 10 + random(20));
                me->set_temp("caiyao", 2);
                message_vision(HIG "$N" HIG "���˰��죬���ڷ�������һ���������"
                               "���Ĳ����в�ͬ��С������ؾ��˳�����\n" NOR, me);
                me->improve_skill("bencao-changshi", me->query("int") / 4 + 1);
                tell_object(me, HIC "�ڲ�ҩ��������ġ����ݳ�ʶ������ˣ�\n" NOR);
        }
}

