// shedu-qiqiao.c

inherit SKILL;

int valid_enable(string usage) { return usage == "poison"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹����޷�ѧϰ����������\n");

        if ((int)me->query("max_neili") < 350)
                return notify_fail("�������̫�����޷�ѧϰ����������\n");

        if ((int)me->query_skill("poison", 1) < 30)
                return notify_fail("��Ļ���������򲻹����޷�ѧ����������\n");

        if ((int)me->query_skill("poison", 1) < (int)me->query_skill("dispel-poison", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷��������������������\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��������ֻ��ͨ��ѧϰ��ó�����\n");
}
