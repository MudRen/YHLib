// yaowang-shenxin.c ҩ������
// Edit By Vin On 26/2/2001
// ����ѧ��֪ʶ���ܣ��ﵽ������ʮ�������������Ǻ��ġ�

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "poison"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("poison", 1) < 150)
                return notify_fail("��Ļ�����������̫ǳ����"
                                   "�������µ�ҩ��������\n");

        if ((int)me->query_skill("dispel-poison", 1) < 150)
                return notify_fail("���������������̫ǳ����"
                                   "�������µ�ҩ��������\n");

        if ((int)me->query_skill("poison", 1) < (int)me->query_skill("yaowang-shenxin", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ���"
                                   "�����ո���µ�ҩ��������\n");

        if ((int)me->query_skill("dispel-poison", 1) < (int)me->query_skill("yaowang-shenxin", 1))
                return notify_fail("�����������ˮƽ���ޣ���"
                                   "�����ո���µ�ҩ��������\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("ҩ������ֻ��ͨ��ѧϰ��ó�����\n");
}
