// zuoyou-hubo.c ���һ���
// by Doing Lu

inherit SKILL;

#include <ansi.h>

#define LEVEL_PER_LAYER         30
#define MAX_LAYER               10

int valid_learn(object me)
{
        int layer;
        int lvl;

        lvl = me->query_skill("zuoyou-hubo", 1);
        if (me->query("gender") == "����" && lvl >= 50)
                return notify_fail("��ĬĬ������ͼ���Ķ�"
                                   "�ã�����ȴ��������ʧ�����ĸ����ꡣ\n");

        if (me->query("int") > 14)
                return notify_fail("������ķ����ң����Գ�"
                                   "�Ը�����ķ���֮����\n");

        if ((int)me->query_skill("force") < lvl * 3 / 2)
                return notify_fail("����ڹ���򲻹���������������ķ�������������\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("���һ���ֻ��ͨ��ѧϰ������ߡ�\n");
}

void skill_improved(object me)
{
        int lvl;
        int layer;

        lvl = me->query_skill("zuoyou-hubo", 1);
        layer = lvl / LEVEL_PER_LAYER;
        if (layer > MAX_LAYER) layer = MAX_LAYER;

        if (! layer)
        {
                tell_object(me, HIM "��Ǳ���������һ�"
                                "������������\n" NOR);
        } else
        if ((lvl % LEVEL_PER_LAYER) == 0)
        {
                tell_object(me, HIM "�������˵�" + chinese_number(layer) +
                            "�㾳������һ����İ��\n" NOR);
        } else
                tell_object(me, HIM "��Ե�" + chinese_number(layer) +
                            "�㾳������һ����ּ�����һ���˽⡣\n" NOR);
}
