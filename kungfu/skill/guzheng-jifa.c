#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
        if (me->query("int") < 24 && me->query_int() < 35)
                return notify_fail("�����ǵ����ԣ�������ȫ��ѧʲô���ݣ�\n");

        return 1;
}

int play(object me, object ob, string arg)
{
        int lvl;
        int i;
        string m_name;

        if (! arg)
                return notify_fail("��Ҫ����ʲô���ӣ�\n");

        if (! (lvl = me->query_skill(arg, 1)))
                return notify_fail("�㲻�������������ӡ�\n");

        if (! SKILL_D(arg)->valid_enable("guzheng-jifa"))
                return notify_fail("�ⲻ���������࣡\n");

        lvl += me->query_skill("guzheng-jifa", 1) / 2;
        m_name = to_chinese(arg);

        if (me->is_busy())
                return notify_fail("��������æ���Ȼ��������ɡ�\n");

        if (lvl < 15)
        {
                message_vision(WHT "\n$N" WHT "���Ҳ��˲�$n" WHT "�����ֻ�Ƿ�"
                               "���˼��´̶���������\n" NOR, me, ob);
        } else
        if (lvl < 30)
        {
                message_vision(WHT "\n$N" WHT "������һ��$n" WHT "������������"
                               "�죬������һ����Ϳ��\n" NOR, me, ob);
        } else
        if (lvl < 60)
        {
                message_vision(WHT "\n$N" WHT "�ں�$n" WHT "���ᵯ�˼��£�����"
                               "������࣬��̫������\n" NOR, me, ob);
        } else
        if (lvl < 90)
        {
                message_vision(HIW "\n$N" HIW "�ں�$n" HIW "����һ��" + m_name +
                               HIW "������������������Ϊ����\n" NOR, me, ob);
        } else
        if (lvl < 150)
        {
                message_vision(HIW "\n$N" HIW "�ں�$n" HIW "����һ��" + m_name +
                               HIW "����Ϊ���ˣ�������ʤ��\n" NOR, me, ob);
        } else
        if (lvl < 225)
        {
                message_vision(HIW "\n$N" HIW "�ں�$n" HIW "����һ��" + m_name +
                               HIW "���������˸п���ǧ������Ͷ�롣\n" NOR, me,
                               ob);
        } else
        if (lvl < 300)
        {
                message_vision(HIC "\n$N" HIC "�ں�$n" HIC "����һ��" + m_name +
                               HIC "����������Ϫˮ��������Ȼ��Ȥ��������ǧ��\n"
                               NOR, me, ob);
        } else
        {
                message_vision(HIG "\n$N" HIG "�ں�$n" HIG "����һ��" + m_name +
                               HIG "��������Ϫ������ͷ�������޾�����ȴ������"
                               "���ɾ������������\n" NOR, me, ob);
        }
        me->start_busy(3 + random(3));

        SKILL_D(arg)->do_effect(me);
        return 1;
}
