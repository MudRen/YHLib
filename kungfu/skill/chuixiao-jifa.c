#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
        if (me->query("int") < 24 && me->query_int() < 35)
                return notify_fail("���������ԣ�������ȫ��ѧʲô���\n");

        return 1;
}

int play(object me, object ob, string arg)
{
        int lvl;
        int i;
        string m_name;

        if (! arg)
                return notify_fail("��Ҫ��ʲô���ӣ�\n");

        if (! (lvl = me->query_skill(arg, 1)))
                return notify_fail("�㲻�ᴵ�������ӡ�\n");

        if (! SKILL_D(arg)->valid_enable("chuixiao-jifa"))
                return notify_fail("��Ҳ�ܵ�������ô��\n");

        lvl += me->query_skill("chuixiao-jifa", 1) / 2;
        m_name = to_chinese(arg);

        if (me->is_busy())
                return notify_fail("��������æ���Ȼ���ٴ���ɡ�\n");

        if (lvl < 15)
        {
                message_vision(WHT "\n$N" WHT "����������һ��$n" WHT "�����ֻ"
                               "�Ƿ������´̶�����������\n" NOR, me, ob);
        } else
        if (lvl < 30)
        {
                message_vision(WHT "\n$N" WHT "����������һ��$n" WHT "��������"
                               "�����죬������һ����Ϳ��\n" NOR, me, ob);
        } else
        if (lvl < 60)
        {
                message_vision(WHT "\n$N" WHT "����$n" WHT "���ᴵ�˼���������"
                               "��������������̫������\n" NOR, me, ob);
        } else
        if (lvl < 90)
        {
                message_vision(HIW "\n$N" HIW "����$n" HIW "����һ��" + m_name +
                               HIW "������������������Ϊ����\n" NOR, me, ob);
        } else
        if (lvl < 150)
        {
                message_vision(HIW "\n$N" HIW "����$n" HIW "����һ��" + m_name +
                               HIW "����Ϊ���ˣ�������ʤ��\n" NOR, me, ob);
        } else
        if (lvl < 225)
        {
                message_vision(HIW "\n$N" HIW "����$n" HIW "����һ��" + m_name +
                               HIW "���������˸п���ǧ������Ͷ�롣\n" NOR, me,
                               ob);
        } else
        if (lvl < 300)
        {
                message_vision(HIC "\n$N" HIC "����$n" HIC "����һ��" + m_name +
                               HIC "������������ã��ƺ���һ������ֱ����Ƣ��\n"
                               NOR, me, ob);
        } else
        {
                message_vision(HIG "\n$N" HIG "����$n" HIG "����һ��" + m_name +
                               HIG "��������˼�����������侳��������ϲ�������"
                               "����У���֪��Ӱ��\n" NOR, me, ob);
        }
        me->start_busy(3 + random(3));

        SKILL_D(arg)->do_effect(me);
        return 1;
}
